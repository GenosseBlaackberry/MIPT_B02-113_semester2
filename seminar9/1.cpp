#include <iostream>

struct item {
    unsigned key;
    unsigned from;
    unsigned till;
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
        cout << " -> " << pt->key << ": " << pt->from << " " << pt->till;
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

void greedy(item*& start) {
    using namespace std;
    unsigned time;
    item* chosen = start;
    item* pt;

    if (start == nullptr) {
        return;
    }

    pt = start;

    while (pt != nullptr) {
        if (pt->till < chosen->till) {
            chosen = pt;

        }
        pt = pt->next;
    }

    cout << chosen->key << " ";
    time = chosen->till;
    pt = start;

    while (pt != nullptr) {
        if (pt->from < time) {
            delete_by_key(start, pt->key);
            pt = start;
        }
        else {
            pt = pt->next;
        }
    }
    greedy(start);
}

void first() {
    using namespace std;
    unsigned N;
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
        cin >> start->from;
        cin >> start->till;
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
            cin >> now->from;
            cin >> now->till;
            now->next = nullptr;
            prev->next = now;
            prev = now;
        }
    }
    greedy(start);
    destroy(start);
    return;
}

int main() {
    first();
    return 0;
}
