// 0 - 3 months: Meta (26) — Google (3) — TikTok (2)
// 0 - 6 months: Amazon (4) — Microsoft (3)
// 6 months ago: Bloomberg (6) — Adobe (4) — Uber (4) — Yahoo (4) — Apple (3) —
// FactSet (2)

// Problem_Link:
// https://leetcode.com/problems/kth-missing-positive-number/description/

#include <bits/stdc++.h>
using namespace std;

// Time o(n) space o(n)

// int findKthPositive(vector<int>& arr, int k) {
//   vector<int> ans;
//   for (int i = 0; i < arr.size(); i++) {
//     int num = arr[i];

//     if (i == 0) {
//       int count = 1;
//       while (count < num) {
//         ans.push_back(count);
//         count++;
//       }
//     } else {
//       int count = arr[i - 1] + 1;
//       while (count < num) {
//         ans.push_back(count);
//         count++;
//       }
//     }
//   }
//   int count = arr.back() + 1;
//   while (ans.size() < k) {
//     ans.push_back(count);
//     count++;
//   }
//   return ans[k - 1];
// }

// int findKthPositive(vector<int>& arr, int k) {
//   vector<int> ans;
//   for (int i = 0; i < arr.size(); i++) {
//     int num = arr[i];

//     if (i == 0) {
//       int count = 1;
//       while (count < num) {
//         ans.push_back(count);
//         count++;
//       }
//     } else {
//       int count = arr[i - 1] + 1;
//       while (count < num) {
//         ans.push_back(count);
//         count++;
//       }
//     }
//   }
//   int count = arr.back() + 1;
//   while (ans.size() < k) {
//     ans.push_back(count);
//     count++;
//   }
//   return ans[k - 1];
// }


// Time o(logn)

int findKthPositive(vector<int>& arr, int k) {
   int l = 0, r = arr.size() - 1;
   int mid = 0, ans = arr.size();

   while(l <= r){
      mid = l + (r - l) / 2;
      int missing = arr[mid] - (mid + 1);

      if(missing >= k){
         r = mid - 1;
         ans = mid;
      }
      else{
         l = mid + 1;
      }
   }
   return ans + k;
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<int> arr = {1, 2, 3, 4};
  int k = 5;

  int ans = findKthPositive(arr, k);

  cout << ans << "\n";
}