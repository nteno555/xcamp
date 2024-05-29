#include <iostream>
using namespace std;

int n, currStair[1001];

// int stair(int level) {
//     if (level==0) {
//         return 1;
//     }
//     if (level<0) {
//         return 0;
//     }
//     // cout << level << endl;
//     return (stair(level-1) + stair(level-2) + stair(level-3)) % 998244353;
// }
// 782230434

int add(int a, int b) {
    int c = 998244353 - a;
    if (c == b) {
        return 0;
    }
    if (b<c) {
        return a+b;
    }
    else {
        return b-c;
    }
}

void stair(int level) {
    for (int i=level; i<=n; i++) {
        currStair[i] = add(currStair[i-1], currStair[i-2]);
        currStair[i] = add(currStair[i], currStair[i-3]);
        // cout << currStair[i] << endl;
    }
}

int main(){
    cin >> n;
    currStair[0] = 1;
    currStair[1] = 1;
    currStair[2] = 2;
    stair(3);
    cout << (currStair[n]);
    return 0;
}