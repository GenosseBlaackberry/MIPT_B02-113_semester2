#include <iostream>
#include <string>

unsigned const N_students = 5;

struct STUDENT {
    std::string NAME;
	unsigned AGE = 0;
	unsigned GROUP = 0;
	unsigned N_marks = 0;
	unsigned SES[30] = { 0 };
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
		cin >> a >> b >> STUD1[i].AGE >> STUD1[i].GROUP >> STUD1[i].N_marks;
		STUD1[i].NAME = a + " " + b;
		for (unsigned j = 0; j < STUD1[i].N_marks; j++) {
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
		for (unsigned j = 0; j < N_students - (i + 1); j++) {
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

void add_mark(STUDENT& s, int mark) {
	s.SES[s.N_marks] = unsigned(mark);
	s.N_marks++;
}

void good_score(STUDENT STUD1[]) {
	for (unsigned i = 0; i < N_students; i++) {
		unsigned n = 0;
		unsigned N_marks_started = STUD1[i].N_marks;
		for (unsigned j = 0; j < N_marks_started; j++) {
			n += STUD1[i].SES[j];
		}
		for (unsigned j = 0; j < 9 * N_marks_started - 2 * n; j++) {
			add_mark(STUD1[i], 5);
		}
	}
}


void second() {
    using namespace std;

    STUDENT* STUD1 = new (nothrow) STUDENT[N_students];

	if (STUD1 == nullptr) {
		cout << "Error in memory alocation";
		delete[] STUD1;
		return;
	}

	input_students(STUD1);
	sort_students(STUD1);
	good_score(STUD1);

    for (unsigned i = 0; i < N_students; i++) {
		cout << endl;
		cout << STUD1[i].NAME << " " << STUD1[i].AGE << " " << STUD1[i].GROUP << " " << STUD1[i].N_marks << endl;
		for (unsigned j = 0; j < STUD1[i].N_marks; j++) {
			cout << STUD1[i].SES[j] << " ";
		}
    }

	cout << endl;

	delete[] STUD1;
	return;
}


int main() {
    second();
    return 0;
}
