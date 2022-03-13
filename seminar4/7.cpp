#include <iostream>

void swipe(unsigned int arr[], unsigned int first, unsigned int second) {
	unsigned int temp = arr[first];
	arr[first] = arr[second];
	arr[second] = temp;
	return;

}

void sort(unsigned int arr[], unsigned int from, unsigned int till) {
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

void pyramid(unsigned int arr[], unsigned int length) {
	unsigned int temp;
	if (length == 0) {
		return;
	}
	sort(arr, 0, length);
	swipe(arr, 0, length);
	pyramid(arr, length - 1);
	return;
}

void seventh() {
	using namespace std;
	unsigned int n;
	unsigned int arr[100] = { 0 };

	cin >> n;
	for (unsigned int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	pyramid(arr, n - 1);
	for (unsigned int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
}

int main() {
	seventh();
	return 0;
}
