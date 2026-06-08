// 0 - 3 months:
// Amazon (5) — Microsoft (4) — Google (2) — Agoda (2)

// 0 - 6 months:
// Meta (4) — Bloomberg (3)

// 6 months ago:
// TikTok (9) — Oracle (6) — Goldman Sachs (4) — Apple (3) — Flipkart (3) — DP
// World (3) — Zeta (2) — Chalo (2) — Uber (2) — Cloudera (2)

// Problem_Link:
// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

#include <bits/stdc++.h>
using namespace std;

bool isLoad(vector<int>& weights, int days, int k) {
  int count = 1;

  int sum = 0;

  int n = weights.size();

  for (int i = 0; i < n; i++) {
    if (weights[i] > k) 
    return false;
    if (sum + weights[i] <= k) {
      sum = sum + weights[i];
    } else {
      sum = weights[i];
      count++;
    }
  }
  return (count <= days);
}

int shipWithinDays(vector<int>& weights, int days) {
  int l = 1, r = 1e9, mid = 0, ans = 0;
  while (l <= r) {
    mid = l + (r - l) / 2;
    if (isLoad(weights, days, mid)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int days = 5;

  int ans = shipWithinDays(weights, days);

  cout << ans << "\n";
}