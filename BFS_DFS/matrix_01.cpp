// 0 - 3 months:
// Amazon (6) — Google (3) — Meta (2)

// 0 - 6 months:
// Bloomberg (3) — DoorDash (3) — Microsoft (2)

// 6 months ago:
// Uber (5) — Apple (4) — Flipkart (4) — TikTok (4) — Graviton (3) — Adobe (2) —
// LinkedIn (2) — Zoho (2) — Accenture (2)

// problem_Link: https://leetcode.com/problems/01-matrix/description/

#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;

bool isValid(int i, int j){
   if(i >= 0 && i < n && j >= 0 && j < m){
       return true;
   }
   return false;
}

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
  n = mat.size();
  m = mat[0].size();
  queue<pair<int, int>> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == 1) {
        mat[i][j] = 1000000000;
      } else {
        q.push({i, j});
      }
    }
  }
  
  while(!q.empty()){
     auto x = q.front();
     q.pop();
     int i = x.first;
     int j = x.second;
     for(int k = 0; k < 4; k++){
        int next_i = i + dx[k];
        int next_j = j + dy[k];
        if(isValid(next_i, next_j) && mat[i][j] + 1 < mat[next_i][next_j]){
            mat[next_i][next_j] = mat[i][j] + 1;
            q.push({next_i, next_j});
        }
     }
  }

  return mat;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};

  vector<vector<int>> ans = updateMatrix(mat);

  for (auto it : ans) {
    cout << "[";
    for (auto i : it) {
      cout << i << " ";
    }
    cout << "]";
  }
}