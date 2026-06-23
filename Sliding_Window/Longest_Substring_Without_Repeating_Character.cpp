// 0 - 3 months:
// Google (31) — Amazon (26) — Microsoft (15) — Bloomberg (10) — TikTok (10) —
// Meta (7) — Turing (4) — IBM (3) — Infosys (3) — Apple (3)

// 0 - 6 months:
// Oracle (12) — Goldman Sachs (6) — Adobe (4) — Zoho (4) — Nvidia (4) —
// Accenture (4) — Yandex (4) — EPAM Systems (3) — Juspay (3) — Tesla (3)

// 6 months ago:
// Yahoo (25) — Walmart Labs (18) — Uber (15) — Tinkoff (14) — Spotify (10) —
// Agoda (8) — Flipkart (7) — J.P. Morgan (6) — eBay (6) — Salesforce (6)

// Problem_Link:
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

#include <bits/stdc++.h>
using namespace std;
// abcab
// Time o(n) space o(26) o(1)
int lengthOfLongestSubstring(string s) {
  unordered_map<char, int> mp;
  int l = 0, r = 0;
  int ans = 0;
// abba
  for (r = 0; r < s.size(); r++) {
    if (mp.count(s[r])) {
      if(mp[s[r]] >= l){
         l = mp[s[r]] + 1;
      }
    }

    int len = r - l + 1;
    mp[s[r]] = r;
    ans = max(ans, len);
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s = "abba";
  int ans = lengthOfLongestSubstring(s);
  cout << ans << "\n";
}