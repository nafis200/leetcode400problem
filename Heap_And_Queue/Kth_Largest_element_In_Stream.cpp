// 0 - 3 months:
// Google (5)

// 0 - 6 months:
// Meta (2)

// 6 months ago:
// Amazon (24) — Microsoft (6) — Tinder (5) — Bloomberg (4) — Adobe (2) —
// Goldman Sachs (2) — Wells Fargo (2)

// Problem_Link:
// https://leetcode.com/problems/kth-largest-element-in-a-stream/description/

#include <bits/stdc++.h>
using namespace std;

// n^2 logn

// class KthLargest {
// public:
//     int k;
//     vector<int>nums;
//     KthLargest(int k, vector<int>& nums) {
//         this->k = k;
//         this->nums = nums;
//     }

//     int add(int val) {
//         nums.push_back(val);
//         sort(nums.rbegin(),nums.rend());
//         return nums[k - 1];
//     }
// };

// Time nlogn space o(n)
class KthLargest {
 public:
  int k;
  priority_queue<int, vector<int>, greater<int>> pq;
  KthLargest(int k, vector<int>& nums) {
    this->k = k;
    for (int i = 0; i < nums.size(); i++) {
      if (pq.size() < k) {
        pq.push(nums[i]);
      } else {
        if (nums[i] > pq.top()) {
          pq.pop();
          pq.push(nums[i]);
        }
      }
    }
  }

  int add(int val) {
    pq.push(val);

    if (pq.size() > k) {
      pq.pop();
    }

    return pq.top();
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}