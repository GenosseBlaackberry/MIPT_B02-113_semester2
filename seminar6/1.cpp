#include <iostream>

void first() {
	using namespace std;
	unsigned N, minimum;
	cin >> N;
	minimum = N;
	int* sizez = new (nothrow) int[N];
	if (sizez == nullptr) {
		cout << "Error in memory alocation";
		delete[] sizez;
		return;
	}
	for (unsigned i = 0; i < N; i++) {
		cin >> sizez[i];
	}
	for (unsigned i = 0; i < N; i++) {
		if (sizez[i] < 0) {
			for (unsigned j = i; j < N && j < i + minimum; j++) {
				if (sizez[j] > 0 && -1*sizez[i] == sizez[j]) {
					minimum = j - i;
				}
			}
		}
	}
	if (minimum == N) {
		cout << 0;
	}
	else {
		cout << minimum;
	}
	delete[] sizez;
	return;
}

int main() {
	first();
	return 0;
}
