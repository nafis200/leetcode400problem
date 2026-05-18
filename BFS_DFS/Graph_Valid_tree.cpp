
// 0 - 3 months:
// Snowflake (3)

// 0 - 6 months:
// LinkedIn (3) — Google (2)

// 6 months ago:
// Microsoft (6) — Meta (5) — Amazon (4) — TikTok (2) — Zenefits (2)

// problem_Link: https://neetcode.io/problems/valid-tree/question

#include <bits/stdc++.h>
using namespace std;

bool ok = true;

void DFS(int node, int par, vector<vector<int>>& g, vector<bool>& vis) {
  vis[node] = true;
  if (!ok) {
    return;
  }
  for (auto i : g[node]) {
    if (vis[i] == false) {
      DFS(i, node, g, vis);
    } else if (vis[i] == true && i != par) {
      ok = false;
      return;
    }
  }
}

bool validTree(int n, vector<vector<int>>& edges) {
  vector<vector<int>> graph(n + 5);
  vector<bool> vis(n + 5, false);
  for (int i = 0; i < (int)edges.size(); i++) {
    int u = edges[i][0];
    int v = edges[i][1];
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  int componnets = 0;
  
  for(int i = 0; i < n; i++){
     if(vis[i] == false){
        DFS(0, -1, graph, vis);
        componnets++;
     }
  }
  if(componnets > 1){
     ok = false;
  }
  
  return ok;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n = 4;
  vector<vector<int>> edges = {
      {0, 1},{2, 3}
  };

  bool ans = validTree(n, edges);
  cout << ans << "\n";
}