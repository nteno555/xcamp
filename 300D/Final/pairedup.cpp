#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

int main() {
	int N;
	vector<pii> V;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num_cows, milk_time;
		cin >> num_cows >> milk_time;
		V.push_back(pii(milk_time, num_cows));
	}
	sort(V.begin(), V.end());
	int M = 0, left = 0, right = N - 1;

	while (left <= right) {
		int sub = min(V[left].second, V[right].second);
		if (left == right) sub /= 2;
		M = max(M, V[left].first + V[right].first);
		V[left].second -= sub;
		V[right].second -= sub;

		if (V[left].second == 0) left++;
		if (V[right].second == 0) right--;
	}
	cout << M << "\n";
}