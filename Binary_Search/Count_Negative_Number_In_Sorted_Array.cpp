// 0 - 6 months:
// Amazon (2)

// 6 months ago:
// Bloomberg (6) — Meta (3) — Microsoft (3) — Adobe (2) — Apple (2)

// Problem_Link:
// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/

#include <bits/stdc++.h>
using namespace std;

// Time o(n^2) space o(1)

// int countNegatives(vector<vector<int>>& grid) {
//   int n = grid.size();
//   int m = grid[0].size();
//   int ans = 0;
//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < m; j++) {
//       if (grid[i][j] < 0) {
//         ans++;
//       }
//     }
//   }
//   return ans;
// }

// 4   3   2  -1
// 3   2   1  -1
// 1   1  -1 -2
// -1 -1 -2 -3


// Time o(n + m)

int countNegatives(vector<vector<int>>& grid) {
  int n = grid.size();
  int m = grid[0].size() - 1;
  int row = 0, col = m;
  int ans = 0;
  while(row < n && col >= 0){
      if(grid[row][col] < 0){
         ans += n - row;
         col--;
      }
      else{
         row++;
      }
  }
  return ans;
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<int>> grid = {
      {4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};

  int ans = countNegatives(grid);

  cout << ans << "\n";
}