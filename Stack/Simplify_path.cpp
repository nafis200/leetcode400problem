// 0 - 3 months:
// Meta (50) — Amazon (7) — Visa (5) — Google (3) — Oracle (3) — Capital One (3)

// 0 - 6 months:
// Bloomberg (3) — Patreon (3) — Snowflake (2) — Yandex (2)

// 6 months ago:
// Microsoft (16) — Apple (7) — Tinkoff (5) — Upstart (4) — Adobe (3) — TikTok
// (3) — Gojek (3) — Tesla (2) — Citadel (2) — Roku (2)

// Problem_Link: https://leetcode.com/problems/simplify-path/description/

#include <bits/stdc++.h>
using namespace std;
string simplifyPath(string path) {
  vector<string> st;
  string cur = "";
  int n = path.size();
  for (int i = 0; i <= n; i++) {
    if (path[i] == '/' || i == n) {
      if (cur == "" || cur == ".") {
      } else if (cur == "..") {
        if (!st.empty()) {
          st.pop_back();
        }
      } else {
        st.push_back(cur);
      }
      cur = "";
    } else {
      cur += path[i];
    }
  }

  if(st.empty()){
    return "/";
  }
  string ans = "";

  for(string s : st){
     ans += "/" + s; 
  }
  return ans; 
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string path = "/.../a/../b/c/../d/./";
  cout << simplifyPath(path) << "\n";
}