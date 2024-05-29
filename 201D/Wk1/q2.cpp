#include <iostream>
using namespace std;

int main() {
    int a;
    int total = 0;
    while (cin >> a) {
        if (total == 0) {
            total = total + a;
        }
        else {
            total = total + a;
            cout << total;
            total = 0;
        }
    }
    return 0;
}