// 0 - 3 months:
// Google (4) — Amazon (4) — Meta (2)

// 0 - 6 months:
// Microsoft (3)

// 6 months ago:
// Bloomberg (13) — TikTok (7) — Adobe (3) — Apple (3) — Urban Company (3) —
// Flipkart (2) — Goldman Sachs (2)

// Problem_Link: https://leetcode.com/problems/surrounded-regions/description/

#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

// time o(n * m) space o(n * m)

bool isValid(vector<vector<char>>& board, int i, int j) {
  int row = board.size();
  int col = board[0].size();
  if (i >= 0 && i <= row - 1 && j >= 0 && j <= col - 1 && board[i][j] == 'O') {
    return true;
  }
  return false;
}

void DFS(vector<vector<char>>& board, int i, int j) {
    board[i][j] = '#';
    for(int k = 0; k < 4; k++){
        int next_i = i + dx[k];
        int next_j = j + dy[k];

        if(isValid(board, next_i, next_j)){
            DFS(board, next_i, next_j);
        }

    }
}

void solve(vector<vector<char>>& board) {
  int row = board.size();
  int col = board[0].size();
  for (int i = 0; i < col; i++) {
    if (board[0][i] == 'O') {
      DFS(board, 0, i);
    }
    if (board[row - 1][i] == 'O') {
      DFS(board, row - 1, i);
    }
  }
  for (int i = 0; i < row; i++) {
    if (board[i][0] == 'O') {
      DFS(board, i, 0);
    }
    if (board[i][col - 1] == 'O') {
      DFS(board, i, col - 1);
    }
  }
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (board[i][j] == '#') {
        board[i][j] = 'O';
      } else {
        board[i][j] = 'X';
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
                                {'X', 'O', 'O', 'X'},
                                {'X', 'X', 'O', 'X'},
                                {'X', 'O', 'X', 'X'}};
    solve(board);
    for(auto v : board){
        for(auto i : v){
            cout << i << " ";
        }
        cout << "\n";
    }
}