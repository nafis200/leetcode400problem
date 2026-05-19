// 0 - 3 months:
// Google (7) — Meta (2) — Microsoft (2)

// 0 - 6 months:
// Amazon (2)

// 6 months ago:
// DoorDash (4) — DE Shaw (3) — Uber (3) — WeRide (3)

// problem_Link: https://leetcode.com/problems/swim-in-rising-water/

#include <bits/stdc++.h>
using namespace std;

// time (n^2 logn) space o(n^2)
// bfs + binary search

// int n, m;
// vector<int> dx = {1, -1, 0, 0};
// vector<int> dy = {0, 0, 1, -1};

// bool isValid(int i, int j, vector<vector<bool>>&vis,vector<vector<int>>&
// grid, int needTime){
//     if(i >= 0 && i < n && j >= 0 && j < m && !vis[i][j] && grid[i][j] <=
//     needTime){
//         return true;
//     }
//     return false;
// }

// bool CanRach(int needTime,vector<vector<int>>& grid){
//    vector<vector<bool>>vis(n, vector<bool>(m, false));
//    queue<pair<int,int>>q;
//    if(grid[0][0] > needTime){
//     return false;
//    }
//    q.push({0 , 0});
//    vis[0][0] = true;
//    while(!q.empty()){
//      auto x = q.front();
//      q.pop();
//       int i = x.first;
//       int j = x.second;
//       if(i == n - 1 && j == m - 1){
//          return true;
//       }
//       for(int k = 0; k < 4; k++){
//         int next_i = i + dx[k];
//         int next_j = j + dy[k];
//         if(isValid(next_i, next_j, vis, grid, needTime)){
//             vis[next_i][next_j] = true;
//             q.push({next_i, next_j});
//         }
//       }
//    }
//  return false;
// }

// int swimInWater(vector<vector<int>>& grid) {
//      n = grid.size();
//      m = grid[0].size();
//      int low = 0, high = 1e9;
//      int ans = 0;
//      while(low <= high){
//         int mid = (high + low) / 2;
//         if(CanRach(mid, grid)){
//             ans = mid;
//             high = mid - 1;
//         }
//         else{
//             low = mid + 1;
//         }
//      }
//      return ans;
// }

// Dijistra

int n, m;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        pq.push({grid[0][0], 0, 0});

        while(!pq.empty()) {

            auto x = pq.top();
            pq.pop();

            int cost = x[0];
            int i = x[1];
            int j = x[2];

            if(vis[i][j]) continue;
            vis[i][j] = true;

            if(i == n-1 && j == m-1) {
                return cost;
            }

            for(int k=0;k<4;k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];

                if(ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj]) {

                    int newCost = max(cost, grid[ni][nj]);
                    pq.push({newCost, ni, nj});
                }
            }
        }

        return -1;
    }
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<int>> grid = {{0, 1, 2, 3, 4},
                              {24, 23, 22, 21, 5},
                              {12, 13, 14, 15, 16},
                              {11, 17, 18, 19, 20},
                              {10, 9, 8, 7, 6}};
  int ans = swimInWater(grid);
  cout << ans << "\n";
}