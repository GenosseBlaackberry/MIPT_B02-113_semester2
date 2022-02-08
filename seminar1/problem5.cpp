#include <iostream>

void problem5() {
	using namespace std;
	int a1, b1, c1, a2, b2, c2;
	float x, y, det;
	cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
	det = a1 * b2 - a2 * b1;
	if (det != 0) {
		x = (b1 * c2 - b2 * c1) / det;
		y = (a2 * c1 - a1 * c2) / det;
		cout << x << " " << y << endl;
	}
	else {
		cout << "No" << endl;
	}

	return;
}

int main(){
	problem5();
	return 0;
}
