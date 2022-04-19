#include <iostream>


unsigned energy(int array[], unsigned n) {
    unsigned min, min_prev;
    if (n == 1) {
        return 0;
    }
    if (n == 2) {
        return abs(array[1] - array[0]);
    }
    min_prev = energy(array, n - 2) + 3 * abs(array[n - 1] - array[n - 3]);
    min = energy(array, n - 1) + abs(array[n - 1] - array[n - 2]);
    if (min_prev < min) {
        return min_prev;
    }
    return min;
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

