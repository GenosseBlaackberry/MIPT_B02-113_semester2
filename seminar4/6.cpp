int female(unsigned int n);

int male(unsigned int n);

int male(unsigned int n) {
	if (n == 0) {
		return 0;
	}
	int add = female(male(n - 1));
	return n - add;
}

int female(unsigned int n) {
	if (n == 0) {
		return 1;
	}
	int add = male(female(n - 1));
	return n - add;
}

void sixth() {
	using namespace std;
	unsigned int n;
	cin >> n;
	cout << female(n) << ' ' << male(n);
}
