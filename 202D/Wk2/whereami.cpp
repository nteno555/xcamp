#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string houses, temp;
    bool returnable = true;
    set<string> s;

    cin >> n >> houses;

    for (int i=1; i<n; i++) {
        for (int j=0; j<=n-i; j++) {
            temp = houses.substr(j, i);
            if (s.count(temp)) {
                returnable = false;
                break;
            }
            else {
                s.insert(temp);
            }
        }

        if (returnable == true) {
            cout << i << endl;
            return 0;
        }
        
        s.clear();
        returnable = true;
    }

    cout << n << endl;

    return 0;
}