// 0 - 6 months:
// General Motors (4) — LinkedIn (2)

// 6 months ago:
// Amazon (22) — Google (7) — Meta (4) — Apple (2) — TikTok (2) — X (2)

// problem_Link: https://neetcode.io/problems/count-connected-components/question

#include<bits/stdc++.h>
using namespace std;

void DFS(int node,vector<bool>&vis, vector<vector<int>>&g){
    vis[node] = true;
    for(auto v : g[node]){
        if(vis[v] == false){
            DFS(v,vis,g);
        }
    }
}

int countComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>>g(n + 1);
    for(auto x : edges){
        int u = x[0];
        int v = x[1];
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool>vis(n + 1, false);
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(vis[i] == false){
            ans++;
            DFS(i, vis,g);
        }
    }
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> edges = {
    {0, 1},
    {1, 2},
    {2, 3},
    {3, 4}
};
int n = 5;

int ans = countComponents(n, edges);
cout << ans << "\n";
}