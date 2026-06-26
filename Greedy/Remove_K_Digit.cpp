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
  string st;

  for (char c : num) {
    while (!st.empty() && k > 0 && st.back() > c) {
      st.pop_back();
      k--;
    }

    st.push_back(c);
  }

  while (k > 0) {
    st.pop_back();
    k--;
  }

  int i = 0;
  while (i < st.size() && st[i] == '0') {
    i++;
  }

  st = st.substr(i);

  if (st.empty()) {
    return "0";
  }

  return st;
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