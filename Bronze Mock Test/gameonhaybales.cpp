#include <iostream>
using namespace std;

int main() {
    int n, a;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a;
        if (a <= 3) {
            cout << "Bessie" << endl;
        }
        else if (a % 3 == 1) {
            cout << "Mildred" << endl;
        }
        else {
            cout << "Bessie" << endl;
        }
    }

    return 0;
}