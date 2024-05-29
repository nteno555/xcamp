#include <iostream>
using namespace std;

int main() {
    int t, x, y, a, area, temp;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> x >> y >> a;
        area = x * y;
        for (int j=0; j<a; j++) {
            cin >> temp;
            area = area - (temp * temp);
        }
        if (area >= 0) {
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }

    return 0;
}