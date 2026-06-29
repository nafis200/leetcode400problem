// 0 - 3 months:
// Google (2)

// 0 - 6 months:
// Meta (2) — Amazon (2)

// 6 months ago:
// TikTok (5) — Uber (5) — Microsoft (3) — Nutanix (2) — Directi (2)

#include <bits/stdc++.h>
using namespace std;

// Time o(n^2logn) space o(n)

int minCostConnectPoints(vector<vector<int>>& points) {
  int ans = 0;

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  //   cost, node
  pq.push({0, 0});
  int n = points.size();
  vector<bool> vis(n, false);
  while (!pq.empty()) {
    auto x = pq.top();
    pq.pop();

    int cost = x.first;
    int node = x.second;
    if (vis[node]) {
      continue;
    }
    vis[node] = true;
    ans += cost;
    for (int v = 0; v < n; v++) {
      if (!vis[v]) {
        int cost_distance = abs(points[v][0] - points[node][0]) +
                            abs(points[v][1] - points[node][1]);
        pq.push({cost_distance, v});
      }
    }
  }

  return ans;
}

int32_t main() {}