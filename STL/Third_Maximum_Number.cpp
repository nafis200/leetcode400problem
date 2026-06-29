// 0 - 3 months:
// Google (2)

// 0 - 6 months:
// Amazon (3)

// 6 months ago:
// TikTok (3) — Microsoft (2) — Adobe (2) — Uber (2) — Yahoo (2)

// Problem_Link: https://leetcode.com/problems/third-maximum-number/description/

#include <bits/stdc++.h>
using namespace std;

// Time nlogn space o(n)

// int thirdMax(vector<int>& nums) {
//   priority_queue<int, vector<int>, greater<int>> pq;
//   unordered_set<int> st;
//   int n = nums.size();
//   int k = 3;
//   for (int i = 0; i < n; i++) {
//     if (st.count(nums[i])) {
//       continue;
//     }
//     pq.push(nums[i]);
//     st.insert(nums[i]);
//     if (pq.size() > 3) {
//       pq.pop();
//     }
//   }
//   if(pq.size() < k){
//     while(pq.size() > 1){
//      pq.pop();
//   }
//   }
//   return pq.top();
// }

// 10  8  5

// 11 
// 10  8  8
// 10  10  8
// 11  10  8

int thirdMax(vector<int>& nums) {
        long first = LONG_MIN;
        long second = LONG_MIN;
        long third = LONG_MIN;

        for (int num : nums) {

            if (num == first || num == second || num == third)
                continue;

            if (num > first) {
                third = second;
                second = first;
                first = num;
            }
            else if (num > second) {
                third = second;
                second = num;
            }
            else if (num > third) {
                third = num;
            }
        }

        return (third == LONG_MIN) ? first : third;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}