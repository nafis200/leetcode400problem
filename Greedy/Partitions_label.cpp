// 0 - 6 months:
// Amazon (3)

// 6 months ago:
// Google (7) — Meta (6) — Bloomberg (6) — Microsoft (5) — LinkedIn (4) — Yandex
// (2) — InMobi (2)

// Problem_Link: https://leetcode.com/problems/partition-labels/description/

#include <bits/stdc++.h>
using namespace std;
vector<int> partitionLabels(string s) {
  int n = s.size();
  vector<int> ans;
  unordered_map<char, int> mp;
  for (int i = 0; i < n; i++) {
    mp[s[i]] = i;
  }
  int l = 0;
  int r = mp[s[l]];
  for(int i = 0; i < n; i++){
     r = max(r, mp[s[i]]);
     if(i == r){
        int len = r - l + 1;
        ans.push_back(len);
        l = i + 1;
     }
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s = "ababcbacadefegdehijhklij";
  vector<int> ans = partitionLabels(s);
  for(auto i : ans){
    cout << i << " ";
  }
}
