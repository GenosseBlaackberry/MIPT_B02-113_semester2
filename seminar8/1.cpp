#include <iostream>

const int N = 1;

struct item {
    int key;
    item* next;
};


void add(item*& start) {
    using namespace std;

    if (start != nullptr) {
        item* now = new (nothrow) item;
        if (now == nullptr) {
            cout << "Error in memory alocation";
            delete now;
        }
        else {
            cout << endl;
            cin >> now->key;
            now->next = start;
            start = now;
        }
    }
}

void destroy(item*& start) {
    item* pt;

    pt = start;
    while (pt != nullptr) {
        item* temp = pt;
        pt = pt->next;
        delete temp;
    }
    start = nullptr;
}

void print(item* start) {
    using namespace std;
    item* pt;

    cout << endl;
    pt = start;
    while (pt != nullptr) {
        cout << "->" << pt->key;
        pt = pt->next;
    }
}

void add_ordered(item*& start) {
    using namespace std;
    item* pt = start;

    if (start != nullptr) {
        item* now = new (nothrow) item;
        if (now == nullptr) {
            cout << "Error in memory alocation";
            return;
        }
        
        cout << endl;
        cin >> now->key;
        if (start->key > now->key) {
            now->next = start;
            start = now;
            return;
        }
        while (pt->next != nullptr && pt->next->key <= now->key) {
            pt = pt->next;
        }
        now->next = pt->next;
        pt->next = now;
    }
}

void delete_by_key(item*& start) {
    using namespace std;
    int del_key;
    item* pt;

    if (start != nullptr) {
        cout << endl;
        cin >> del_key;
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
}


void first() {
    using namespace std;
    item* prev;

    item* start = new (nothrow) item;
    if (start == nullptr) {
        cout << "Error in memory alocation";
        delete start;
    }
    else {
        cin >> start->key;
        start->next = nullptr;
        prev = start;

        for (unsigned i = 0; i < N - 1; i++) {
            item* now = new (nothrow) item;
            if (now == nullptr) {
                cout << "Error in memory alocation";
                delete now;
            }
            cin >> now->key;
            now->next = nullptr;
            prev->next = now;
            prev = now;
        }
        print(start);
        delete_by_key(start);
        print(start);
    }
}
int main()
{
    first();
    return 0;
}
