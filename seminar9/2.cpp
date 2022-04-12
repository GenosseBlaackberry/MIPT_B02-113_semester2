#include <iostream>
#include <stdlib.h>


int comp(const void* a, const void* b)
{
    return (*(int*)b - *(int*)a);
}

void greedy(unsigned coins[], unsigned n, unsigned coin_type) {
    using namespace std;
    unsigned output;

    if (n == 0) {
        return;
    }
    output = n / coins[coin_type];
    cout << coins[coin_type] << " " << output << endl;
    n -= coins[coin_type] * output;
    greedy(coins, n, coin_type+1);
}

void second() {
    using namespace std;
    unsigned N, n;

    cin >> N;

    unsigned* coins = new (nothrow) unsigned[N];
    if (coins == nullptr) {
        cout << "Error in memory alocation";
        delete[] coins;
        return;
    }
    for (unsigned i = 0; i < N; i++) {
        cin >> coins[i];
    }
    qsort(coins, N, sizeof(unsigned), comp);
    cin >> n;
    greedy(coins, n, 0);

    delete[] coins;
    return;
}

int main() {
    second();
    return 0;
}
