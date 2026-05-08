// 0 - 3 months:
// Google (7) — Amazon (7) — Meta (3)

// 0 - 6 months:
// Microsoft (5) — Bloomberg (3)

// 6 months ago:
// Oracle (9) — MakeMyTrip (6) — Adobe (5) — ServiceNow (5) — Apple (4) —
// Walmart Labs (4) — Goldman Sachs (4) — Zomato (4) — Myntra (3) — Netflix

// problem Link: https://leetcode.com/problems/first-missing-positive/


// যখনই দেখবেন কোনো প্রশ্নে "Missing Number", "Duplicate Number" বা "First Missing Positive" বের করতে বলা হয়েছে এবং মেমোরি লিমিট $O(1)$ দেওয়া আছে, তখনই Cyclic Sort এর কথা মাথায় আনবেন। এটি লিটকোড (LeetCode) হার্ড প্রবলেমগুলো সমাধান করার জন্য একটি অত্যন্ত শক্তিশালী প্যাটার্ন।



#include <bits/stdc++.h>
using namespace std;

// time o(nlogn) space o(n)

// int firstMissingPositive(vector<int>& nums) {
//   set<int> st;
//   int mn = 1e9;
//   for (auto it : nums) {
//     st.insert(it);
//     if(it > 0){
//         st.insert(it);
//     }
//   }
//   for(int i = 1; i < 1e5 + 2; i++){
//      if(st.find(i) == st.end()){
//         mn = i;
//         break;
//      }
//   }
//   return mn;
// }

// time o(nlogn) space o(1)

// int firstMissingPositive(vector<int>& nums) {
//   sort(nums.begin(), nums.end());
//   int n = nums.size();
//   int start = 0;
//   while (start < n && nums[start] < 1) {
//     start++;
//   }
//   int ans = -1;
//   if (start == n || ((start < n)  && nums[start] != 1)) {
//     ans = 1;
//     return ans;
//   }
//   for (int i = start + 1; i < n; i++) {
//     if (nums[i] - nums[i - 1] > 1) {
//       ans = nums[i - 1] + 1;
//       break;
//     }
//   }
//   if (ans == -1) {
//     ans = nums[n - 1] + 1;
//   }
//   return ans;
// }

// time o(n) space o(1)

int firstMissingPositive(vector<int>& nums) {
   int n = nums.size();
   for(int i = 0; i < n; i++){
     while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]){
        swap(nums[nums[i] - 1], nums[i]);
     }
   }

   int ans = -1;
   for(int i = 0; i < n; i++){
     if(i + 1 != nums[i]){
         ans = i + 1;
         break;
     }
   }
   if(ans == -1){
     ans = n + 1;
   }
   return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {1};

  int ans = firstMissingPositive(nums);

//   for(auto it : nums){
//     cout << it << " ";
//   }
//   return 0;

  cout << ans << "\n";
}