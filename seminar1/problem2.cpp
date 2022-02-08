#include <iostream>

void problem2() {
	using namespace std;
	unsigned int N;
	unsigned int input;
	unsigned int min = 0;
	unsigned int repeats = 0;
	cin >> N;
	for (unsigned int i = 0; i < N; i++) {
		cin >> input;
		if (input < min or repeats == 0) {
			min = input;
			repeats = 1;
		}
		else if (input == min) {
			repeats++;
		}
	}
	cout << min << " " << repeats << endl;
	return;
}

int main(){
	problem2();
	return 0;
}
