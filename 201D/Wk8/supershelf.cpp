#include <iostream>
using namespace std;

int n;


void dfs(int k, int sum) //could we not pass sum in here?
{
	if (sum >= ans) {
		return; //why do we stop earlier here?
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
        cin >> a[i];
        b[i] = 0;
    }
    for (int i=0; i<n; i++) {
        dfs(i, 0);
    }
    cout << ans;
    return 0;
}