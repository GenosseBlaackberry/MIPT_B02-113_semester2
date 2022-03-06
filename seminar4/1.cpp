void first() {
	unsigned int temp;
	using namespace std;
	cin >> temp;
	if (temp == 0) {
		return;
	}
	if (temp % 2 != 0) {
		cout << temp << endl;
		cout << endl;
	}
	first();
}


int main() {
	first();
	return 0;
}
