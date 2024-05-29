#include <iostream>
using namespace std;

int main() {
    int l1=0, l2=0, inp=0, p1=0, p2=0, counter=0;
    int arr1[100], arr2[100], final[200];
    cin >> inp;
    while (inp != -1) {
        arr1[l1] = inp;
        l1++;
        cin >> inp;
    }
    cin >> inp;
    while (inp != -1) {
        arr2[l2] = inp;
        l2++;
        cin >> inp;
    }
    
    while (p1 < l1 && p2 < l2) {
        if (arr1[p1] >= arr2[p2]) {
            final[counter] = arr1[p1];
            p1++;
        }
        else {
            final[counter] = arr2[p2];
            p2++;
        }
        counter++;
    }
    if (p1 != l1) {
        while (p1 < l1) {
            final[counter] = arr1[p1];
            p1++;
            counter++;
        }
    }
    else if (p2 != l2) {
        while (p2 < l2) {
            final[counter] = arr2[p2];
            p2++;
            counter++;
        }
    }
    for (int i=0; i<l1+l2; i++) {
        cout << final[i] << ' ';
    }
    
    return 0;
}