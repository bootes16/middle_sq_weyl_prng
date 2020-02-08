//
// Produce a stream of characters from the simple PRNG.
//
#include <iostream>

#include "middle_sq_weyl.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (1 == argc) {
        cout << "Usage: " << argv[0] << " <count>" << endl;
        return -1;
    }

    auto count = atoi(argv[1]);
    MiddleSqWeyl<unsigned char> prng;

    while (count-- > 0)
        cout << prng();
}
