#include <iostream>

void swipe(int arr[], unsigned int first, unsigned int second) {
	unsigned int temp = arr[first];
	arr[first] = arr[second];
	arr[second] = temp;
	return;
}

void sort(int arr[], unsigned int from, unsigned int till) {
	if (2 * from >= till) {
		return;
	}
	sort(arr, 2 * from + 1, till);
	sort(arr, 2 * from + 2, till);
	if (2 * from + 2 <= till) {
		if (arr[2 * from + 2] > arr[2 * from + 1]) {
			if (arr[2 * from + 2] > arr[from]) {
				swipe(arr, 2 * from + 2, from);
			}
		}
		else if (arr[2 * from + 1] > arr[from]) {
			swipe(arr, 2 * from + 1, from);
		}
	}
	else if (arr[2 * from + 1] > arr[from]) {
		swipe(arr, 2 * from + 1, from);
	}
	return;
}

void pyramid(int arr[], unsigned int length) {
	if (length == 0) {
		return;
	}
	sort(arr, 0, length);
	swipe(arr, 0, length);
	pyramid(arr, length - 1);
	return;
}

void second() {
	using namespace std;
	unsigned N, n_evens, n_odds;
	cin >> N;
	n_evens = N / 2;
	n_odds = N - n_evens;
	int* list_evens = new (nothrow) int[n_evens];
	if (list_evens == nullptr) {
		cout << "Error in memory alocation";
		delete[] list_evens;
		return;
	}
	int* list_odds = new (nothrow) int[n_odds];
	if (list_odds == nullptr) {
		cout << "Error in memory alocation";
		delete[] list_evens;
		delete[] list_odds;
		return;
	}
	if (N > 0) {
		for (unsigned i = 0; i < N; i++) {
			if (i % 2 == 0) {
				cin >> list_odds[i / 2];
			}
			else {
				cin >> list_evens[(i - 1) / 2];
			}
		}
	}
	pyramid(list_odds, n_odds - 1);
	pyramid(list_evens, n_evens - 1);
	for (unsigned i = 0; i < n_odds; i++) {
		cout << list_odds[n_odds - 1 - i] << ' ';
	}
	for (unsigned i = 0; i < n_evens; i++) {
		cout << list_evens[n_evens - 1 - i] << ' ';
	}
	delete[] list_evens;
	delete[] list_odds;
	return;
}

int main() {
	second();
	return 0;
}
