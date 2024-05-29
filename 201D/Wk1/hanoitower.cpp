#include <iostream>
using namespace std;

int towers;

void move(int n, int currentRod, int nextRod, int unusedRod) {
    if (n==0) {
        return;
    }

    move(n-1, currentRod, unusedRod, nextRod);
    cout << currentRod << "->" << nextRod << endl;
    move(n-1, unusedRod, nextRod, currentRod);
    return;
}

int main() {
    cin >> towers;
    move(towers);
    return 0;
}