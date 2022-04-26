#include <iostream>

struct Tree {
    Tree* left = nullptr;
    Tree* right = nullptr;
    unsigned data = 0;
    int difference = 0;
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

unsigned length(Tree* start) {
    unsigned counter = 0;
    if (start == nullptr) {
        return 0;
    }
    if (length(start->left) > length(start->right)) {
        return length(start->left) + 1;
    }
    else {
        return length(start->right) + 1;
    }
}

void diffs(Tree* start) {
    if (start == nullptr) {
        return;
    }
    start->difference = length(start->right) - length(start->left);
    diffs(start->left);
    diffs(start->right);
    return;
}

void balance(Tree*& start) {
    using namespace std;
    Tree* temp;

    if (start == nullptr) {
        return;
    }
    if (length(start->right) == 2 && length(start->left) == 0) {
        Tree* now = new (nothrow) Tree;
        if (now == nullptr) {
            cout << "Error in memory alocation" << endl;
            delete now;
            return;
        }
        now->data = start->data;
        temp = start->right;
        delete start;
        start = temp;
        start->left = now;
        return;
    }
    balance(start->right);
    if (length(start->left) == 2 && length(start->right) == 0) {
        Tree* now = new (nothrow) Tree;
        if (now == nullptr) {
            cout << "Error in memory alocation" << endl;
            delete now;
            return;
        }
        now->data = start->data;
        temp = start->left;
        delete start;
        start = temp;
        start->right = now;
        return;
    }
    balance(start->left);
    return;
}

void add(Tree*& start, unsigned item) {
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
    balance(start);
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
    cout << " |" << start->data << "/" << start->difference << "| ";
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
