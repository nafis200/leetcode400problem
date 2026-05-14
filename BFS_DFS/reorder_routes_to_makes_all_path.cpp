 // 0 - 3 months:
// Google (2) — TikTok (2)

// 0 - 6 months:
// Amazon (4) — Microsoft (3)

// 6 months ago:
// Bloomberg (2) — DRW (2)

// Problem_Link: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/

#include<bits/stdc++.h>
using namespace std;

// time o(v + e) = o(n) space o(n)

// E = V - 1

// O(V + E)
// = O(V + (V - 1))
// = O(2V - 1) o(v) o (n)

int DFS(vector<vector<pair<int,int>>>&g, vector<bool>&visited, int node){
    visited[node] = true;
    int change = 0;
    for(auto i : g[node]){
        int neighbour = i.first;
        int cost = i.second;
        
        if(!visited[neighbour]){
            change += cost;
            change += DFS(g, visited, neighbour);
        }
    }
    return change;
}

int minReorder(int n, vector<vector<int>>& connections) {
     vector<vector<pair<int,int>>>g(n);
     for(int i = 0; i < connections.size(); i++){
        int u = connections[i][0];
        int v = connections[i][1];
        g[u].push_back({v, 1});
        g[v].push_back({u, 0});
     }
 
     vector<bool>visited(n,false);

     int ans = DFS(g, visited, 0);
     return ans;
     
}
int32_t main(){
  
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 6;
    vector<vector<int>> connections = {
    {0, 1},
    {1, 3},
    {2, 3},
    {4, 0},
    {4, 5}
};
 int ans = minReorder(n, connections);
 cout << ans << "\n";
}