 
 	
// 0 - 3 months:
// DoorDash (4)

// 0 - 6 months:
// Meta (5)

// 6 months ago:
// Amazon (12) — Google (8) — TikTok (8) — Uber (7) — Visa (4) — Microsoft (3) — Bloomberg (2) — Snowflake (2) — eBay (2) — Spotify (2)

#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

bool isValid(int i, int j, vector<vector<int>>& grid){
    if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != -1){
        return true;
    }
    return false;
}


void islandsAndTreasure(vector<vector<int>>& grid) {
   n = grid.size();
   m = grid[0].size();   
   queue<pair<int,int>>q;
   for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
        if(grid[i][j] == 0){
            q.push({i, j});
        }
    }
   }  
   while(!q.empty()){
      auto x = q.front();
      q.pop();
      int i = x.first;
      int j = x.second;
      for(int k = 0; k < 4; k++){
         int next_i = i + dx[k];
         int next_j = j + dy[k];
         if(isValid(next_i, next_j, grid)){
            if(grid[next_i][next_j] > grid[i][j] + 1){
                grid[next_i][next_j] = grid[i][j] + 1;
                q.push({next_i, next_j});
            }
         }
      }
   }
}


int32_t main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> grid = {
        {2147483647, -1, 0, 2147483647},
        {2147483647, 2147483647, 2147483647, -1},
        {2147483647, -1, 2147483647, -1},
        {0, -1, 2147483647, 2147483647}
    };

    islandsAndTreasure(grid);

    for(auto it : grid){
        for(auto i : it){
            cout << i << " ";
        }
        cout << "\n";
    }

}