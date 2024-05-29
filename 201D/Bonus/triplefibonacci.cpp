#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int fibonacci[n];
    fibonacci[0] = 1;
    fibonacci[1] = 1;
    fibonacci[2] = 1;
    for (int i=3; i<n; i++) {
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2] + fibonacci[i-3];
    }
    cout << fibonacci[n-1];
    return 0;
}