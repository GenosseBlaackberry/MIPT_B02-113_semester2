#include <iostream>

unsigned int max2(unsigned int a, unsigned int b) {
	if (a >= b) {
		return a;
	}
	else {
		return b;
	}
}

unsigned int max4(unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
	return max2(max2(a, b), max2(c, d));
}

void problem7() {
	using namespace std;
	unsigned int N, first, second, third, forth, maximum;

	first = 0;
	second = 0;
	third = 0;
	forth = 0;
	cin >> N;
	for (unsigned int i = 0; i < N; i++) {
		int x, y;
		cin >> x;
		cin >> y;
		if (y > 0) {
			if (x > 0) {
				first++;
			}
			else if (x < 0) {
				second++;
			}
		}
		else if (y < 0) {
			if (x > 0) {
				forth++;
			}
			else if (x < 0) {
				third++;
			}
		}
	}
	maximum = max4(first, second, third, forth);
	if (first == maximum) {
		cout << 1 << first << endl;
	}
	else if (second == maximum) {
		cout << 2 << second << endl;
	}
	else if (third == maximum) {
		cout << 3 << third << endl;
	}
	else if (forth == maximum) {
		cout << 4 << " " << forth << endl;
	}
	return;
}

int main(){
	problem7();
	return 0;
}
