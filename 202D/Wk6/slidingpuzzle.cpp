#include <bits/stdc++.h>
using namespace std;

struct State {
    int count;
    string cur;
}

string swap(string str, int a, int b) {
    if (a < b) {
        int temp = b;
        b = a;
        a = temp;
    }

    string c = "";
    
    for (int i=0; i<str.length(); i++) {
        if (i==a) {
            c += str[b];
        }
        else if (i==b) {
            c += str[a];
        }
        else {
            c += str[i];
        }
    }
    
    return c;
}

int main() {
    int zi, curCount1;
    string temp, o;
    set<string> vis1;
    set<string> vis2;
    queue<State> q1;
    queue<State> q2;
    cin >> temp;

    State start = {0, temp};
    State end = {0, "123804765"};

    q1.push(start);
    vis1.insert(start.cur);
    q2.push(end);
    vis2.insert(end.cur);

    while (!q1.empty() && !q2.empty()) {
        temp = q.front().cur;
        curCount1 = q.front().count;
        curCount2
        q.pop()

        zi = temp.find('0');

        if (zi>=3) {
            o = swap(zi-3, zi);



            if (!vis1.count(o)) {
                q.push({curCount1+1, o});
            }
        }
    }
}