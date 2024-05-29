#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;
    int n, m, count=1;
    cin >> n >> m;

    for (int i=1; i<=n; i++) {
        q.push(i);
    }

    while (q.size() > 1) {
        if (count == m) {
            cout << q.front() << ' ';
            q.pop();
            m = 1
        }
        else {        
        m++;
        q.push(q.front());
        q.pop();
        } 
    }
}