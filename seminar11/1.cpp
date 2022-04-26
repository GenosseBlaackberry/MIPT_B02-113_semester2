#include <iostream>

struct Tree {
    Tree* left = nullptr;
    Tree* right = nullptr;
    unsigned data = 0;
};

void del(Tree*& start) {
    if (start == nullptr) {
        delete start;
        return;
    }
    del(start->left);
    del(start->right);
    delete(start);
    start = nullptr;
    return;
}

void add(Tree* start, unsigned item) {
    using namespace std;
    bool flag = 1;
    Tree* pt;
    Tree* now = new (nothrow) Tree;
    if (now == nullptr) {
        cout << "Error in memory alocation" << endl;
        delete now;
        return;
    }
    now->data = item;
    pt = start;
    while (flag) {
        if (now->data < pt->data) {
            if (pt->left == nullptr) {
                pt->left = now;
                flag = 0;
            }
            pt = pt->left;
        }
        else {
            if (pt->right == nullptr) {
                pt->right = now;
                flag = 0;
            }
            pt = pt->right;
        }
    }
    return;
}

void print(Tree* start) {
    using namespace std;
    if (start == nullptr) {
        return;
    }
    cout << "( ";
    if (start->left != nullptr) {
        print(start->left);
    }
    cout << " |" << start->data << "| ";
    if (start->right != nullptr) {
        print(start->right);
    }
    cout << " )";
    return;
}

void input() {
    using namespace std;
    unsigned input;
    Tree* start = new (nothrow) Tree;
    if (start == nullptr) {
        cout << "Error in memory alocation" << endl;
        delete start;
        return;
    }
    cin >> input;
    if (input == 0) {
        return;
    }
    start->data = input;
    print(start);
    cout << endl;
    while (input != 0) {
        cin >> input;
        if (input == 0) {
            break;
        }
        add(start, input);
        print(start);
        cout << endl;

    }
    del(start);
    print(start);
    return;
}

int main()
{
    input();
    return 0;
}
