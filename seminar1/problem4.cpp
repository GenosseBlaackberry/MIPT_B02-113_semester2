#include <iostream>

void problem4() {
	using namespace std;
	unsigned int N;
	int input, min, min2, max, max2;
	cin >> N;
	cin >> min;
	max = min;
	for (unsigned int i = 1; i < N; i++) {
		cin >> input;
		if (input < min) {
			min2 = min;
			min = input;
		}
		else if (i == 1 or input < min2) {
			min2 = input;
		}

		if (input > max) {
			max2 = max;
			max = input;
		}
		else if (i == 1 or input > max2) {
			max2 = input;
		}
	}
	cout << min + min2 << " " << max + max2 << endl;
	return;
}

int main(){
	problem4();
	return 0;
}
