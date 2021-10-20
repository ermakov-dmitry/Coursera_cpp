#include "stats.h"

void Stats::AddMethod(string_view method) {
    if (methods.find(method) != methods.end()) {
        methods[method]++;
    } else {
        methods["UNKNOWN"]++;
    }
}

void Stats::AddUri(string_view uri) {
    if (uris.find(uri) != uris.end()) {
        uris[uri]++;
    } else {
        uris["unknown"]++;
    }
}

const map<string_view, int> &Stats::GetMethodStats() const {
    return methods;
}

const map<string_view, int> &Stats::GetUriStats() const {
    return uris;
}

HttpRequest ParseRequest(string_view line) {
    HttpRequest request;
    size_t pos = 0;
    size_t space = line.find(' ', pos);
    while (space == 0) {
        line.remove_prefix(1);
        space = line.find(' ', pos);
    }
    request.method = line.substr(pos, space);
    pos = space + 1;
    space = line.find(' ', pos);
    request.uri = line.substr(pos, space - pos);
    pos = space + 1;
    request.protocol = line.substr(pos);
    return request;
}