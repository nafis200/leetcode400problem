// 0 - 6 months:
// Meta (5) — Amazon (5) — Google (3) — Bloomberg (2)

// 6 months ago:
// Microsoft (13) — Apple (7) — Adobe (6) — Paytm (4) — TikTok (3) — Nvidia (2)
// — Yahoo (2)

// Problem_Link: https://algo.monster/liteproblems/340

#include <bits/stdc++.h>
using namespace std;

int LongestSubstring(string s, int k) {
  map<char, int> mp;
  int ans = 0;
  int l = 0, r = 0;
  for (r = 0; r < s.size(); r++) {
    mp[s[r]]++;
    while (mp.size() > k) {
      mp[s[l]]--;
      if (mp[s[l]] == 0) mp.erase(s[l]);
      l++;
    }
    int len = r - l + 1;
    ans = max(ans, len);
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s = "abaccc";
  int k = 2;
  int ans = LongestSubstring(s, k);
  cout << ans << "\n";
}