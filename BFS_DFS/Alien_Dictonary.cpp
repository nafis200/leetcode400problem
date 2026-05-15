// 0 - 3 months:
// Meta (11) — Uber (6) — Google (4) — Amazon (3) — Microsoft (2) — TikTok (2)

// 0 - 6 months:
// Airbnb (3) — Wix (2) — X (2) — Snap (2) — Pocket Gems (2)

// 6 months ago:
// Bloomberg (4) — Oracle (2) — Flipkart (2) — Citadel (2) — PhonePe (2)

// problem_Link: https://leetcode.com/problems/alien-dictionary/description/

// https://leetcode.com/discuss/post/248131/microsoft-interview-round-1-alien-dictio-yu0z/

#include <bits/stdc++.h>
using namespace std;

// valid

// abc
// de

// valid
// ab
// abc

// invalid
// abc
// ab

string alienOrder(vector<string>& words) {
  unordered_map<char, vector<char>> g;

  unordered_map<char, int> indeg;

  unordered_map<char, bool>visited;

  for (auto s : words) {
    for (auto i : s) {
      indeg[i] = 0;
      visited[i] = false;
    }
  }

  for (int i = 1; i < words.size(); i++) {
    string a = words[i - 1];
    string b = words[i];

    int len = min(a.size(), b.size());

    if (a.size() > b.size() && a.substr(0, len) == b) {
      return "";
    }

    for (int j = 0; j < len; j++) {
      if (a[j] != b[j]) {
        indeg[b[j]]++;
        g[a[j]].push_back(b[j]);
        break;
      }
    }
  }
  vector<char>ans,z;
  for(auto it : indeg){
    if(it.second == 0){
        z.push_back(it.first);
        visited[it.first] = true;
    }
  }
  while(ans.size() < indeg.size() && !z.empty()){
      char x = z.back();
      z.pop_back();
      ans.push_back(x);
      for(auto it : g[x]){
         indeg[it]--;
         if(indeg[it] == 0 && visited[it] == false){
            z.push_back(it);
            visited[it] = true;
         }
      }
  }
  if(ans.size() != indeg.size()){
    return "";
  }
  string s;
  for(auto it : ans){
     s += it;
  }
  return s;
}

int32_t main() {
  vector<string> words = {"wrt", "wrf", "er", "ett", "rftt"};
  string ans = alienOrder(words);

  cout << ans << "\n";
}