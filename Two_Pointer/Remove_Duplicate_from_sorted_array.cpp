// Google (12) — Meta (7) — Microsoft (6) — Amazon (4) — Bloomberg (3) — Apple
// (2)

// Problem_Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;


// time o(n) space o(n)

// int removeDuplicates(vector<int>& nums) {

//   vector<int>temp;
//   int n = nums.size();
//   temp.push_back(nums[0]);
//   for(int i = 1; i < n; i++){
//      if(nums[i] == nums[i - 1]){
//         continue;
//      }
//      temp.push_back(nums[i]);
//   }

//   for(int i = 0; i < temp.size(); i++){
//      nums[i] = temp[i];
//   }
//   return temp.size();
// }




// Time o(n) space o(1)

// int removeDuplicates(vector<int>& nums) {

//   nums.erase(unique(nums.begin(), nums.end()), nums.end());
//   return nums.size();
// }



// time o(n) space o(1)

int removeDuplicates(vector<int>& nums) {
   
    int i = 0;
    int n = nums.size();
    for(int j = 1; j < n; j++){
        if(nums[i] != nums[j]){
            i++;
          nums[i] = nums[j];
        }
    }
    return i + 1;

}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

  int ans = removeDuplicates(nums);
  cout << ans << "\n";
}