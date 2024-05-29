#include <iostream>
using namespace std;

int main() {
    int max = 0;
    int array[] = {1, 2, 3, 4, 5, 6};
    for(int i=0; i< sizeof(array)/sizeof(array[0]); i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    cout << max << endl;
    return 0;
    }
