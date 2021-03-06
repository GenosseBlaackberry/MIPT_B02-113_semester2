#include <iostream>

struct item {
    unsigned key;
    unsigned profit;
    unsigned mass;
    double goodness;
    item* next;
};

void destroy(item*& start) {
    item* pt;

    pt = start;
    while (pt != nullptr) {
        item* temp = pt;
        pt = pt->next;
        delete temp;
    }
    start = nullptr;
    return;
}

void print(item* start) {
    using namespace std;
    item* pt;

    pt = start;
    while (pt != nullptr) {
        cout << " -> " << pt->key << ": " << pt->profit << " " << pt->mass << " " << pt->goodness;
        pt = pt->next;
    }
    cout << endl;
    return;
}

void delete_by_key(item*& start, unsigned del_key) {
    using namespace std;
    item* pt;

    if (start != nullptr) {
        if (start->key == del_key) {
            item* temp = start;
            start = start->next;
            delete temp;
            return;
        }
        pt = start;
        while (pt->next != nullptr && pt->next->key != del_key) {
            pt = pt->next;
        }
        if (pt->next != nullptr) {
            item* temp = pt->next;
            pt->next = pt->next->next;
            delete temp;
        }
    }
    return;
}

void greedy(item*& start, unsigned n) {
    using namespace std;
    unsigned time;
    item* chosen = start;
    item* pt;

    if (start == nullptr) {
        return;
    }

    pt = start;

    while (pt != nullptr) {
        if (pt->goodness > chosen->goodness) {
            chosen = pt;

        }
        pt = pt->next;
    }

    cout << chosen->key << " ";
    
    if (chosen->mass < n) {
        cout << chosen->mass <<endl;
        unsigned output = n - chosen->mass;
        delete_by_key(start, chosen->key);
        greedy(start, output);
        return;
    }
    else {
        cout << n << endl;
        return;
    }
}

void third() {
    using namespace std;
    unsigned N, n;
    item* prev;

    cin >> N;

    item* start = new (nothrow) item;
    if (start == nullptr) {
        cout << "Error in memory alocation";
        delete start;
    }
    else {
        if (N == 0) {
            return;
        }
        cin >> start->key;
        cin >> start->profit;
        cin >> start->mass;
        start->goodness = float(start->profit) / float(start->mass);
        start->next = nullptr;
        prev = start;

        for (unsigned i = 1; i < N; i++) {
            item* now = new (nothrow) item;
            if (now == nullptr) {
                cout << "Error in memory alocation";
                delete now;
                return;
            }
            cin >> now->key;
            cin >> now->profit;
            cin >> now->mass;
            now->goodness = float(now->profit) / float(now->mass);
            now->next = nullptr;
            prev->next = now;
            prev = now;
        }
    }
    cin >> n;
    greedy(start, n);
    destroy(start);
    return;
}

int main() {
    third();
    return 0;
}
