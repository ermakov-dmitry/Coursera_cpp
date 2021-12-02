#include "Common.h"
#include <vector>
#include <map>
#include <unordered_map>
#include <mutex>

using namespace std;

class LruCache : public ICache {
public:
    LruCache(shared_ptr<IBooksUnpacker> books_unpacker, const Settings& settings)
    : unpacker(move(books_unpacker)), settings_(settings) {}

    BookPtr GetBook(const string& book_name) override {
        lock_guard g(mtx);
        auto it = cache.find(book_name);
        if (it != cache.end()) {
            auto name_pr = priority.find(it->second.second);
            auto node = priority.extract(name_pr);
            node.key() = it->second.second = max_rank++;
            priority.insert(move(node));
            return it->second.first;
        }
        shared_ptr<const IBook> book = unpacker->UnpackBook(book_name);
        cache[book->GetName()] = make_pair(book, max_rank);  // add to cache
        priority[max_rank++] = book->GetName();  // add to pr
        cur_memory += book->GetContent().size();
        CheckCache();
        return book;
    }

private:
    using Data = pair<BookPtr, size_t>;
    shared_ptr<IBooksUnpacker> unpacker;
    Settings settings_;  // settings_.max_memory
    unordered_map<string, Data> cache;  // name : *content_
    map<size_t, string> priority;
    size_t cur_memory = 0;
    size_t max_rank = 0;
    mutex mtx;

    void CheckCache() {
        while (cur_memory > settings_.max_memory) {
            auto clear_it = priority.begin();
            cur_memory -= cache.at(clear_it->second).first->GetContent().size();
            cache.erase(clear_it->second);
            priority.erase(clear_it);
        }
    }
};


unique_ptr<ICache> MakeCache(
        shared_ptr<IBooksUnpacker> books_unpacker,
        const ICache::Settings& settings
) {
    // реализуйте функцию
    return make_unique<LruCache>(move(books_unpacker), settings);
}