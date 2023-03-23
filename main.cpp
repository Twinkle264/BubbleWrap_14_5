#include <iostream>
using namespace std;

void inflate (bool a[12][12]) {
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            a[i][j] = true;
        }
    }
}

bool non_poped (int a, int b, int a1, int b1, bool matrix[12][12]) {
    for (int i = a; i <= a1; ++i) {
        for (int j = b; j <= b1; ++j) {
            if (!matrix[i][j]) {
                cout << "At these coordinates, the polyethylene has already burst!" << endl;
                return false;
            }
        }
    }
    return true;
}

bool is_valid (int a, int b, int a1, int b1) {
    if (a < 0 || b < 0 || a1 < 0 || b1 < 0 || a > 11 || b > 11 || a1 > 11 || b1 > 11) {
        cout << "Incorrect coordinates!" << endl;
        return false;
    }
    return true;
}

void pop (int a, int b, int a1, int b1, bool matrix[12][12]) {
    for (int i = a; i <= a1; ++i) {
        for (int j = b; j <= b1; ++j) {
            matrix[i][j] = false;
            cout << endl << "Pop!" << endl;
        }
    }
}

bool checkStatus (bool a[12][12]) {
    int counter = 0;
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            if (!a[i][j]) {
                ++counter;
            }
        }
    }
    if (counter >= 144) {
        return false;
    } else {
        return true;
    }
}

void show_matrix (bool a[12][12]) {
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            if (a[i][j]) {
                cout << 'o' << ' ';
            } else {
                cout << 'X' << ' ';
            }
        }
        cout << endl;
    }
}

int main() {
    bool bubble_wrap[12][12];
    int x = 0, x1 = 0;
    int y = 0, y1 = 0;

    inflate(bubble_wrap);

    while (checkStatus(bubble_wrap)) {
        do {
            show_matrix(bubble_wrap);
            cout << endl;
            cout << "Input coordinates:" << endl;
            cin >> x >> y;
            cin >> x1 >> y1;

            if (!is_valid(x, y, x1, y1)) break;

            if (non_poped(x, y, x1, y1, bubble_wrap)) {
                pop(x, y, x1, y1, bubble_wrap);
            }
            if (!checkStatus(bubble_wrap)) break;
        } while (is_valid(x, y, x1, y1));
    }

    show_matrix(bubble_wrap);
    cout << endl << "Already bubbles are popped!" << endl;

    return 0;
}
