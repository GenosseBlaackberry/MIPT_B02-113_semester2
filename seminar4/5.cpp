void fifth_iteration(unsigned int n) {
	unsigned int temp;
	using namespace std;
	temp = n % 10;
	if (n == 0) {
		return;
	}
	n = (n - temp) / 10;
	cout << temp;
	fifth_iteration(n);
}

void fifth() {
	unsigned int n;
	std::cin >> n,
	fifth_iteration(n);
	return;
}


int main() {
	fifth();
	return 0;
}
