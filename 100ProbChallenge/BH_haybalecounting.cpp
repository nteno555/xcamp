#include <iostream>
using namespace std;

int main() {
    int n, q, temp, start, end;
    int psum[1000001];

    cin >> n >> q;

    for (int i=0; i<1000001; i++) {
        psums[i] = 0;
    }

    for (int i=0; i<n; i++) {
        cin >> temp;
        for (int j=0; j<n; j++) {
            psums[j]++;
        }
    }

    for (int i=0; i<q; i++) {
        cin >> start >> end;
        cout << psums[end] - psums[start-1];
    }

    return 0;
}