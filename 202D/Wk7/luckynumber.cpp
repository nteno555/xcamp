#include <bits/stdc++.h>
using namespace std;

bool valid(int num) {
    string str = to_string(num);
    int num5=0, num8=0;
    
    for (int i=0; i<str.length(); i++) {
        if (str[i]=='5') num5++;
        else num8++;
    }
    
    return (num8==num5);
}

int main() {
    int n, curNum, curCount, ans=INT_MAX;
    queue<pair<int, int>> q;
    cin >> n;

    int len = to_string(n).length();
    if (len%2==1) len++;
    
    q.push({8, 1});
    q.push({5, 1});

    while (!q.empty()) {
        curNum = q.front().first;
        curCount = q.front().second;
        q.pop();

        if (curCount == len) {
            if (curNum >= n && valid(curNum)) {
                ans = min(ans, curNum);
            }
        }
        
        else {
            curNum = curNum * 10;
            q.push({curNum+8, curCount+1});
            q.push({curNum+5, curCount+1});
        }
    }

    cout << ans;
}