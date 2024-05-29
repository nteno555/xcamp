#include <bits/stdc++.h>
using namespace std;

struct State {
    string s;
    int count;
}

struct Visited {
    bool visitedBy1;
    bool visitedBy2;
}

bool valid(string s1, string s2) {
    int mistakes = 0, j=0, i=0;
    if (s1.length() == s2.length()) {
        for (int i=0; i<s1.length(); i++) {
            if (s1[i] != s2[i]) mistakes++;
        }
        if (mistakes > 1) return false;
        else return true;
    }
    else if (s1.length() - s2.length() == -1) {
        while (i < s1.length() && j < s2.length()) {
            if (s1[i] != s2[j] && mistakes != 1) {
                mistakes++;
                j+=2;
                i++;
            }
            else if (mistakes == 1) return false;
            i++;
            j++;
        }
        return true;
    }
    else if (s1.length()- s2.length() == 1) {
        while (i<s1.length() && j<s2.length()) {
            if (s1[i] != s2[j] && mistakes != 1) {
                mistakes++;
                i+=2;
                j++;
            }
            else if(mistakes == 1) return false;
            i++;
            j++;
        }
    }
    else {
        return false;
    }
}

int main() {
    string word1, word2, temp, curString1, curString2;
    map<string, bool> m;
    queue<State> q1;
    queue<State> q2;
    int n, curCount1, curCount2;

    cin >> word1 >> word2 >> n;

    for (int i=0; i<n; i++) {
        cin >> temp;
        m.insert({temp, {false, false}});
    }

    State start = {word1, 0};
    State end = {word2, 0};

    q1.push(start);
    q2.push(end);

    while (!q1.empty() && !q2.empty()) {
        curString1 = q1.front().s;
        curCount1 = q1.front().count;
        curString2 = q2.front().s;
        curCount2 = q2.front().count;

        q1.pop();
        q2.pop();
        
    }
}