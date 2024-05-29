#include <iostream>
using namespace std;

int n, q;
int cows[1000001], sums[1000001][3], intervals[1000001][2];

void prefixSum() {
    int counter = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<3; j++) {
            sums[i][j] = 0;
        }
    }

    for (int i=0; i<n; i++) {
        sums[i][cows[i]-1]++;
    }
}

int main() {
    int st, end;
    cin >> n >> q;

    for (int i=0; i<n; i++) {
        cin >> cow[n];
    }

    prefixSum();

    for (int i=0; i<q; i++) {
        for (int j=0; j<2; j++) {
            cin >> st >> end;
            cout << sums[end][0]-sums[st][0] << ' ' << sums[end][1]-sums[st][1] << ' ' << sums[end][2]-sums[st][2] << endl;
        }
    }

    return 0;
}