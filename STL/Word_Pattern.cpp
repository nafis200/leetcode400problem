// 0 - 6 months: Google (2) — Meta (2) — Zoho (2) — Uber (2) — Dropbox (2)
// 6 months ago: Amazon (11) — Apple (7) — Adobe (4) — Microsoft (3) — Bloomberg
// (2)

// Problem_Link: https://leetcode.com/problems/word-pattern/description/

#include <bits/stdc++.h>
using namespace std;
bool wordPattern(string pattern, string s) {
  vector<string> words;
  stringstream ss(s);
  string word;

  while (ss >> word) {
    words.push_back(word);
  }

  if (pattern.length() != words.size()) {
    return false;
  }

  unordered_map<char, string> mp;
  unordered_map<string, char> mp1;

  for (int i = 0; i < pattern.size(); i++) {
    if (mp.find(pattern[i]) != mp.end()) {
      if (mp[pattern[i]] != words[i]) {
        return false;
      }
    }

    if (mp1.find(words[i]) != mp1.end()) {
      if (mp1[words[i]] != pattern[i]) {
        return false;
      }
    }

    mp[pattern[i]] = words[i];
    mp1[words[i]] = pattern[i];
  }

  return true;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string pattern = "abba", s = "dog cat cat dog";

  bool ans = wordPattern(pattern, s);
}