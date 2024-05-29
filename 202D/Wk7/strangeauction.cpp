#include <bits/stdc++.h>
using namespace std;

int main() {
    int start, target, a, b;
    cin >> start >> target >> a >> b;
    
    int arr[start+1];
    
    start -= target;

    for (int i=0; i<=start; i++) {
        arr[i] = 0;
    }

    arr[a] = 1;
    arr[b] = 1;

    for (int i=0; i<=start; i++) {
        if (i>=a) arr[i] += arr[i-a];
        if (i>=b) arr[i] += arr[i-b];
    }

    cout << arr[start];
}