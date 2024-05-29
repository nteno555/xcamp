#include <iostream>
#include <math.h>
using namespace std;

int func(int row) {
    return pow(11, row);
}

int main() {
    int n;
    cin >> n;

    cout << func(n);
}