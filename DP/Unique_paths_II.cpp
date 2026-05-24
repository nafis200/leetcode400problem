// 0 - 3 months:
// Microsoft (3) — Bloomberg (3) — Amazon (2)

// 6 months ago:
// Google (21) — Meta (10) — Agoda (6) — Nvidia (4) — TikTok (3) — TCS (2) —
// Goldman Sachs (2) — Pinterest (2) — Zepto (2)

// Problem_Link: https://leetcode.com/problems/unique-paths-ii/

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>>memo;

int dp(int i, int j, vector<vector<int>>& grid){
    if(i == n - 1 && j == m - 1){
        if(grid[i][j] == 0){
            return 1;
        }
        return 0;
    }
    if(i >= n || j >= m){
        return 0;
    }
    if(memo[i][j] != -1){
        return memo[i][j];
    }
    if(grid[i][j] == 1){
        return 0;
    }
    int ans = 0;
 
    if(grid[i][j] == 0){
        ans = ans + dp(i + 1, j, grid) + dp(i, j + 1,grid);
    }

    return memo[i][j] = ans;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    n = obstacleGrid.size();
    m = obstacleGrid[0].size();
    memo.assign(n + 1, vector<int>(m + 1, -1));
    int ans = dp(0, 0, obstacleGrid);
    return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  int ans = uniquePathsWithObstacles(obstacleGrid);
  cout << ans << "\n";
}