// 0 - 3 months:
// Google (4) — PhonePe (2)

// 0 - 6 months:
// Microsoft (2) — Snap (2)

// 6 months ago:
// Samsung (19) — Amazon (16) — Bloomberg (4) — Uber (4) — Cisco (4) — Flipkart
// (3) — QBurst (2)

// Problem_Link: https://leetcode.com/problems/burst-balloons/description/

// nums = [3, 5]

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> memo;
vector<int> a;
int dp(int l, int r) {
  if (l == r - 1) {
    return 0;
  }
  if (memo[l][r] != -1) {
    return memo[l][r];
  }
  int ans = 0;

  for (int k = l + 1; k < r; k++) {
    int left = dp(l, k);
    int right = dp(k, r);
    int gain = a[k] * a[l] * a[r];
    ans = max(ans, left + gain + right);
  }

  return memo[l][r] = ans;
}

int maxCoins(vector<int>& nums) {
  a.push_back(1);
  for (auto i : nums) {
    a.push_back(i);
  }
  a.push_back(1);
  int n = a.size();
  memo.assign(n + 1, vector<int>(n + 1, -1));
  int ans = 0;
  ans = dp(0, n - 1);
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {3, 1, 5, 8};
  int ans = maxCoins(nums);
  cout << ans << "\n";
}