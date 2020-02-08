//
// Simple main function illustrating use of the simple PRNG.
//
// Author: Greg Johnson
// Github: bootes16
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

    // Create some PRNGs of different type widths.
    MiddleSqWeyl<char> crng;
    MiddleSqWeyl<unsigned char> ucrng;
    MiddleSqWeyl<int> irng;
    MiddleSqWeyl<uint16_t> u16rng;

    for (int i = 0; i < count; i++) {
        cout << i << ": " << +crng()
            << " " << +ucrng()
            << " " << irng()
            << " " << u16rng()
            << endl;
    } 
}
