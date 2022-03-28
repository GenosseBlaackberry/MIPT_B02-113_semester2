#include <iostream>

void my_personal_swap(int* a, int* b) {
	using namespace std;
	if (a == nullptr || b == nullptr) {
		return;
	}
	int* temp = new (nothrow) int;
	if (temp == nullptr) {
		cout << "Error in memory alocation";
		delete temp;
		return;
	}
	*temp = *a;
	*a = *b;
	*b = *temp;
	delete temp;
	return;
}

int third() {
	using namespace std;
	int a, b;
	cin >> a >> b;
	my_personal_swap(&a, &b);
	cout << a << " " << b << endl;
	my_personal_swap(&a, nullptr);
	my_personal_swap(nullptr, &b);
	my_personal_swap(nullptr, nullptr);
	return 0;
}

int main() {
	third();
	return 0;
}
