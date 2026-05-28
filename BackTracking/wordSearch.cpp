// 0 - 3 months:
// Bloomberg (14) — Amazon (5) — Uber (5) — Google (4) — Atlassian (2)

// 0 - 6 months:
// Microsoft (7) — Faire (4) — Meta (3) — TikTok (3) — Zoho (2)

// 6 months ago:
// Karat (13) — PayPal (12) — Apple (7) — Oracle (6) — Goldman Sachs (6) —
// Netflix (5) — Salesforce (5) — Epic Systems (4) — Grammarly (4) — Walmart
// Labs (3)

// Problem_Link: https://leetcode.com/problems/word-search/

#include <bits/stdc++.h>
using namespace std;

int row, col;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

// time O(m × n × 4^L)

bool isValid(vector<vector<char>>& board, int i, int j, char ch) {
  if (i >= 0 && i < row && j >= 0 && j < col && board[i][j] == ch) {
    return true;
  }
  return false;
}

bool DFS(vector<vector<char>>& board, int i, int j, string& word, int idx) {
  if (idx == word.size()) {
    return true;
  }

 
  if (!isValid(board, i, j, word[idx])) {
    return false;
  }

  
  char temp = board[i][j];
  board[i][j] = '#';

  for (int k = 0; k < 4; k++) {
    int next_i = i + dx[k];
    int next_j = j + dy[k];

    if (DFS(board, next_i, next_j, word, idx + 1)) {
      return true;
    }
  }

  
  board[i][j] = temp;

  return false;
}

bool exist(vector<vector<char>>& board, string word) {

    row = board.size();
    col = board[0].size();

    // pruning: reverse word if beneficial
    vector<int> freq(256, 0);

    for (auto& rowv : board)
        for (char c : rowv)
            freq[c]++;

    for (char c : word)
        if (--freq[c] < 0)
            return false;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {

            if (board[i][j] == word[0]) {
                if (DFS(board, i, j, word, 0))
                    return true;
            }
        }
    }

    return false;
}

// bool exist(vector<vector<char>>& board, string word) {
//   row = board.size();
//   col = board[0].size();

//   for (int i = 0; i < row; i++) {
//     for (int j = 0; j < col; j++) {
//       if (DFS(board, i, j, word, 0)) {
//         return true;
//       }
//     }
//   }

//   return false;
// }


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<char>> board = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  string word = "ABCCED";
  bool ans = exist(board, word);
}