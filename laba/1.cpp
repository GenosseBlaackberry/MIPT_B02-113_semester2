#include <iostream>
#include <cstdlib>
#include <ctime>

unsigned int max_x, max_y, N;
unsigned int x_cors[10000], y_cors[10000];
bool stopped[10000] = { 0 };

void input(unsigned int& max_x, unsigned int& max_y, unsigned int& N,
	unsigned int x_cors[], unsigned int y_cors[]) {
	using namespace std;
	cin >> max_x >> max_y;
	cin >> N;
	for (unsigned int i = 0; i < N; i++) {
		cin >> x_cors[i];
		cin >> y_cors[i];
	}
	return;
}

void iteration(unsigned int& max_x, unsigned int& max_y, unsigned int& N,
	unsigned int x_cors[], unsigned int y_cors[], bool stopped[]) {
	for (unsigned int i = 0; i < N; i++) {
		unsigned int j = 0;
		while (stopped[i] == 0) {
			j++;
			if (x_cors[i] == max_x || x_cors[i] == 0 || y_cors[i] == max_y || y_cors[i] == 0) {
				stopped[i] = 1;
			}
			else {
				short way = rand() % 4;
				if (way == 0) {
					x_cors[i]++;
				}
				else if (way == 1) {
					x_cors[i]--;
				}
				else if (way == 2) {
					y_cors[i]++;
				}
				else {
					y_cors[i]--;
				}
			}
		}
		std::cout << j << std::endl;
	}
	return;
}



int main() {
	input(max_x, max_y, N, x_cors, y_cors);
	iteration(max_x, max_y, N, x_cors, y_cors, stopped);
	return 0;
}
