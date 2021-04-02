#include "test_runner.h"

#include <ostream>
using namespace std;

template <typename K, typename T>
void Print(ostringstream& os, const K& x, const T& y) {
    os << x << endl;
    os << y << endl;
}

#define PRINT_VALUES(out, x, y) Print(out, x, y)

int main() {
    TestRunner tr;
    tr.RunTest([] {
        ostringstream output;
        PRINT_VALUES(output, 5, "red belt");
        ASSERT_EQUAL(output.str(), "5\nred belt\n");
    }, "PRINT_VALUES usage example");
}