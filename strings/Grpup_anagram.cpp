// 0 - 3 months:
// Amazon (28) — Google (12) — Meta (7) — Microsoft (7) — Oracle (5) —
// Salesforce (5) — Bloomberg (4) — Nvidia (4) — Affirm (4) — Goldman Sachs (3)

// 0 - 6 months:
// Apple (10) — Uber (5) — Anduril (5) — Walmart Labs (4) — Atlassian (4) —
// TikTok (3) — athenahealth (3) — tcs (2) — Adobe (2) — Wayfair (2)

// 6 months ago:
// Yandex (34) — Zoho (15) — Yahoo (12) — ServiceNow (11) — EPAM Systems (9) —
// PayPal (8) — BP (6) — J.P. Morgan (5) — Visa (5) — eBay (4)

// time o(n * klogk) space o(n * k)

// problem Link: https://leetcode.com/problems/group-anagrams/description/

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
  map<string, vector<string>> mp;
  for (auto it : strs) {
    string s = it;
    sort(s.begin(), s.end());
    mp[s].push_back(it);
  }

  vector<vector<string>> st;

  for (auto it : mp) {
    vector<string> v;
    for (auto i : it.second) {
      v.push_back(i);
    }
    st.push_back(v);
  }
  return st;
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<string> str = {"eat", "tea", "tan", "ate", "nat", "bat"};

  vector<vector<string>> ans = groupAnagrams(str);

  for (auto it : ans) {
    cout << "[";
    for (auto v : it) {
      cout << v << " ";
    }
    cout << "]";
  }
}