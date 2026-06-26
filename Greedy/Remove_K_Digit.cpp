// 0 - 3 months:
// Google (3) — Amazon (2) — Deloitte (2)

// 0 - 6 months:
// Meta (2) — Bloomberg (2) — Adobe (2) — PhonePe (2)

// 6 months ago:
// Microsoft (16) — Zopsmart (4) — Coupang (4) — TikTok (3) — Snowflake (3) —
// Josh Technology (3) — Zeta (2) — Oracle (2) — ByteDance (2) — Walmart Labs
// (2)

// Problem_Link: https://leetcode.com/problems/remove-k-digits/description/

//  1 2 2 9

#include <bits/stdc++.h>
using namespace std;
string removeKdigits(string num, int k) {
  string ans = "";
  int n = (int)num.size();
  for (int i = 0; i < n; i++) {
    if (ans.empty()) {
      ans.push_back(num[i]);
    } else {
      if (k > 0 && ans.back() > num[i]) {
        k--;
        ans.pop_back();
      }
      ans.push_back(num[i]);
    }
  }
  while(k > 0){
     k--;
     ans.pop_back();
  }
  if(ans.empty()){
     ans = "0";
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string num = "222";
  int k = 3;
  string ans = removeKdigits(num, k);
  cout << ans << "\n";
}