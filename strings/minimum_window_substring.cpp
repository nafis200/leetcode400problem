

// 0 - 3 months:
// Microsoft (7) — Amazon (5) — LinkedIn (4) — Google (3) — Meta (3) — IBM (3) —
// Oracle (3) — Lyft (3) — Bloomberg (2)

// 0 - 6 months:
// Adobe (2) — TikTok (2) — Snowflake (2) — Snap (2)

// 6 months ago:
// Airbnb (11) — Uber (7) — SoFi (6) — Zopsmart (6) — Yandex (5) — Walmart Labs
// (4) — Salesforce (4) — Infosys (3) — Zeta (3) — Apple (3)

// problem Link:
// https://leetcode.com/problems/minimum-window-substring/description/

#include <bits/stdc++.h>
using namespace std;

// time o(n^2) space o(1)

// string minWindow(string s, string t) {
//     int n = s.size();
//     int minLen = INT_MAX;
//     string ans = "";

//     unordered_map<char, int> target;

//     for (char c : t) {
//         target[c]++;
//     }

//     for (int i = 0; i < n; i++) {
//         unordered_map<char, int> freq;

//         for (int j = i; j < n; j++) {
//             freq[s[j]]++;

//             bool ok = true;

//             for (auto it : target) {
//                 if (freq[it.first] < it.second) {
//                     ok = false;
//                     break;
//                 }
//             }

//             if (ok) {
//                 if (j - i + 1 < minLen) {
//                     minLen = j - i + 1;
//                     ans = s.substr(i, minLen);
//                 }
//             }
//         }
//     }

//     return ans;
// }

// s = bbbbba
// t = bba

// time o(n + m) space o(1)

string minWindow(string s, string t) {
  int n = s.size();
  unordered_map<char, int> need;
  for (auto it : t) {
    need[it]++;
  }
  int required = need.size();

  int form = 0;
  int left = 0, start = 0;

  unordered_map<char, int> window;
  int minLen = INT_MAX;
  for (int right = 0; right < n; right++) {
    char c = s[right];
    window[c]++;
    if (need.count(c) && window[c] == need[c]) {
      form++;
    }
    while (form == required) {
      if (right - left + 1 < minLen) {
        start = left;
        minLen = right - left + 1;
      }
      char ch = s[left];
      window[ch]--;
      if (window.count(ch) && window[ch] < need[ch]) {
        form--;
      }
      left++;
    }
  }
  if (minLen == INT_MAX) {
    return "";
  }
  return s.substr(start, minLen);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s, t;

  s = "ABBC";
  t = "ABC";

  string ans = minWindow(s, t);

  cout << ans << "\n";
}