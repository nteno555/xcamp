#include <iostream>
#include <limits.h>
using namespace std;

int n, m, ans=INT_MAX;
int visited[100001], flights[100002], connections[200001][3];

void bfs() {
}

int main() {
    int n1, n2, n3;
    cin >> n >> m;

    flights[0] = 0;

    for (int i=1; i<=n; i++) {
        flights[i] = -1;
    }

    for (int i=1; i<=m; i++) {
        cin >> n1 >> n2 >> n3;
        if (n1==1) {
            flights[n2] = min(n3, flights[n2]);
        }
        else {
            connections[i][0] = n1;
            connections[i][1] = n2;
            connections[i][2] = n3;
            m--;

        }
    }


}