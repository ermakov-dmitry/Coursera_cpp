#include "ini.h"

namespace Ini {
    Document Load(istream& input) {
        Document result;
        string line;
        string section_name;
        while (!input.eof()) {
            getline(input, line);
            if (line.front() == '[') {
                section_name = {line.begin() + 1, line.end() - 1};
                result.AddSection(section_name);
            } else if (!line.empty()) {
                line.erase(remove_if(line.begin(), line.end(), [](const char& s){return isspace(s);}), line.end());
                size_t equal_idx = line.find('=');
                auto key = line.substr(0, equal_idx);
                auto value = line.substr(equal_idx + 1);
                result.AddSection(section_name).insert({key, value});
            }
        }
        return result;
    }

    Section &Document::AddSection(const string& name) {
        return sections[name];
    }

    const Section &Document::GetSection(const string& name) const {
        return sections.at(name);
    }

    size_t Document::SectionCount() const {
        return sections.size();
    }
}
