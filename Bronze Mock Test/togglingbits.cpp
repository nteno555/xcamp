#include <iostream>
using namespace std;

int main() {
    int cases, n, k, ans, lastFound;
    string bits;
    bool found;
    cin >> cases;
    for (int i=0; i<cases; i++) {
        cin >> n >> k >> bits;
        ans = 0;
        found = false;
        lastFound = -1;
        for (int j=0; j<n; j++) {
            if (j-lastFound >= k && lastFound != -1) {
                found = false;
            }
            if (bits[j] == '1') {
                if (found==false) {
                    lastFound = j;
                    found = true;
                }
                else {
                    ans++;
                }
            }
        }

        cout << ans << endl;
    }
}