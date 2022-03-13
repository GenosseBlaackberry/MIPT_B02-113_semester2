#include <iostream>

void second() {
	unsigned int temp1, temp2;
	using namespace std;
	cin >> temp1;
	if (temp1 == 0) {
		return;
	}
	cout << temp1 << endl;
	cout << endl;
	cin >> temp2;
	if (temp2 == 0) {
		return;
	}
	second();
}


int main() {
	second();
	return 0;
}
