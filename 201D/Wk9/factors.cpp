#include <iostream>
#include <math.h>
using namespace std;

int n;

void dfs(int num) {
    if (sqrt(num) < 2) {
        return;
    }
    for (int i=2; i<n; i++) {
        if (num%i == 0) {
            dfs(i);
        }
    }
}

int main(){
    cin >> n;

    return 0;
}