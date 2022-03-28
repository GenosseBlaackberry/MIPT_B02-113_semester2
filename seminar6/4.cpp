#include <iostream>

int det(int matrix[], unsigned N) {
	using namespace std;
	unsigned counter;
	int power = 1;
	int d = 0;
	if (N == 1) {
		return matrix[0];
	}
	int* matrix1 = new (nothrow) int[(N - 1) * (N - 1)];
	if (matrix1 == nullptr) {
		cout << "Error in memory alocation";
		delete[] matrix1;
		return -1;
	}
	for (unsigned i = 0; i < N; i++){
		counter = 0;
		for (unsigned j = 1; j < N; j++) {
			for (unsigned k = 0; k < N; k++) {
				if (k != i) {
					matrix1[counter] = matrix[j * N + k];
					counter++;
				}
			}
		}
		cout << endl;
		for (unsigned x = 0; x < (N - 1) * (N - 1); x++) {
			cout << matrix1[x] << " ";
		}
		cout << endl;
		d += matrix[i] * det(matrix1, N - 1) * power;
		power *= -1;
		}
	cout << endl;
	return d;
}

void forth() {
	using namespace std;
	unsigned N;
	cin >> N;
	int* matrix = new (nothrow) int[N*N];
	if (matrix == nullptr) {
		cout << "Error in memory alocation";
		delete[] matrix;
		return;
	}
	for (unsigned i = 0; i < N * N; i++) {
		cin >> matrix[i];
	}

	cout << det(matrix, N) << endl;

	delete[]  matrix;
	return;
}

int main() {
	forth();
	return 0;
}
