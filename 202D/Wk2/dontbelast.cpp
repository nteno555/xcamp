#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, temp, absMin=INT_MAX, absSecMin = INT_MAX-1, count=0;
    string name, curCow, cows[7] = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
    map<string, int> m;

    m["Bessie"] = 0;
    m["Elsie"] = 0;
    m["Daisy"] = 0;
    m["Gertie"] = 0;
    m["Annabelle"] = 0;
    m["Maggie"] = 0;
    m["Henrietta"] = 0;

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> name >> temp;
        m[name] += temp;
    }

    for (int i=0; i<7; i++) {
        curCow = cows[i];
        if (m[curCow] < absMin) {
            absSecMin = absMin;
            absMin = m[curCow];
        }
        else if (m[curCow] < absSecMin) {
            absSecMin = m[curCow];
        }
    }

    for (int i=0; i<7; i++) {
        curCow = cows[i];
        if (m[curCow] == absSecMin) count++;
        if (count >= 2) {
            cout << "Tie";
            return 0;
        }
    }

    cout << absSecMin;
    return 0;
}