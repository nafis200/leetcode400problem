// 0 - 3 months:
// Amazon (6) — Google (2)

// 0 - 6 months:
// Bloomberg (4) — Meta (2) — Microsoft (2) — Adobe (2) — Two Sigma (2)

// 6 months ago:
// Sprinklr (4) — Yahoo (4) — DoorDash (2)

// problem_Link: https://leetcode.com/problems/number-of-provinces/description/

#include <bits/stdc++.h>
using namespace std;

// time o (n * m) space o (n * m)

vector<vector<int>> dp;
int n, m;
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

bool isValid(int i, int j, int next_i, int next_j,
             vector<vector<int>>& matrix) {
  if (next_i >= 0 && next_i < n && next_j >= 0 && next_j < m &&
      matrix[next_i][next_j] > matrix[i][j]) {
    return true;
  }
  return false;
}

int DFS(vector<vector<int>>& matrix, int i, int j) {
  if (dp[i][j] != -1) {
    return dp[i][j];
  }

  int ans = 1;
  for(int k = 0; k < 4; k++){
     int next_i = i + dx[k];
     int next_j = j + dy[k];
     if(isValid(i, j, next_i, next_j, matrix)){
          ans = max(ans, 1 + DFS(matrix, next_i, next_j));  
     }
  }
  return dp[i][j] = ans;
  
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
  n = matrix.size();
  m = matrix[0].size();
  dp.assign(n, vector<int>(m, -1));

  int ans = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
        ans = max(ans, DFS(matrix, i, j));
    }
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<int>> matrix = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
  int ans = longestIncreasingPath(matrix);
  cout << ans << "\n";
}