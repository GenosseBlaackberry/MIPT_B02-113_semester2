#include <iostream>

unsigned length(int array[], unsigned n) {
    unsigned max, max_prev;
    if (n == 1) {
        return 1;
    }
    max = 0;
    for (unsigned i = 0; i < n - 1; i++) {
        if (array[n - 1] > array[i]) {
            max_prev = length(array, i + 1);
            if (max_prev > max) {
                max = max_prev;
            }
        }
    }
    return max + 1;
}

void first() {
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

    cout << length(array, n);
    return;
}

int main()
{
    first();
    return 0;
}

