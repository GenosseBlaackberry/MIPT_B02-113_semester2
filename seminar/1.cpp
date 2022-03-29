#include <iostream>
#include <string>

unsigned const N_students = 10;
unsigned const N_marks = 5;

struct STUDENT {
    std::string NAME;
    unsigned GROUP;
    unsigned SES[5];
};


void swipe(unsigned int arr[], unsigned int first, unsigned int second) {
	unsigned int temp = arr[first];
	arr[first] = arr[second];
	arr[second] = temp;
	return;

}

void input_students(STUDENT STUD1[]) {
	using namespace std;
	for (unsigned i = 0; i < N_students; i++) {
		string a, b;
		cin >> a >> b >> STUD1[i].GROUP;
		STUD1[i].NAME = a + " " + b;
		for (unsigned j = 0; j < N_marks; j++) {
			cin >> STUD1[i].SES[j];
		}
	}
}

void sort_students(STUDENT STUD1[]) {
	unsigned indexes[N_students] = { 0 };
	STUDENT output[N_students];
	for (unsigned i = 0; i < N_students; i++) {
		indexes[i] = i;
	}
	
	for (unsigned i = 0; i < N_students; i++) {
		bool sorted = 1;
		for (int j = 0; j < N_students - (i + 1); j++) {
			if (STUD1[indexes[j]].NAME.compare(STUD1[indexes[j + 1]].NAME) == 1) {
				sorted = 0;
				swipe(indexes, j, j + 1);
			}
		}
		if (sorted) {
			break;
		}
	}
	
	for (unsigned i = 0; i < N_students; i++) {
		output[i] = STUD1[indexes[i]];
	}

	for (unsigned i = 0; i < N_students; i++) {
		STUD1[i] = output[i];
	}
}


void first() {
    using namespace std;

    STUDENT STUD1[N_students];

	input_students(STUD1);
	sort_students(STUD1);

	bool no_dvoechniks = 1;

    for (unsigned i = 0; i < N_students; i++) {
        for (unsigned j = 0; j < N_marks; j++) {
			if (STUD1[i].SES[j] == 2) {
				no_dvoechniks = 0;
				cout << endl;
				cout << STUD1[i].NAME << " " << STUD1[i].GROUP << endl;
				break;
			}
        }
    }
	if (no_dvoechniks) {
		cout << endl;
		cout << "There are no dvoechniks" << endl;
	}
}


int main() {
    first();
    return 0;
}
