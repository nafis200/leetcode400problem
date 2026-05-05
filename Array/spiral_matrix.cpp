
// 0 - 3 months:
// Amazon (14) — Google (7) — Microsoft (7) — Meta (5) — Cisco (5) — Uber (4) —
// Oracle (3) — Epic Systems (3) — Capital One (3) — TikTok (2)

// 0 - 6 months:
// Zoho (16) — Bloomberg (7) — IBM (2) — Apple (2) — Walmart Labs (2) —
// Nordstrom (2) — Intuit (2) — Databricks (2) — Roblox (2) — PayPal (2)

// 6 months ago:
// Adobe (27) — Accenture (7) — Yahoo (7) — tcs (5) — Goldman Sachs (3) — DE
// Shaw (3) — Darwinbox (3) — Netflix (3) — MakeMyTrip (3) — Epic Games (3)

#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
  int top = 0, left = 0, bottom = matrix.size() - 1, right = matrix[0].size() - 1;

  vector<int> ans;

  while (top <= bottom && left <= right) {
   
    for (int i = left; i <= right; i++) {
      ans.push_back(matrix[top][i]);
    }
    top++;
    if (top > bottom) {
      break;
    }

    for (int i = top; i <= bottom; i++) {
      ans.push_back(matrix[i][right]);
    }
    right--;
    if (right < left) {
      break;
    }
    for (int i = right; i >= left; i--) {
      ans.push_back(matrix[bottom][i]);
    }
    bottom--;

    if (bottom < top) {
      break;
    }
    for(int i = bottom; i >= top; i--){
        ans.push_back(matrix[i][left]);
    }
    left++;
     if (left > right) {
      break;
    }
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  vector<int> ans = spiralOrder(matrix);

  for (auto it : ans) {
    cout << it << " ";
  }
}