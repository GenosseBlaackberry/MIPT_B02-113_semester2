#include <iostream>
#include <cstdlib>
#include <ctime>

bool to_draw = 0;
bool problem_number = 0;

void input(unsigned int &max_x, unsigned int &max_y, unsigned int &N,
	unsigned int x_cors[], unsigned int y_cors[]) {
	using namespace std;
	if (problem_number == 0) {
		cin >> max_x;
		max_y = max_x;
		N = 1;
	}
	else {
		cin >> max_x >> max_y;
		cin >> N;
	}
	for (unsigned int i = 0; i < N; i++) {
		cin >> x_cors[i];
		cin >> y_cors[i];
	}
	return;
}


void visualization(unsigned int max_x, unsigned int max_y, unsigned int N,
	unsigned int x_cors[], unsigned int y_cors[], bool stopped[], unsigned int modulation_time) {
	if (to_draw == 1) {
		using namespace std;
		cout << endl;
		cout << modulation_time << endl;
		for (unsigned int i = 0; i < max_x; i++) {
			cout << '|';
			for (unsigned int j = 0; j < max_y; j++) {
				bool found = 0;
				for (unsigned int k = 0; k < N && found == 0; k++) {
					if (x_cors[k] == i && y_cors[k] == j) {
						if (stopped[k] == 0) {
							cout << 0;
						}
						else {
							cout << 'x';
						}
						found = 1;
					}
				}
				if (found == 0) {
					cout << '.';
				}
			}
			cout << '|' << endl;
		}
	}
	return;
}


void move_checker(unsigned int max_x, unsigned int max_y, unsigned int N,
	unsigned int x_cors[], unsigned int y_cors[], unsigned int x_wanted_cors[], unsigned int y_wanted_cors[], bool stopped[]) {
	for (unsigned int i = 0; i < N; i++) {
		for (unsigned int j = i; j < N; j++) {
			x_cors[i] = x_wanted_cors[i];
			y_cors[i] = y_wanted_cors[i];
			if (x_wanted_cors[i] != x_wanted_cors[j] || y_wanted_cors[i] != y_wanted_cors[j]) {
				x_cors[j] = x_wanted_cors[j];
				y_cors[j] = y_wanted_cors[j];
			}
		}
		if (x_cors[i] == max_x - 1 || x_cors[i] == 0 || y_cors[i] == max_y - 1 || y_cors[i] == 0) {
			stopped[i] = 1;
		}
	}
	return;
}

void stand_checker(unsigned int N, unsigned int x_cors[], unsigned int y_cors[], bool stopped[]) {
	for (unsigned int i = 0; i < N; i++) {
		for (unsigned int j = i + 1; j < N; j++) {
			if ((x_cors[i] - x_cors[j]) * (x_cors[i] - x_cors[j]) + (y_cors[i] - y_cors[j]) * (y_cors[i] - y_cors[j]) <= 1) {
				stopped[i] = 1;
				stopped[j] = 1;
			}
		}
	}
	return;
}


unsigned int iterations(unsigned int max_x, unsigned int max_y, unsigned int N,
	unsigned int x_cors[], unsigned int y_cors[], bool stopped[]) {
	unsigned int x_wanted_cors[1000], y_wanted_cors[1000];
	unsigned int stop_counter = 0;
	unsigned int modulation_time = 0;
	visualization(max_x, max_y, N, x_cors, y_cors, stopped, modulation_time);
	while (stop_counter < N) {
		stop_counter = 0;
		modulation_time++;
		for (unsigned int i = 0; i < N; i++) {
			x_wanted_cors[i] = x_cors[i];
			y_wanted_cors[i] = y_cors[i];
			if (stopped[i] == 0) {
				short way = rand() % 4;
				if (way == 0) {
					x_wanted_cors[i]++;
				}
				else if (way == 1) {
					x_wanted_cors[i]--;
				}
				else if (way == 2) {
					y_wanted_cors[i]++;
				}
				else {
					y_wanted_cors[i]--;
				}
			}
			else {
				stop_counter++;
			}
		}
		move_checker(max_x, max_y, N, x_cors, y_cors, x_wanted_cors, y_wanted_cors, stopped);
		stand_checker(N, x_cors, y_cors, stopped);
		stop_counter = 0;
		for (unsigned int i = 0; i < N; i++) {
			if (stopped[i] == 1) {
				stop_counter++;
			}
		}
		visualization(max_x, max_y, N, x_cors, y_cors, stopped, modulation_time);
	}
	return modulation_time;
}


void output(unsigned int max_x, unsigned int max_y, unsigned int N,
	unsigned int x_cors[], unsigned int y_cors[], bool stopped[]) {
	using namespace std;
	unsigned int to_print = iterations(max_x, max_y, N, x_cors, y_cors, stopped);
	cout << endl;
	cout << to_print;
}


int main() {
	unsigned int max_x, max_y, N;
	unsigned int x_cors[1000], y_cors[1000];
	bool stopped[1000] = { 0 };
	input(max_x, max_y, N, x_cors, y_cors);
	output(max_x, max_y, N, x_cors, y_cors, stopped);
	return 0;
}
