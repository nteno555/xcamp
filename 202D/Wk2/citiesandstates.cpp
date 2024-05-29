#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cc=0, ans=0;
    map<string, string> m;
    string city, state, combos[200001];

    cin >> n;
    
    for (int i=0; i<n; i++) {
        cin >> city >> state;
        city = city.substr(0, 2);

        if (city == state) continue;
        else {
            m.insert(pair<string, string>(city+' '+state, state+' '+city));
            combos[cc] = state+' '+city;
            cc++;
        }
    }

    for (int i=0; i<cc; i++) {
        ans = ans + m.count(combos[i]);
    }

    cout << ans/2;
}