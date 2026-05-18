

// 0 - 3 months:
// Oracle (3) — Amazon (2) — Uber (2)

// 0 - 6 months:
// Meta (4) — ZIP (3) — Microsoft (2) — Bloomberg (2)

// 6 months ago:
// Google (6) — Goldman Sachs (6) — eBay (6) — TikTok (5) — DE Shaw (3) —
// Coupang (2) — CARS24 (2)

// problem_Link: https://leetcode.com/problems/open-the-lock/

// time and space A^N + D

// A = 10 (0 --- 9)  N = 4  and D = 8 state


#include <bits/stdc++.h>
using namespace std;
int openLock(vector<string>& deadends, string target) {
  unordered_set<string> st(deadends.begin(), deadends.end());
  unordered_set<string> vis;
  if (st.count("0000")) {
    return -1;
  }
  vis.insert("0000");
  queue<pair<string, int>> q;
  q.push({"0000", 0});
  while (!q.empty()) {
    auto x = q.front();
    q.pop();
    string dis = x.first;
    int steps = x.second;
    if (dis == target) {
      return steps;
    }
    for (int i = 0; i < 4; i++) {
      string original = dis;
      dis[i] = (dis[i] == '9') ? '0' : dis[i] + 1;
      if (!st.count(dis) && !vis.count(dis)) {
        vis.insert(dis);
        q.push({dis, steps + 1});
      }

      dis = original;
      dis[i] = (dis[i] == '0') ? '9' : dis[i] - 1;

      if (!st.count(dis) && !vis.count(dis)) {
        vis.insert(dis);
        q.push({dis, steps + 1});
      }
       dis = original;
    }
  }
  return -1;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<string> deadends = {"0201", "0101", "0102", "1212", "2002"};

  string target = "0202";
  int ans = openLock(deadends, target);
  cout << ans << "\n";
}