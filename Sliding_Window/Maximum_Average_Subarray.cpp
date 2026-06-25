// ### 0 – 3 Months

// * Google ×5
// * Amazon ×2

// ### 0 – 6 Months

// * Meta ×5
// * Bloomberg ×5
// * Microsoft ×2

// ### 6 Months Ago

// * TCS ×2
// * Goldman Sachs ×2
// * Uber ×2
// * OPPO ×2

// Problem_Link:
// https://leetcode.com/problems/maximum-average-subarray-i/description/

#include <bits/stdc++.h>
using namespace std;
double findMaxAverage(vector<int>& nums, int k) {
  double ans = 0;
  double ave = 0;

  for (int i = 0; i < k; i++) {
    ave += nums[i];
  }
  double sum = ave;
  ave = ave / k;
  ans = ave;

  for (int i = k; i < nums.size(); i++) {
    sum += nums[i];
    sum -= nums[i - k];
    ave = sum / k;
    ans = max(ans, ave);
  }

  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {1, 12, -5, -6, 50, 3};
  int k = 0;
}