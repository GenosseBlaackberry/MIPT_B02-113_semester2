#include <iostream>

void swipe(unsigned int arr[], unsigned int first, unsigned int second) {
	unsigned int temp = arr[first];
	arr[first] = arr[second];
	arr[second] = temp;
	return;

}

void sort(unsigned int arr[], unsigned int from, unsigned int till) {
	if (2 * from >= till - 2){
		return;
	}
	if (arr[2 * from + 1] >= arr[2 * from + 2]){
		if (arr[2 * from + 1] >= arr[from]) {
			swipe(arr, 2 * from + 1, from);
		}
	}
	else if (arr[2 * from + 2] >= arr[from]) {
		std::cout << arr[2 * from + 2] << ' ' << arr[from] << std::endl;
		swipe(arr, 2 * from + 2, from);
	}
	sort(arr, 2 * from + 1, till);
	sort(arr, 2 * from + 2, till);
	return;
}

void pyramid(unsigned int arr[], unsigned int length) {
	unsigned int temp;
	if (length == 1) {
		return;
	}
	swipe(arr, 0, length - 1);
	sort(arr, 0, length);
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
	pyramid(arr, n);
	for (unsigned int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
}

int main() {
	seventh();
	return 0;
}
