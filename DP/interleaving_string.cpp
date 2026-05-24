// 0 - 3 months:
// Google (3) — Microsoft (2)

// 0 - 6 months:
// Axon (4) — Amazon (3) — eBay (3)

// 6 months ago:
// Bloomberg (9) — Meta (6) — Apple (5) — Zeta (2) — Walmart Labs (2) — Zoho (2)
// — Nuro (2) — ThoughtSpot (2)

// Problem_Link: https://leetcode.com/problems/interleaving-string/

#include <bits/stdc++.h>
using namespace std;

int n, m, t;

string x, y, z;

vector<vector<int>> memo;

bool dp(int i, int j) {
  if (i == n && j == m) {
    return true;
  }
  if (i > n || j > m) {
    return false;
  }
  if (memo[i][j] != -1) {
    return memo[i][j];
  }
  int k = i + j;
  bool ans = false;
  if (i < n && x[i] == z[k]) {
    ans |= dp(i + 1, j);
  }
  if (j < m && y[j] == z[k]) {
    ans |= dp(i, j + 1);
  }
  return memo[i][j] = ans;
}

bool isInterleave(string s1, string s2, string s3) {
  x = s1;
  y = s2;
  z = s3;
  n = s1.size();
  m = s2.size();
  t = s3.size();
  memo.assign(n + 1, vector<int>(m + 1, -1));

  if (n + m != t) {
    return false;
  }
  bool ans = dp(0, 0);
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s1 = "aabcc";
  string s2 = "dbbca";
  string s3 = "aadbbcbcac";
  bool ans = isInterleave(s1, s2, s3);
  cout << ans << "\n";
}