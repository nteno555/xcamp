#include <bits/stdc++.h>
using namespace std;

int main() {
    int temp, n;
    unordered_set<int> s;

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> temp;
        s.insert(temp);
    }
    cout << s.size();
}