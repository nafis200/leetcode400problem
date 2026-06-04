// 0 - 3 months: Meta (20) — Google (10) — Amazon (8) — LinkedIn (8) — Bloomberg (4) — Microsoft (3) — Tinkoff (2) — TikTok (2)

// 0 - 6 months: Uber (2) — Pinterest (2) — Instacart (2)

// 6 months ago: Adobe (20) — Apple (14) — Yahoo (6) — Oracle (5) — tcs (3) — PayPal (3) — Goldman Sachs (2) — Intuit (2) — Accenture (2) — ServiceNow (2)

// Problem_Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

#include<bits/stdc++.h>
using namespace std;

// Time o(n) space o(1)

//  vector<int> searchRange(vector<int>& nums, int target) {
//     int first = INT_MAX;
//     int last = INT_MIN;
//     for(int i = 0; i < (int)nums.size(); i++){
//         if(nums[i] == target){
//             first = min(first, i);
//             last = max(last, i);
//         }
//     }   
//     vector<int>ans;   
//     if(first == INT_MAX){
//         ans.push_back(-1);
//         ans.push_back(-1);
//     }
//     else{
//         ans.push_back(first);
//         ans.push_back(last);
//     }
//     return ans;
//  }

// Time o(logn)

vector<int> searchRange(vector<int>& nums, int target) {
    int first = INT_MAX;
    int last = INT_MIN;
    int l = 0, r = nums.size() - 1;
    
    int mid = 0;

    while(l <= r){
        mid = l + (r - l) / 2;
        if(nums[mid] == target){
            r = mid - 1;
            first = mid;
        }
        else if(nums[mid] > target){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    l = 0, r = nums.size() - 1;
    mid = 0;

    while(l <= r){
        mid = l + (r - l) / 2;
        if(nums[mid] == target){
            l = mid + 1;
            last = mid;
        }
        else if(nums[mid] < target){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }

    vector<int>ans;   
    if(first == INT_MAX){
        ans.push_back(-1);
        ans.push_back(-1);
    }
    else{
        ans.push_back(first);
        ans.push_back(last);
    }
    return ans;
 }

int32_t main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   vector<int>nums = {5, 7, 7, 8, 8, 10};
   int target = 8;

   vector<int>ans = searchRange(nums, target);

   cout << ans[0] << " " << ans[1] << "\n";
}

