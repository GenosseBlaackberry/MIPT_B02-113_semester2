#include <iostream>
#include <string>

const unsigned N = 8;

void turns(unsigned pawns[], unsigned n) {
    using namespace std;
    unsigned* array = new (nothrow) unsigned[N * N];
    unsigned counter = 0;
    if (array == nullptr) {
        cout << "Error in memory alocation";
        delete[] array;
        return;
    }

    for (unsigned i = 0; i < N * N; i++) {
        array[i] = 0;
    }

    array[N * pawns[2 * n + 1] + pawns[2 * n]] = 1;

    /*
    for (unsigned i = N - 1; i > 0; i--) {
        for (unsigned j = 0; j < N; j++) {
            cout << array[i * N + j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    */

    for (unsigned i = 1; i < N; i++) {
        for (unsigned j = 0; j < N; j++) {
            bool flag = 1;
            for (unsigned k = 0; k < n && flag; k++) {
                if (pawns[2 * k] == j && pawns[2 * k + 1] == i) {
                    if (j == 0) {
                        array[N * i + j] += array[N * (i - 1) + (j + 1)];
                    }
                    else if (j == (N - 1)) {
                        array[N * i + j] += array[N * (i - 1) + (j - 1)];
                    }
                    else {
                        array[N * i + j] += array[N * (i - 1) + (j - 1)] + array[N * (i - 1) + (j + 1)];
                    }      
                    flag = 0;
                }
            }
            if (flag == 1) {
                array[N * i + j] += array[N * (i - 1) + j];
            }
        }
    }

    /*
    for (unsigned i = N - 1; i > 0; i--) {
        for (unsigned j = 0; j < N; j++) {
            cout << array[i * N + j] << " ";
        }
        cout << endl;
    }
    */

    for (unsigned i = 0; i < N; i++) {
        counter += array[N * (N - 1) + i];
    }

    cout << counter;
    delete[] array;
    return;
}

void third() {
    using namespace std;
    unsigned n;
    string input;

    cin >> n;
    unsigned* pawns = new (nothrow) unsigned[2*(n + 1)];
    if (pawns == nullptr) {
        cout << "Error in memory alocation";
        delete[] pawns;
        return;
    }
    for (unsigned i = 0; i < n + 1; i++) {
        cin >> input;
        
        if (input[0] == 'a') {
            pawns[2 * i] = 0;
        }
        else if (input[0] == 'b') {
            pawns[2 * i] = 1;
        }
        else if (input[0] == 'c') {
            pawns[2 * i] = 2;
        }
        else if (input[0] == 'd') {
            pawns[2 * i] = 3;
        }
        else if (input[0] == 'e') {
            pawns[2 * i] = 4;
        }
        else if (input[0] == 'f') {
            pawns[2 * i] = 5;
        }
        else if (input[0] == 'g') {
            pawns[2 * i] = 6;
        }
        else if (input[0] == 'h') {
            pawns[2 * i] = 7;
        }

        if (input[1] == '1') {
            pawns[2 * i + 1] = 0;
        }
        else if (input[1] == '2') {
            pawns[2 * i + 1] = 1;
        }
        else if (input[1] == '3') {
            pawns[2 * i + 1] = 2;
        }
        else if (input[1] == '4') {
            pawns[2 * i + 1] = 3;
        }
        else if (input[1] == '5') {
            pawns[2 * i + 1] = 4;
        }
        else if (input[1] == '6') {
            pawns[2 * i + 1] = 5;
        }
        else if (input[1] == '7') {
            pawns[2 * i + 1] = 6;
        }
        else if (input[1] == '8') {
            pawns[2 * i + 1] = 7;
        }
    }

    turns(pawns, n);
    delete[] pawns;
    return;
}

int main()
{
    third();
    return 0;
}
