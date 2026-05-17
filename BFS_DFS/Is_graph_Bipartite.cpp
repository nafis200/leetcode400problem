

// 0 - 3 months:
// Google (3)

// 0 - 6 months:
// Amazon (3) — Microsoft (2) — Samsung (2)

// 6 months ago:
// Meta (7) — Uber (6) — TikTok (5) — Pinterest (4) — Lime (3) — LinkedIn (2) —
// Apple (2)

// Problem_Link: https://leetcode.com/problems/is-graph-bipartite/description/

#include <bits/stdc++.h>
using namespace std;

bool ok = true;

void DFS(vector<vector<int>>& graph, vector<bool>& vis, vector<int>& col,
         int node) {
  vis[node] = true;
  if (!ok) {
    return;
  }
  for (auto i : graph[node]) {
    if (vis[i] == false) {
      col[i] = col[node] ^ 1;
      DFS(graph, vis, col, i);
    } else {
      if (col[i] == col[node]) {
        ok = false;
        return;
      }
    }
  }
}

bool isBipartite(vector<vector<int>>& graph) {
  int n = graph.size();
  vector<bool> vis(n + 1, false);
  vector<int> col(n + 1, 0);
  for (int i = 0; i < graph.size(); i++) {
    if (vis[i] == false) {
      DFS(graph, vis, col, i);
    }
  }
  return ok;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<vector<int>> graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
  bool ans = isBipartite(graph);
  cout << ans << "\n";
}