// 0 - 3 months:
// Amazon (6) — Google (2)

// 0 - 6 months:
// Bloomberg (4) — Microsoft (2) — Adobe (2) — Two Sigma (2)

// 6 months ago:
// Meta (10) — Sprinklr (4) — Yahoo (4) — DoorDash (2)

// problem_Link: https://leetcode.com/problems/number-of-provinces/description/

#include <bits/stdc++.h>
using namespace std;

// time o(n * n) space o(n)

void DFS(vector<vector<int>>& isConnected, vector<bool>&visited, int node){
     int n = isConnected.size();
     visited[node] = true;
     for(int i = 0; i < n; i++){
         if(visited[i] == false && isConnected[node][i] == 1){
            DFS(isConnected, visited, i);
         }
     }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<bool>vis(n, false);
    int province = 0;
    for(int i = 0; i < n; i++){
        if(vis[i] == false){
           province++;
           DFS(isConnected, vis, i);
        }
    }
    return province;
}

int main() {
  vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};

  int ans = findCircleNum(isConnected);

  cout << ans << "\n";

  return 0;
}