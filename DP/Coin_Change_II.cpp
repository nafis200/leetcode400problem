// 0 - 3 months:
// Google (5) — Meta (2) — Amazon (2)

// 0 - 6 months:
// Bloomberg (2)

// 6 months ago:
// Microsoft (13) — TikTok (3) — Apple (2) — Morgan Stanley (2) — Zoho (2) — DE
// Shaw (2) — PornHub (2)

// https://leetcode.com/problems/coin-change-ii/

#include <bits/stdc++.h>
using namespace std;

// time is o(n * amount^2)

int n;

vector<vector<int>> memo;

// int dp(int i, int sum, int amount, vector<int>& coins) {
//   if (i == n) {
//     if (sum == amount) {
//       return 1;
//     }
//     return 0;
//   }
//   if (sum > amount) {
//     return 0;
//   }
//   if (memo[i][sum] != -1) {
//     return memo[i][sum];
//   }
//   int ans = 0;
//   for (int k = 0; sum + k * coins[i] <= amount; k++) {
//     int newSum = sum + k * coins[i];
//     ans += dp(i + 1, newSum, amount, coins);
//   }
//   return memo[i][sum] = ans;
// }



// time o(amount * n)

int dp(int i, int sum, int amount, vector<int>& coins) {
  if (i == n) {
    if (sum == amount) {
      return 1;
    }
    return 0;
  }
  if (sum > amount || i == n) {
    return 0;
  }
  if (memo[i][sum] != -1) {
    return memo[i][sum];
  }
  
  int take = 0;
  int skip = 0;

  take = dp(i, sum + coins[i], amount, coins);
  skip = dp(i + 1, sum, amount, coins);

  return memo[i][sum] = take + skip;
}

int change(int amount, vector<int>& coins) {
  n = coins.size();
  memo.assign(n + 1, vector<int>(amount + 1, -1));
  int ans = dp(0, 0, amount, coins);
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int amount = 5;
  vector<int> coins = {1, 2, 5};
  int ans = change(amount, coins);
  cout << ans << "\n";
}