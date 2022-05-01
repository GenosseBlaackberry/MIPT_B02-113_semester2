#include <iostream>


unsigned energy(int array[], unsigned n) {
    unsigned* energies = new (std::nothrow) unsigned[n];
    unsigned output = 0;
    if (energies == nullptr) {
        return output;
    }
    unsigned a, b;
    energies[0] = 0;
    energies[1] = abs(array[1] - array[0]);
    for (unsigned i = 2; i < n; i++) {
        a = energies[i - 2] + 3 * abs(array[i - 2] - array[i]);
        b = energies[i - 1] + abs(array[i - 1] - array[i]);
        if (a < b) {
            energies[i] = a;
        }
        else {
            energies[i] = b;
        }
    }

    output = energies[n - 1];
    delete[] energies;

    return output;
}

void second() {
    using namespace std;
    unsigned n;

    cin >> n;
    int* array = new (nothrow) int[n];
    if (array == nullptr) {
        cout << "Error in memory alocation";
        return;
    }
    for (unsigned i = 0; i < n; i++) {
        cin >> array[i];
    }

    cout << energy(array, n);
    return;
}

int main()
{
    second();
    return 0;
}
