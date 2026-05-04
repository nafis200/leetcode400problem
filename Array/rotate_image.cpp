// 0 - 3 months:
// Google (12) — Meta (11) — Cisco (7) — Amazon (5) — Bloomberg (4) — Microsoft
// (3) — Uber (3) — Infosys (2) — Nvidia (2) — Roblox (2)

// 0 - 6 months:
// IBM (10) — Capital One (6) — Apple (5)

// 6 months ago:
// Adobe (23) — Yahoo (14) — Oracle (7) — Tinkoff (6) — Zoho (5) — ConsultAdd
// (4) — Walmart Labs (3) — DE Shaw (3) — ZScaler (3) — AMD (3)

// Problem-Link: https://leetcode.com/problems/rotate-image/description/

// time complexity o(n^2) auxilary o(n^2)

#include <bits/stdc++.h>
using namespace std;

// void rotate(vector<vector<int>>& matrix) {
//   vector<vector<int>> a = matrix;

//   int row = matrix.size();
//   int col = matrix[0].size();
//   for (int i = 0; i < row; i++) {
//     for (int j = 0; j < col; j++) {
//        a[j][abs(col - i - 1)] = matrix[i][j];
//     }
//   }
//   matrix = a;
// }


// time complexity o(n^2) space o(1)

void rotate(vector<vector<int>>& matrix) {
  int row = matrix[0].size();

  for (int i = 0; i < row; i++) {
    for (int j = 0; j <= i; j++) {
      swap(matrix[i][j], matrix[j][i]);
    }
  }

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < (row + 1) / 2; j++) {
      swap(matrix[i][j], matrix[i][row - 1 - j]);
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  rotate(matrix);
  int row = matrix.size();
  int col = matrix[0].size();
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << "\n";
  }
}