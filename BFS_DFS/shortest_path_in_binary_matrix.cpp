// 0 - 3 months:
// Meta (38) — Uber (3) — Amazon (2)

// 0 - 6 months:
// Google (7) — Microsoft (2) — Bloomberg (2)

// 6 months ago:
// Yahoo (5) — TikTok (3) — Oracle (2) — Airbnb (2) — Palo Alto Networks (2) —
// Snap (2)

// problem_Link:
// https://leetcode.com/problems/shortest-path-in-binary-matrix/description/


// time complexity o(n^2) space complexity o (n^2)

#include <bits/stdc++.h>
using namespace std;

// const int inf = 1e9;
// vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
// vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
// int n;
// int m;
// bool isValid(int i, int j, vector<vector<int>>& grid){
//    if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != 1){
//        return true;
//    }
//    return false;
// }

// int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//   n = grid.size();
//   m = grid[0].size();
//   vector<vector<int>> grid(n, vector<int>(m, inf));

//   if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) {
//     return -1;
//   }
//   queue<pair<int,int>>q;
//   q.push({0, 0});
//   grid[0][0] = 1;
//   while(!q.empty()){
//      auto x = q.front();
//      q.pop();
//      int i = x.first;
//      int j = x.second;
//      for(int k = 0; k < 8; k++){
//         int next_i = i + dx[k];
//         int next_j = j + dy[k];
//         if(isValid(next_i, next_j, grid)){
//             if(grid[i][j] + 1 < grid[next_i][next_j]){
//                 grid[next_i][next_j] = grid[i][j] + 1;
//                 q.push({next_i, next_j});
//             }
//         }
//      }
//   }
//   if(grid[n - 1][m - 1] == inf){
//      return -1;
//   }
//   return grid[n - 1][m - 1];
// }

// time o(n ^ 2) space o(1)

const int inf = 1e9;
const int ninf = -1e9;
vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
int n;
int m;
bool isValid(int i, int j, vector<vector<int>>& grid){
   if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != 1){
       return true;
   }
   return false;
}

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
  n = grid.size();
  m = grid[0].size();
  


  if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) {
    return -1;
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
        if(grid[i][j] == 0){
            grid[i][j] = inf;
        }
        else{
            grid[i][j] = ninf;
        }
    }
  }
  grid[0][0] = 1;
  queue<pair<int,int>>q;
  q.push({0, 0});
  while(!q.empty()){
     auto x = q.front();
     q.pop();
     int i = x.first;
     int j = x.second;
     for(int k = 0; k < 8; k++){
        int next_i = i + dx[k];
        int next_j = j + dy[k];
        if(isValid(next_i, next_j, grid)){
            if(grid[i][j] + 1 < grid[next_i][next_j]){
                grid[next_i][next_j] = grid[i][j] + 1;
                q.push({next_i, next_j});
            }
        }
     }
  }
  if(grid[n - 1][m - 1] == inf){
     return -1;
  }
  return grid[n - 1][m - 1];
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<int>> grid = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
  int ans = shortestPathBinaryMatrix(grid);
  cout << ans << "\n";
}