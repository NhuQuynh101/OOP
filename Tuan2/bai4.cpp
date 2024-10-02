#include <iostream>
#include <list>
using namespace std;

class List {
private:
    list<double> data;
    unsigned int size;

public:
    List() : size(0) {}

    void add(double x) {
        data.push_back(x);
        size++;
    }

    void remove_first(double x) {
        list<double>::iterator it = data.begin();
        while (it != data.end()) {
            if (*it == x) {
                data.erase(it);
                size--;
                return;
            }
            ++it;
        }
    }

    void remove_all(double x) {
        list<double>::iterator it = data.begin();
        while (it != data.end()) {
            if (*it == x) {
                it = data.erase(it);
                size--;
            }
            else {
                ++it;
            }
        }
    }

    void replace(int index, double x) {
        if (index >= 0 && index < size) {
            list<double>::iterator it = data.begin();
            advance(it, index);
            *it = x;
        }
    }

    void print() {
        cout << "[";
        list<double>::iterator it = data.begin();
        while (it != data.end()) {
            cout << *it;
            if (++it != data.end()) {
                cout << ",";
            }
        }
        cout << "]" << endl;
    }
};

int main() {
    List mylist;

    int n;
    do {
        cin >> n;

        switch(n) {
            case 0: {
                double x;
                cin >> x;
                mylist.add(x);
                break;
            }
            case 1: {
                double x;
                cin >> x;
                mylist.remove_first(x);
                break;
            }
            case 2: {
                double x;
                cin >> x;
                mylist.remove_all(x);
                break;
            }
            case 3: {
                int index;
                double x;
                cin >> index >> x;
                mylist.replace(index, x);
                break;
            }
        }
    } while (n != -1);

    mylist.print();

    return 0;
}
