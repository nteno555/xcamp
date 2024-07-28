#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo;
vector<int> cards;

int dp(int i, int j){
  if (i == j-1){
    return 0;
  }

  if (memo[i][j] != -1){
    return memo[i][j];
  }

  int result = INT_MAX;
  for(int k = i+1; k < j; k++){
    result = min(result, dp(i, k) + dp(k, j) + cards[i] * cards[k] * cards[j]);
  }
  memo[i][j] = result;
  return result;
}

int main(){
  int n, input;
  cin >> n;
  cards.push_back(0);
  for(int i = 0; i < n; i++){
    cin >> input;
    cards.push_back(input);
  }
  memo.resize(n+1, vector<int>(n+1, -1));
  cout << dp(1, n) << endl;;
}

