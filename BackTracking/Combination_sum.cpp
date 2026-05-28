// 0 - 3 months:
// Amazon (6) — Google (4) — Meta (3)

// 0 - 6 months:
// Microsoft (3) — Bloomberg (3) — Apple (2) — NetApp (2)

// 6 months ago:
// Airbnb (17) — TikTok (10) — Walmart Labs (7) — ByteDance (5) — Confluent (4)
// — LinkedIn (3) — Oracle (3) — Zoho (3) — Citadel (3) — Pinterest (3)

// Problem_Link: https://leetcode.com/problems/combination-sum/

#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
vector<vector<int>> result;
int n;
void combination(int i, int sum, int target, vector<int>& candidates) {
  if (i == n) {
    if (target == sum) {
      result.push_back(ans);
    }
    return;
  }
  if (sum > target) {
    return;
  }
  combination(i + 1, sum, target, candidates);
  ans.push_back(candidates[i]);
  combination(i, sum + candidates[i], target, candidates);
  ans.pop_back();
  sort(result.begin(),result.end());
  return;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
  n = candidates.size();
  combination(0, 0, target, candidates);
  return result;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> candidates = {2, 3, 6, 7};
  int target = 7;
  vector<vector<int>> ans = combinationSum(candidates, target);

  for (auto num : ans) {
    cout << "[";
    for (auto i : num) {
      cout << i << " ";
    }
    cout << "]";
  }
}