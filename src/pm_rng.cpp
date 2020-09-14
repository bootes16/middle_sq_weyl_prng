#include <iostream>

using namespace std;

#include "park_miller_2.h"

int main() {
    ParkMiller2 pm {54321};

    double min = 1.0;
    double max = 0.0;
    const int num = 10000;
    const int num_bins =20;
    int bins[num_bins] {};

    for (int i = 0; i < num; i++) {
        double n = pm();
        min = n < min ? n : min;
        max = n > max ? n : max;

        bins[ static_cast<int>(n * num_bins) ]++;
    }
    cout << "min: " << min << " max: " << max << endl;
    for (int i = 0; i < num_bins; i++) {
        cout << i << ": " << bins[i] << endl;
    }
}
