#include <iostream>
#include <string>

using namespace std;

#define UNIQ_ID_IMPL_2(lineno) id_##lineno
#define UNIQ_ID_IMPL(lineno) UNIQ_ID_IMPL_2(lineno)
#define UNIQ_ID UNIQ_ID_IMPL(__LINE__)

int main() {
    int UNIQ_ID = 5;

    return 0;
}
