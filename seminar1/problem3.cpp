#include <iostream>

void problem3() {
	using namespace std;
	unsigned int input;
	unsigned int previous_input = 0;
	unsigned int inversions = 0;
	do {
		cin >> input;
		if (input > previous_input and previous_input != 0) {
			inversions++;
		};
		previous_input = input;
	} while (input != 0);
	cout << inversions << endl;
	return;
}

int main(){
	problem3();
	return 0;
}
