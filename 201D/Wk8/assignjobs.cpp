#include <iostream>
#include <limits.h>
using namespace std;

int n, ans=INT_MAX, sum=0;
int jobs[21][21];

void dfs(int k, int sum) {
	if (sum >= ans) {
		return;
	}
	if (k > n) {
		ans = min(ans, sum);
	} else {
		for (int j = 1; j <= n; j++) {
			if (!b[j]) {
				b[j] = 1;
				dfs(k + 1, sum + a[k][j]);
				b[j] = 0;
			}
		}
	}
}



int main(){
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> jobs[i][j];
        }
    }

    dfs(0, 0);


}