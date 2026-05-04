
// Meta (22)
// 0 - 6 months:
// Google (2)
// 6 months ago:
// tcs (3)

// problem Link: https://leetcode.com/problems/toeplitz-matrix/description/

#include <bits/stdc++.h>
using namespace std;

bool isToeplitzMatrix(vector<vector<int>>& matrix) {
  int rows = matrix.size();
  int cols = matrix[0].size();

  bool ok = true;

  for (int i = 1; i < rows; i++) {
    for (int j = 1; j < cols; j++) {
      if (matrix[i][j] != matrix[i - 1][j - 1]) {
        ok = false;
      }
    }
  }

  return ok;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 1, 2, 3}, {9, 5, 1, 2}};

  bool ans = isToeplitzMatrix(matrix);

  cout << ans << "\n";
}

// Time complexity o(n^2) auxilary space complexity o(1)