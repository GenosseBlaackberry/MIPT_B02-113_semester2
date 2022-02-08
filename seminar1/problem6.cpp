#include <iostream>

void problem6() {
	using namespace std;
	float x, y, a, b, r;
	cin >> x >> y >> a >> b >> r;
	if ((x - a)*(x - a) + (y - b)*(y - b) <= r*r){
		cout <<  "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return;
}

int main(){
	problem6();
	return 0;
}
