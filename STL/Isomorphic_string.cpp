// Google (10) — Yandex (5) — Microsoft (4) — Amazon (4) — Bloomberg (4) —
// LinkedIn (3) — Meta (2) 0 - 6 months: Oracle (2) — Remitly (2) 6 months ago:
// Apple (12) — Yahoo (10) — Adobe (9) — Uber (5) — EPAM Systems (3) — Barclays
// (3) — TikTok (2)

// Problem_Link: https://leetcode.com/problems/isomorphic-strings/description/

#include <bits/stdc++.h>
using namespace std;

// Time o(n) space o(n)

bool isIsomorphic(string s, string t) {
  unordered_map<char, int> mp;
  unordered_map<char, int> mp1;
  for (int i = 0; i < s.size(); i++) {
    if (mp.find(s[i]) != mp.end()) {
      if (mp[s[i]] != t[i]) {
        return false;
      }
    }

    if (mp1.find(t[i]) != mp1.end()) {
      if (mp1[t[i]] != s[i]) {
        return false;
      }
    }

    mp[s[i]] = t[i];
    mp1[t[i]] = s[i];
  }
  return true;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s = "f11", t = "b23";

  bool ans = isIsomorphic(s, t);
  cout << ans << "\n";
}