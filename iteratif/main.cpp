#include <iostream>
#include "tiling_iterative.h"

int main() {
    int n;
    cout << "Masukkan ukuran papan N x N (Iteratif): ";
    cin >> n;

    if (n % 2 != 0) {
        cout << "Tidak ada solusi untuk papan dengan ukuran ganjil." << endl;
    } else {
        test_algorithm(n);
    }

    return 0;
}
