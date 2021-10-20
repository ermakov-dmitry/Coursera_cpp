#pragma once
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

namespace Ini {
    using Section = unordered_map<string, string>;

    class Document {
    public:
        Section& AddSection(const string& name);
        const Section& GetSection(const string& name) const;
        size_t SectionCount() const;

    private:
        unordered_map<string, Section> sections;
    };

    Document Load(istream& input);
}
