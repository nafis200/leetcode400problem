// 0 - 3 months:
// Amazon (2)

// 0 - 6 months:
// Meta (3)

// 6 months ago:
// Google (6) — Uber (3) — Microsoft (2) — Samsung (2)

// problem_Link:
// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/

#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};
int n;
int m;
bool isValid(int i, int j, vector<vector<bool>>& vis,
             vector<vector<char>>& grid) {
  if (i >= 0 && i < n && j >= 0 && j < m && vis[i][j] == false &&
      grid[i][j] != '+') {
    return true;
  }
  return false;
}

int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
  n = maze.size();
  m = maze[0].size();
  vector<vector<bool>> vis(n, vector<bool>(m, false));
  queue<pair<int, pair<int, int>>> q;

  q.push({0, {entrance[0], entrance[1]}});
  vis[entrance[0]][entrance[1]] = true;
  while(!q.empty()){
     auto x = q.front();
     q.pop();
     int cost = x.first;
     int i = x.second.first;
     int j = x.second.second;
     if((i == 0 || i == n - 1 || j == 0 || j == m - 1) && !(i == entrance[0] && j == entrance[1])){
         return cost;
     }
     for(int k = 0; k < 4; k++){
        int next_i = i + dx[k];
        int next_j = j + dy[k];
        if(isValid(next_i, next_j, vis, maze)){
           vis[next_i][next_j] = true;
           q.push({cost + 1,{next_i, next_j}});
        }
     }
  }
  return -1;
  
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<char>> maze = {
      {'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}};

  vector<int> entrance = {1, 2};

  int ans = nearestExit(maze, entrance);
  cout << ans << "\n";
}