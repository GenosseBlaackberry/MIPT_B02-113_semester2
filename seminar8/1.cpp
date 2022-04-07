#include <iostream>

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
            return;
        }
        cin >> now->key;
        now->next = start;
        start = now;
        cout << endl;
    }
    return;
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
    return;
}

void print(item* start) {
    using namespace std;
    item* pt;

    pt = start;
    while (pt != nullptr) {
        cout << "->" << pt->key;
        pt = pt->next;
    }
    cout << endl;
    return;
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
        cout << endl;
    }
    return;
}

void delete_by_key(item*& start) {
    using namespace std;
    int del_key;
    item* pt;

    if (start != nullptr) {
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
        cout << endl;
    }
    return;
}


void first() {
    using namespace std;
    item* prev;
    unsigned input;

    cout << "Enter your list of integers. '0' is stop symbol" << endl;
    item* start = new (nothrow) item;
    if (start == nullptr) {
        cout << "Error in memory alocation";
        delete start;
    }
    else {
        cin >> input;
        if (input == 0) {
            return;
        }
        start->key = input;
        start->next = nullptr;
        prev = start;

        while (input != 0) {
            item* now = new (nothrow) item;
            if (now == nullptr) {
                cout << "Error in memory alocation";
                delete now;
                return;
            }
            cin >> input;
            if (input == 0) {
                continue;
            }
            now->key = input;
            now->next = nullptr;
            prev->next = now;
            prev = now;
        }

        cout << "   Enter 0 to print list" << endl;
        cout << "   Enter 1 to add item to begining" << endl;
        cout << "   Enter 2 to destroy list" << endl;
        cout << "   Enter 3 to add item to sorted list" << endl;
        cout << "   Enter 4 to delete item by key" << endl;
        cout << "   Enter 5 to exit program" << endl;

        while (input != 5) {
            cin >> input;
            if (input == 0) {
                cout << "Your list:" << endl;
                print(start);
            }
            else if (input == 1) {
                cout << "Enter number" << endl;
                add(start);
            }
            else if (input == 2) {
                destroy(start);
                cout << "Your list is destroyed" << endl;
            }
            else if (input == 3) {
                cout << "Enter number" << endl;
                add_ordered(start);
            }
            else if (input == 4) {
                cout << "Enter number" << endl;
                delete_by_key(start);
            }
      
        } 
    }
    return;
}
int main()
{
    first();
    return 0;
}
