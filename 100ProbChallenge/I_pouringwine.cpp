#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int c1, c2, c3, ans=-1;
vector<vector<int>> visited;

bool valid(int cup1, int cup2, int cup3) {
    for (int i=0; i<visited.size(); i++) {
        if (cup1 == visited[i][0] && cup2 == visited[i][1] && cup3 == visited[i][2]) {
            return false;
        }
    }
    return (cup1>-1 && cup1<=c1 && cup2>-1 && cup2<=c2 && cup3>-1 && cup3<=c3);
}

bool done(int cup1, int cup2, int cup3) {
    if (cup1 == cup2 && cup3 == 0) {
        return true;
    }
    if (cup1 == cup3 && cup2 == 0) {
        return true;
    }
    if (cup2 == cup3 && cup1 == 0) {
        return true;
    }
    return false;
}

void dfs(int cup1, int cup2, int cup3, int count) {
    if (count > ans && ans != -1) return;
    if (done(cup1, cup2, cup3)) {
        ans = count;
    }
    if (valid(cup1, cup2, cup3)) {
        vector<int> temp{cup1, cup2, cup3};
        visited.push_back(temp);
 
        dfs(cup1-(c2-cup2), c2, cup3, count+1);
        dfs(cup1-(c3-cup3), cup2, c3, count+1);
        dfs(0, cup1+cup2, cup3, count+1);
        dfs(0, cup2, cup1+cup3, count+1);
        // pour to cup 2 & cup 3

        dfs(c1, cup2-(c1-cup1), cup3, count+1);
        dfs(cup1, cup2-(c3-cup3), c3, count+1);
        dfs(cup1+cup2, 0, cup3, count+1);
        dfs(cup1, 0, cup2+cup3, count+1);
        // pour to cup1 & cup 3

        dfs(c1, cup2, cup3-(c1-cup1), count+1);
        dfs(cup1, c2, cup3-(c2-cup2), count+1);
        dfs(cup1+cup3, cup2, 0, count+1);
        dfs(cup1, cup2+cup3, 0, count+1);
        // pour to cup1 and cup 2
        
        visited.pop_back();
    }
    return;
}

int main() {
    cin >> c1 >> c2 >> c3;
    
    dfs(c1, 0, 0, 0);

    if (ans==-1) cout << "NO";
    else cout << ans;
}