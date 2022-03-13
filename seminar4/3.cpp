#include <iostream>

void third_iteration(int &number, int &sum) {
	using namespace std;
	unsigned int temp;
	cin >> temp;
	if (temp == 0) {
		return;
	}
	number++;
	sum += temp;
	third_iteration(number, sum);
}

void third() {
	double average;
	int number = 0;
	int sum = 0;
	third_iteration(number, sum);
	average = double(sum) / double(number);
	std::cout << average;
	return;
}


int main() {
	third();
	return 0;
}
