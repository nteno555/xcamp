#include <iostream>
using namespace std;

int n;
int dice[1000001];

int add(int a, int b) {
    int c = 1000000007  - a;
    if (c==b) return 0;
    if (b<c) return a+b;
    else return b-c;
}

void dp() {
    for (int i=2; i<=n; i++) {
        for (int j=1; j<=min(i, 6); j++) {
            dice[i] = add(dice[i], dice[i-j]);
        }
    }
    return;
}

int main() {
    cin >> n;
	
    dice[0] = 0;
    for (int i=1; i<7; i++) dice[i] = 1;

    dp();

    cout << dice[n];
}