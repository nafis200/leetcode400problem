
// 0 - 3 months:
// Google (5) — Amazon (2)

// 0 - 6 months:
// Salesforce (2)

// 6 months ago:
// Netflix (5) — Microsoft (4) — Bloomberg (4) — Meta (3) — TikTok (2) — Akuna
// Capital (2) — Yahoo (2)

// Problem_Link: https://leetcode.com/problems/network-delay-time/description/

#include <bits/stdc++.h>
using namespace std;
// Time (v + e)loge
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
  vector<vector<pair<int, int>>> g(n + 1);
  for (auto i : times) {
    int u = i[0];
    int v = i[1];
    int w = i[2];
    g[u].push_back({v, w});
  }
  vector<int> dis(n + 1, INT_MAX);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  pq.push({0, k});
  dis[k] = 0;
  while (!pq.empty()) {
    auto x = pq.top();
    pq.pop();
    int cost = x.first;
    int node = x.second;

    for (auto v : g[node]) {
      int neighbor = v.first;
      int weight = v.second;
      if (dis[neighbor] > dis[node] + weight) {
        dis[neighbor] = dis[node] + weight;
        pq.push({dis[neighbor], neighbor});
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, dis[i]);
  }
  if (ans == INT_MAX) {
    ans = -1;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};

  int n = 4;
  int k = 2;
  cout << networkDelayTime(times, n, k) << "\n";

  return 0;
}