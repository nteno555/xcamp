#include <iostream>

using namespace std;

int n, k, count;
int arr[100];
int vis[100];

// loops from 1 to n, and stops at level n
void luckybox(int level){
    if (level > n){
        for (int i = 1; i <= n; i++){
            if (count == k) {
                cout << arr[i] << " ";
            }
        }
        count++;
        return;
    } else {
        for (int i = 1; i <= n; i++){
            if (vis[i] == 0){
                vis[i] = 1;
                arr[level] = i; 
                luckybox(level + 1);
                vis[i] = 0;
            }
        }
    }
}

int main()
{
    cin >> n >> k;
    luckybox(1);
}