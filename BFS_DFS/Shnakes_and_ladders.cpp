// 0 - 3 months:
// Amazon (5) — Google (2) — Microsoft (2)

// 0 - 6 months:
// Meta (4) — Zomato (2)

// 6 months ago:
// Bloomberg (4) — Apple (4) — Goldman Sachs (3) — Oracle (2) — TikTok (2) —
// Cisco (2) — Pinterest (2) — Anduril (2)

// https://leetcode.com/problems/snakes-and-ladders/description/

#include <bits/stdc++.h>
using namespace std;

// time o(n^2) space o(n^2)

pair<int, int> getPos(int num, int n) {
  int row = n - 1 - (num - 1) / n;
  int col = (num - 1) % n;

  int rowReverse = (num - 1) / n;

  if (rowReverse % 2) {
    col = n - 1 - col;
  }
  return {row, col};
}

int snakesAndLadders(vector<vector<int>>& board) {
  int n = board.size();
  vector<int> dist(n * n + 1, 1e9);
  queue<int> q;
  dist[1] = 0;
  q.push(1);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int dice = 1; dice <= 6; dice++) {
      int next = x + dice;
      if (next > n * n) {
        break;
      }
      auto it = getPos(next, n);
      int r = it.first;
      int c = it.second;
      if(board[r][c] != -1){
         next = board[r][c];
      }
      if(dist[next] > dist[x] + 1){
          dist[next] = dist[x] + 1;
          q.push(next);
      }
    }
  }
  return (dist[n*n] == 1e9 ? -1 : dist[n*n]);
}

int main() {
  vector<vector<int>> board = {
      {-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1}, {-1, 35, -1, -1, 13, -1},
      {-1, -1, -1, -1, -1, -1}, {-1, 15, -1, -1, -1, -1}};

  return 0;
}