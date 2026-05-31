
#include <bits/stdc++.h>
using namespace std;

// time n! space o(n ^ 2)

vector<int> col, diag1, diag2;
int ans = 0;
void solve(int n, vector<string>& board, int row) {
  if (row == n) {
    ans++;
    return;
  }
  for (int c = 0; c < n; c++) {
    if (col[c] || diag1[row - c + n] || diag2[row + c]) {
      continue;
    }
    board[row][c] = 'Q';
    col[c] = 1;
    diag1[row - c + n] = 1;
    diag2[row + c] = 1;
    solve(n, board, row + 1);
    board[row][c] = '.';
    col[c] = 0;
    diag1[row - c + n] = 0;
    diag2[row + c] = 0;
  }

}

int totalNQueens(int n) {
  vector<string> board(n, string(n, '.'));
  col.assign(n, 0);
  diag1.assign(2 * n, 0);
  diag2.assign(2 * n, 0);
  solve(n, board, 0);
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int ans = totalNQueens(4);
  cout << ans << "\n";
}