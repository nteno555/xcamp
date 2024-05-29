#include <iostream>
using namespace std;

int towers;

int powerto(int a, int b) {
    int ans = 1;
    for (int i=0; i<b; i++) {
        ans = ans * a;
    }
    return ans;
}

void move(int n, int t1, int t2, int t3) {
    if (n==0) {
        return;
    }

    move(n-1, t1, t3, t2);
    cout << t1 << "->" << t2 << endl;
    move(n-1, t3, t2, t1);
    return;
}

int main() {
    cin >> towers;
    move(towers, 1, 3, 2);
    cout << "tot=" << powerto(2, towers) -1 << endl;
    return 0;
}