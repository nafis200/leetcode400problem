// 0 - 3 months:
// Google (10) — Microsoft (6) — Amazon (4) — Bloomberg (4) — Meta (3) — TikTok
// (3)

// 0 - 6 months:
// tcs (3) — PhonePe (2) — Pocket Gems (2)

// 6 months ago:
// Apple (18) — Adobe (16) — Walmart Labs (7) — Yahoo (7) — Oracle (6) — Zoho
// (6) — Uber (5) — PayPal (3) — Swiggy (3) — Docusign (3)

// Problem_Link: https://leetcode.com/problems/sort-colors/

#include <bits/stdc++.h>
using namespace std;

// Time o(n^2) space o(1)

// void sortColors(vector<int>& nums) {
//    int n = nums.size();
//    for(int i = 0; i < n - 1; i++){
//      for(int j = i + 1; j < n; j++){
//          if(nums[i] > nums[j]){
//             swap(nums[i], nums[j]);
//          }
//      }
//    }
// }

// Time nlogn space o(n)

// void mergeSort(int l, int r, vector<int>& nums) {
//     if (l >= r) return;

//     int mid = (l + r) / 2;

//     mergeSort(l, mid, nums);
//     mergeSort(mid + 1, r, nums);

//     vector<int> L, R;

//     for (int i = l; i <= mid; i++) {
//         L.push_back(nums[i]);
//     }

//     for (int i = mid + 1; i <= r; i++) {
//         R.push_back(nums[i]);
//     }

//     int i = l;
//     int Lid = 0, Rid = 0;

//     while (Lid < L.size() && Rid < R.size()) {
//         if (L[Lid] <= R[Rid]) {
//             nums[i++] = L[Lid++];
//         } else {
//             nums[i++] = R[Rid++];
//         }
//     }

//     while (Lid < L.size()) {
//         nums[i++] = L[Lid++];
//     }

//     while (Rid < R.size()) {
//         nums[i++] = R[Rid++];
//     }
// }

// void sortColors(vector<int>& nums) {
//     int n = nums.size();
//     mergeSort(0, n - 1, nums);
// }

// time (nlogn) worst o(n^2) space o(1)

// int Partition(int l, int r, vector<int>& nums){
//     int i = l;
//     for(int j = l; j < r; j++){
//         if(nums[j] <= nums[r]){
//             swap(nums[i], nums[j]);
//             i++;
//         }
//     }
//     swap(nums[i], nums[r]);
//     return i;
// }

// void QuickSort(int l, int r, vector<int>&nums){
//     if(l >= r){
//         return;
//     }
//     int p = Partition(l, r, nums);
//     QuickSort(l, p - 1, nums);
//     QuickSort(p + 1, r, nums);
// }


// void sortColors(vector<int>& nums) {
//     int n = nums.size();
//     QuickSort(0, n - 1, nums);
// }

//  1 0 2 1 2 0

// Time o(n)

void sortColors(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    int high = n - 1;
    int j = 0;
    while(j <= high){
        if(nums[j] == 0){
            swap(nums[i], nums[j]);
            i++;
            j++;
        }
        else if(nums[j] == 1){
            j++;
        }
        else{
            swap(nums[j], nums[high]);
            high--;
        }

    }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {2, 0, 2, 1, 1, 0};

  sortColors(nums);

  for (auto it : nums) {
    cout << it << " ";
  }
}