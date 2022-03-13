#include <iostream>

void forth_iteration(unsigned int& counter, unsigned int& max) {
	using namespace std;
	unsigned int temp;
	cin >> temp;
	if (temp == 0) {
		return;
	}
	if (temp > max) {
		max = temp;
		counter = 1;
	}
	else if (temp == max) {
		counter++;
	}
	forth_iteration(counter, max);
	return;
}

void forth() {
	unsigned int counter = 0;
	unsigned int max = 0;
	forth_iteration(counter, max);
	std::cout << counter;
	return;
}


int main() {
	forth();
	return 0;
}
