// 0 - 3 months:
// Yandex (3) — Google (2) — Amazon (2)

// 6 months ago:
// Meta (9) — Bloomberg (6) — Netflix (4) — Microsoft (3) — VK (3) — Apple (2) —
// Zoho (2)

// time o(n) space o(1)

#include <bits/stdc++.h>
using namespace std;

// o(n) space o(1)

vector<string> summaryRanges(vector<int>& nums) {
  vector<string> ans;

  int n = nums.size();

  for (int i = 0; i < n; i++) {
    int start = nums[i];
    while (i + 1 < n &&  1LL * (nums[i + 1] - 1 == nums[i])) {
      i++;
    }

    string numbers;

    if (start == nums[i]) {
      numbers = to_string(nums[i]);
    } else {
      numbers = to_string(start) + "->" + to_string(nums[i]);
    }

    ans.push_back(numbers);
  }
  return ans;
}



int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {0, 1, 2, 4, 5, 7};

  vector<string> ans = summaryRanges(nums);
  for (auto i : ans) {
    cout << i << " ";
  }
}