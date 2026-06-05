// 0 - 3 months:
// Google (28) — Amazon (12) — Meta (11) — Bloomberg (8) — Microsoft (5) —
// Goldman Sachs (4) — Oracle (3)

// 0 - 6 months:
// Adobe (5) — Wix (4) — Rippling (4) — Apple (3) — Swiggy (2) — Yahoo (2) —
// Capgemini (2) — Dropbox (2) — Zenefits (2)

// 6 months ago:
// Uber (20) — VMware (9) — TikTok (7) — Zoho (5) — Yandex (5) — Wipro (4) —
// PornHub (4) — LinkedIn (3) — Flipkart (3) — Walmart Labs (3)

// Problem_Link:
// https://leetcode.com/problems/median-of-two-sorted-arrays/description/

#include <bits/stdc++.h>
using namespace std;

// Time o(n + m) space o(n + m)

// double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//   int n = nums1.size();
//   int n1 = nums2.size();

//   int l = 0, r = 0;
//   vector<int> ans;
//   while (l < n && r < n1) {
//     if (nums1[l] <= nums2[r]) {
//       ans.push_back(nums1[l]);
//       l++;
//     } else {
//       ans.push_back(nums2[r]);
//       r++;
//     }
//   }
//   while (l < n) {
//     ans.push_back(nums1[l]);
//     l++;
//   }

//   while (r < n1) {
//     ans.push_back(nums2[r]);
//     r++;
//   }

//   int mid = ans.size() / 2;
//   double result;
//   if (ans.size() % 2 == 0) {
//     result = (ans[mid] + ans[mid - 1]) / 2.0;
//   } else {
//     result = ans[mid];
//   }

//   return result;
// }

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  int n = nums1.size();
  int n1 = nums2.size();

  if (n > n1) {
    swap(nums1, nums2);
    swap(n, n1);
  }

  int l = 0, r = n;
  while (l <= r) {
    int cut1 = l + (r - l) / 2;

    int cut2 = (n + n1 + 1) / 2 - cut1;

    int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;

    if (cut1 > 0) {
      l1 = nums1[cut1 - 1];
    }
    if (cut1 != n) {
      r1 = nums1[cut1];
    }
    if (cut2 > 0) {
      l2 = nums2[cut2 - 1];
    }
    if (cut2 != n) {
      r2 = nums2[cut2];
    }

    if(l1 <= r2 && l2 <= r1){
        if((n + n1) % 2 == 1){
          return max(l1, l2);
        }
        else{
          return (max(l1, l2) + min(r1, r2)) / 2.0;
        }
    }
    if(l1 > r2){
       r = cut1 - 1;
    }
    else{
      l = cut1 + 1;
    }
  }
  return 0.0;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<int> nums1 = {0, 0, 0, 0, 0};
  vector<int> nums2 = {-1, 0, 0, 0, 0, 0, 1};
  double ans = findMedianSortedArrays(nums1, nums2);
  cout << ans << "\n";
}