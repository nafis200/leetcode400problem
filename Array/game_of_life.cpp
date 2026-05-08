// 0 - 6 months:
// Microsoft (4) — Meta (2) — Anduril (2) — Applied Intuition (2)

// 6 months ago:
// Google (9) — Amazon (9) — Bloomberg (4) — Goldman Sachs (3) — WarnerMedia (3)
// — Snap (2) — Salesforce (2) — Two Sigma (2) — BitGo (2) — Dropbox (2)

// problem link: https://leetcode.com/problems/game-of-life/description/

// কম প্রতিবেশী (<2): নির্জনতার কারণে মারা যাবে।

// বেশি প্রতিবেশী (>3): অতিরিক্ত ভিড়ের কারণে মারা যাবে।

// সঠিক প্রতিবেশী (2 বা 3): বেঁচে থাকবে।

// নতুন জন্ম: ঠিক ৩টি প্রতিবেশী থাকলে মৃত জায়গায় নতুন প্রাণের জন্ম হবে।

#include <bits/stdc++.h>
using namespace std;

// time o(n * m) space o(n * m)

// bool ok(int i, int j, int n, int m) {
//   return (i >= 0 && i < n && j >= 0 && j < m);
// }

// void gameOfLife(vector<vector<int>>& board) {
//   int n = board.size();
//   int m = board[0].size();
//   vector<vector<int>> copyBoard = board;
//   int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
//   int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < m; j++) {
//       int liveNeighbour = 0;
//       for (int k = 0; k <= 7; k++) {
//         int next_i = i + dx[k];
//         int next_j = j + dy[k];
//         if (ok(next_i, next_j, n, m) && copyBoard[next_i][next_j] == 1) {
//           liveNeighbour++;
//         }
//       }
//       if (copyBoard[i][j] == 1) {
//         if (liveNeighbour > 3 ||  liveNeighbour < 2) {
//           board[i][j] = 0;
//         }
//       }

//       if (copyBoard[i][j] == 0) {
//         if (liveNeighbour == 3) {
//           board[i][j] = 1;
//         }
//       }
//     }
//   }
// }

// optimise

// আমরা ৪টি অবস্থা ব্যবহার করতে পারি:

// 0: আগে মৃত ছিল, এখনও মৃত।

// 1: আগে জীবিত ছিল, এখনও জীবিত।

// 2: আগে মৃত ছিল, কিন্তু এখন জীবিত হয়েছে (0 → 1)।

// 3: আগে জীবিত ছিল, কিন্তু এখন মারা গেছে (1 → 0)।

// Time o(n^2) space o(1)

bool ok(int i, int j, int n, int m) {
  return (i >= 0 && i < n && j >= 0 && j < m);
}

void gameOfLife(vector<vector<int>>& board) {
  int n = board.size();
  int m = board[0].size();
  int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
  int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int liveNeighbour = 0;
      int next_i = 0, next_j = 0;
      for (int k = 0; k < 8; k++) {
        next_i = i + dx[k];
        next_j = j + dy[k];
        if (ok(next_i, next_j, n, m)) {
          if ((board[next_i][next_j] == 1) || (board[next_i][next_j] == 3)) {
            liveNeighbour++;
          }
        }
      }
      if (board[i][j] == 1) {
        if (liveNeighbour < 2 || liveNeighbour > 3) {
          board[i][j] = 3;
        }
      }

      if (board[i][j] == 0) {
        if (liveNeighbour == 3) {
          board[i][j] = 2;
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] == 2) {
        board[i][j] = 1;
      }
      if (board[i][j] == 3) {
        board[i][j] = 0;
      }
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<vector<int>> board = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};

  gameOfLife(board);

  for (auto it : board) {
    cout << "[";
    for (auto it1 : it) {
      cout << it1 << " ";
    }
    cout << "]";
  }
}