// 0 - 3 months:
// Amazon (10) — Google (4) — Microsoft (3) — Oracle (3) — TikTok (3) — Meta (2)
// — Intuit (2) — PayPal (2) — Datadog (2) — Affirm (2)

// 0 - 6 months:
// Bloomberg (6) — Infosys (2) — Adobe (2) — Apple (2) — Pinterest (2) —
// Accenture (2) — Salesforce (2)

// 6 months ago:
// Yahoo (12) — Uber (6) — Airbnb (3) — Agoda (3) — Capital One (3) — ConsultAdd
// (3) — J.P. Morgan (2) — tcs (2) — Walmart Labs (2) — EPAM Systems (2)

// Problem_Link: https://leetcode.com/problems/coin-change/description/

#include <bits/stdc++.h>
using namespace std;

// time o(n * amount) space o(n * amount)

int n;
vector<vector<int>> memo;

// int dp(vector<int>& coins, int amount, int i){
//     if(amount == 0 && i == n){
//         return 0;
//     }
//     if(amount < 0 || i == n){
//         return 1e9;
//     }
//     if(memo[i][amount] != -1){
//         return memo[i][amount];
//     }
//     int ans = 1e9;
//     ans = dp(coins, amount, i + 1);
//     if(amount - coins[i] >= 0){
//         ans = min(ans, dp(coins, amount - coins[i], i) + 1);
//     }
//     return memo[i][amount] = ans;
// }

// int coinChange(vector<int>& coins, int amount) {
//     n = coins.size();
//     memo.assign(n + 5, vector<int>(amount + 5, -1));
//     int ans = dp(coins, amount, 0);
//     if(ans == 1e9){
//         ans = -1;
//     }
//     return ans;
// }

int coinChange(vector<int>&coins, int amount){
    const int INF = 1e9;
    vector<int>dp(amount + 5, INF);
    dp[0] = 0;
    for(int a = 1; a <= amount; a++){
        for(auto coin : coins){
            if(a - coin >= 0){
                dp[a] = min(dp[a], dp[a - coin] + 1);
            }
        }
    }
    if(dp[amount] == INF){
        return -1;
    }
    return dp[amount];
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {2};
  int amount = 3;
  int ans = coinChange(nums, amount);

  cout << ans << "\n";
}