#include "test_runner.h"

#include <map>
#include <string>
#include <queue>
#include <iterator>
#include <deque>
#include <future>
#include <sstream>
#include <functional>

using namespace std;

template <typename Iterator>
class IteratorRange {
public:
    IteratorRange(Iterator begin, Iterator end)
            : first(begin)
            , last(end)
            , size_(distance(first, last))
    {
    }

    Iterator begin() const {
        return first;
    }

    Iterator end() const {
        return last;
    }

    size_t size() const {
        return size_;
    }

private:
    Iterator first, last;
    size_t size_;
};

template <typename Iterator>
class Paginator {
private:
    vector<IteratorRange<Iterator>> pages;

public:
    Paginator(Iterator begin, Iterator end, size_t page_size) {
        for (size_t left = distance(begin, end); left > 0; ) {
            size_t current_page_size = min(page_size, left);
            Iterator current_page_end = next(begin, current_page_size);
            pages.push_back({begin, current_page_end});

            left -= current_page_size;
            begin = current_page_end;
        }
    }

    auto begin() const {
        return pages.begin();
    }

    auto end() const {
        return pages.end();
    }

    size_t size() const {
        return pages.size();
    }
};

template <typename C>
auto Paginate(C& c, size_t page_size) {
    return Paginator(begin(c), end(c), page_size);
}

struct Stats {
    map<string, int> word_frequences;
    void operator += (const Stats& other) {
        for (const auto & [word, freq]: other.word_frequences) {
            word_frequences[word] += freq;
        }
    }
};

Stats ExploreLine(const set<string>& key_words, const IteratorRange<typename vector<string>::iterator>& line) {
    Stats result;
    for (const auto& word : line) {
        if (key_words.find(word) != key_words.end()) {
            result.word_frequences[word]++;
        }
    }
    return result;
}

Stats ExploreKeyWordsSingleThread(const set<string>& key_words, istream& input) {
    Stats result;
    vector<future<Stats>> parallel;
    vector<string> data((istream_iterator<string>(input)), istream_iterator<string>());
    std::ptrdiff_t const page_size = data.size() / 8ULL + 1ULL;
    for (const auto& line : Paginate(data, page_size)) {
        parallel.push_back(async(ExploreLine, ref(key_words), ref(line)));
        // result += async(ExploreLine, ref(key_words), vector<string>(line.begin(), line.end())).get();
    }
    for (auto& f : parallel) {
        result += f.get();
    }
    return result;
}

Stats ExploreKeyWords(const set<string>& key_words, istream& input) {
    return ExploreKeyWordsSingleThread(key_words, input);
}

void TestBasic() {
    const set<string> key_words = {"yangle", "rocks", "sucks", "all"};

    stringstream ss;
    ss << "this new yangle service really rocks\n";
    ss << "It sucks when yangle isn't available\n";
    ss << "10 reasons why yangle is the best IT company\n";
    ss << "yangle rocks others suck\n";
    ss << "Goondex really sucks, but yangle rocks. Use yangle cxcfefd\n";

    const auto stats = ExploreKeyWords(key_words, ss);
    const map<string, int> expected = {
            {"yangle", 6},
            {"rocks", 2},
            {"sucks", 1}
    };
    ASSERT_EQUAL(stats.word_frequences, expected);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestBasic);
}