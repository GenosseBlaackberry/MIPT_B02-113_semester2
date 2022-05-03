#include <iostream>

struct Tree {
    Tree* left = nullptr;
    Tree* right = nullptr;
    unsigned data = 0;
};

struct Line {
    Line* before = nullptr;
    Line* after = nullptr;
    Tree* data = nullptr;
    unsigned layer = 0;
    unsigned number = 1;
};

void del_tree(Tree*& start) {
    if (start == nullptr) {
        delete start;
        return;
    }
    del_tree(start->left);
    del_tree(start->right);
    delete(start);
    start = nullptr;
    return;
}

void del_line(Line*& start) {
    if (start == nullptr) {
        delete start;
        return;
    }
    del_tree(start->data);
    del_line(start->after);
    delete(start);
    start = nullptr;
    return;
}

void add_tree(Tree* start, unsigned item) {
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

void add_line(Line* start, Tree* item, unsigned layer, unsigned number) {
    using namespace std;
    bool flag = 1;
    Line* pt;
    Line* now = new (nothrow) Line;
    if (now == nullptr) {
        cout << "Error in memory alocation" << endl;
        delete now;
        return;
    }
    now->data = item;
    now->layer = layer;
    now->number = number;
    pt = start;
    while (pt->after != nullptr) {
        pt = pt->after;
    }
    pt->after = now;
    now->before = pt;
    return;
}

void print_ver(Tree* start) {
    using namespace std;
    if (start == nullptr) {
        return;
    }
    cout << "( ";
    if (start->left != nullptr) {
        print_ver(start->left);
    }
    cout << " |" << start->data << "| ";
    if (start->right != nullptr) {
        print_ver(start->right);
    }
    cout << " )";
    return;
}

void print_hor(Tree* start) {
    using namespace std;

    unsigned ammount;
    bool flag = 1;
    Line* pt;
    Line* line = new (nothrow) Line;
    if (line == nullptr) {
        cout << "Error in memory alocation" << endl;
        delete line;
        return;
    }

    cout << endl;
    line->data = start;
    for (unsigned i = 0; flag; i++) {
        flag = 0;
        ammount = 0;
        pt = line;
        while (pt != nullptr) {
            if (pt->layer == i) {
                cout << pt->data->data << " ";
                if (pt->data->left != nullptr) {
                    ammount++;
                    add_line(line, pt->data->left, i + 1, ammount);
                    flag = 1;
                }
                if (pt->data->right != nullptr) {
                    ammount++;
                    add_line(line, pt->data->right, i + 1, ammount);
                    flag = 1;
                }
            }
            pt = pt->after;
        }
        cout << endl;
    }

    


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
    print_hor(start);
    cout << endl;
    while (input != 0) {
        cin >> input;
        if (input == 0) {
            break;
        }
        add_tree(start, input);
        print_hor(start);
        cout << endl;

    }
    del_tree(start);
    print_ver(start);
    return;
}

int main()
{
    input();
    return 0;
}
