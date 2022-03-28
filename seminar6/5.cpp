#include <iostream>

int* my_slightly_dumb_reallocation(int* source, unsigned int n_old, unsigned int n_new) {
	using namespace std;
	int* path = new (nothrow) int[n_new];
	if (path == nullptr) {
		cout << "Error in memory alocation";
		delete[] path;
		return source;
	}
	if (source == NULL) {
		return path;
	}
	for (unsigned i = 0; i < n_new && i < n_old; i++) {
		path[i] = source[i];
	}
	return path;
}

int fifth() {
	using namespace std;
	unsigned int n, i;
	cin >> n;
	int* a = my_slightly_dumb_reallocation(NULL, 0, n / 2);
	for (i = 0; i < n / 2; i++)
		cin >> a[i];
	a = my_slightly_dumb_reallocation(a, n / 2, n);
	for (; i < n; i++)
		cin >> a[i];
	int sum = 0;
	for (i = 0; i < n; i++)
		sum += a[i];
	cout << sum << endl;
	a = my_slightly_dumb_reallocation(a, n, n / 2);
	a = my_slightly_dumb_reallocation(a, n / 2, 0);
	a = my_slightly_dumb_reallocation(a, 0, 0);
	return 0;
}


int main() {
	fifth();
	return 0;
}
