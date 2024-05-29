#include <deque>
#include <stack>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string parantheses;
int ans=0;
deque<char> q;

void alg() {
    stack<char> s;
    for (int i=1; i<parantheses.length(); i++) {
        if (q.empty()) q.push_back(parantheses[i]);
        else if (parantheses[i] == ')' && q.back() == '(') q.pop_back();
        else if (parantheses[i] == ')' && q.front() == '(') q.pop_back();
        else q.push_back(parantheses[i]);
    }

    for (int i=0; i<q.size(); i=i+2) {
        if (q[i] == q[i+1]) {
            ans++;
        }
        else {
            ans = ans + 2;
        }
    }
    return;
}

int main() {
    cin >> parantheses;
    
    q.push_back(parantheses[0]);

    alg();

    cout << ans;
}