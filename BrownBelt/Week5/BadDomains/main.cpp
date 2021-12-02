#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

using namespace std;


bool IsSubdomain(string_view domain, string_view subdomain) {
    size_t i = 0;
    size_t j = 0;
    while (i < domain.size() && j < subdomain.size()) {
        if (subdomain[j++] != domain[i++]) {
            return false;
        }
    }
    auto condition = i == domain.size() || domain[i] == '.';
    return condition;
}


vector<string> ReadDomains(istream& stream) {
    size_t count;
    stream >> count;
    string domain;
    vector<string> domains;
    getline(stream, domain);  // pass empty string
    for (size_t i = 0; i < count; ++i) {
        getline(stream, domain);
        domains.push_back(domain);
    }
    return domains;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> banned_domains = ReadDomains(cin);
    vector<string> domains_to_check = ReadDomains(cin);

    for (string& domain : banned_domains) {
        reverse(begin(domain), end(domain));
    }
    sort(begin(banned_domains), end(banned_domains));

    size_t insert_pos = 0;
    for (string& domain : banned_domains) {
        if (insert_pos == 0 || !IsSubdomain(domain, banned_domains[insert_pos - 1])) {
            swap(banned_domains[insert_pos++], domain);
        }
    }
    banned_domains.resize(insert_pos);

    for (string& domain : domains_to_check) {
        reverse(domain.begin(), domain.end());
        if (const auto it = upper_bound(begin(banned_domains), end(banned_domains), domain);
                it != begin(banned_domains) && IsSubdomain(domain, *prev(it))) {
            cout << "Bad\n";
        } else {
            cout << "Good\n";
        }
    }
    return 0;
}