// 0 - 3 months:
// Amazon (4) — Oracle (2)

// 0 - 6 months:
// Google (2) — Microsoft (2)

// 6 months ago:
// Tinkoff (6) — Walmart Labs (4) — Graviton (3) — Nvidia (2) — Expedia (2)

// problem_Link: https://leetcode.com/problems/keys-and-rooms/description/

#include<bits/stdc++.h>
using namespace std;

// time o(v + e) space o(n)

void DFS(vector<vector<int>>& rooms,vector<bool>&visited, int node){
     visited[node] = true;
     vector<int>g = rooms[node];
     for(auto it : g){
         if(!visited[it]){
            DFS(rooms,visited, it);
         }
     }
}

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    vector<bool> visited(n, false);
    DFS(rooms, visited, 0);
    bool ans = true;

   

    for(int i = 0; i < n; i++){
        if(visited[i] == false){
            ans = false;
        }
    }
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> rooms = {{1}, {2}, {3}, {}};

    bool ans = canVisitAllRooms(rooms);

    cout << ans << "\n";
}