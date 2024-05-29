#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n, curLetter, count=0, letters[1001];
    queue<int> dictionary;
    map<int, bool> vis;

    for (int i=0; i<n; i++) {
        cin >> letters[i];
        vis.insert({letters[i], false});
    }

    for (int i=0; i<n; i++) {
        curLetter = letters[i];

        if (map[curLetter]) {
            continue;
        }
        else {
            if (q.size() >= m) {
            }
            q.push(curLetter);
            count++;
        }
    }

    cout >> count;
}