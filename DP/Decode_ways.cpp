// 0 - 3 months:
// Goldman Sachs (3) — Meta (2) — Amazon (2)

// 0 - 6 months:
// Google (7) — Microsoft (5) — Uber (3) — Apple (2) — TikTok (2) — Graviton (2)

// 6 months ago:
// Commvault (8) — Oracle (6) — Bloomberg (5) — Flipkart (5) — Salesforce (4) —
// Adobe (3) — Zoho (3) — Tesla (3) — J.P. Morgan (2) — Morgan Stanley (2)

#include <bits/stdc++.h>
using namespace std;

// time complexity o(n) space o(n)

// vector<int>memo;
// int n;

// int dp(int i, string &s){
//      if(i == n){
//         return 1;
//      }
//      if(s[i] == '0'){
//         return 0;
//      }
//      if(memo[i] != -1){
//         return memo[i];
//      }
//      int ways = 0;
//      ways += dp(i + 1, s);
//      if(i + 1 < n){
//         int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
//         if(num >= 10 && num <= 26){
//             ways += dp(i + 2, s);
//         }
//      }
//    return memo[i] = ways;
// }

//  int numDecodings(string s) {
//    n = s.size();
//    memo.assign(n + 1, - 1);
//    int ans = dp(0, s);
//    return ans;
//  }

// time o(n) space o(1)

int numDecodings(string s) {
  int n = s.size();
  int next1 = 1;
  int next2 = 0;
  // dp[i] = dp[i + 1] + dp[i + 2]
  // cur   = next1     + next2

  // dp[i - 1] = dp[i] + dp[i + 1];
  // next1 = cur
  // next2 = next1

  int cur = 0;
  for (int i = n - 1; i >= 0; i--) {
    cur = 0;
    if (s[i] != '0') {
      cur += next1;
      if (i + 1 < n) {
        int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
        if (num >= 10 && num <= 26) {
          cur += next2;
        }
      }
    }

    next2 = next1;
    next1 = cur;
  }
  return cur;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s = "226";
  int ans = numDecodings(s);
  cout << ans << "\n";
}