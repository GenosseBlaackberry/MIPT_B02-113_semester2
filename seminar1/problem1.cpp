#include <iostream>

void problem1() {
	using namespace std;
	unsigned int input;
	unsigned int max = 0;
	do {
		cin >> input;
		if (input % 2 == 0 and input > max) {
			max = input;
		}
	} while (input != 0);
	cout << max << endl;
	return;
}

int main(){
	problem1();
	return 0;
}
