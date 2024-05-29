#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, person, temp, currentIndex, time, ticketsRemaining;
    queue<int> q;

    cin >> n >> person;
    for (int i=0; i<n; i++) {
        cin >> temp;
        if (i==person) ticketsRemaining = temp;
        q.push(temp);
    }

    while (ticketsRemaining > 0) {
        if (currentIndex == 0) {
            if (ticketsRemaining==1) {
                cout << time+1;
                return;
            }
            ticketsRemaining--;
            q.pop();
            q.push(ticketsRemaining);
            currentIndex = q.size()-1;
        }
        else {
            temp = q.front();
            if (temp == 1) {
                q.pop();
            }
            else {
                q.pop;
                q.push(temp-1);
            }
            currentIndex--;
        }
        time++;
    }
}