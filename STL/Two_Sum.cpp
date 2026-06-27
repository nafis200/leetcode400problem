// 0 - 3 months:
// Google (186) — Amazon (68) — Microsoft (57) — Meta (52) — Bloomberg (27) — Apple (10) — Oracle (7) — Visa (4) — Infosys (3) — Walmart Labs (3)

// 0 - 6 months:
// TCS (11) — Yandex (8) — Adobe (5) — TikTok (5) — Accenture (5) — Salesforce (5) — SAP (5) — IBM (4) — Uber (4) — PayPal (4)

// 6 months ago:
// Yahoo (88) — Goldman Sachs (15) — Capgemini (12) — Deloitte (11) — Zoho (10) — Wipro (10) — Spotify (8) — Tinkoff (7) — Cisco (7) — Nvidia (7)

// Problem_Link: https://leetcode.com/problems/two-sum/

#include<bits/stdc++.h>
using namespace std;
// Time o(n^2) space o(1)
// vector<int> twoSum(vector<int>& nums, int target) {
//      int n = nums.size();
//      vector<int>ans;
//      for(int i = 0; i < n - 1; i++){
//         for(int j = i + 1; j < n; j++){
//             if(nums[i] + nums[j] == target){
//                 ans.push_back(i);
//                 ans.push_back(j);
//             }
//         }
//      }
//      return ans;        
// }

// x + y = target
//  x = y - target


// Time o(n) space o(n)
vector<int> twoSum(vector<int>& nums, int target) {
     int n = nums.size();
     vector<int>ans;
     unordered_map<int,int>mp;
     for(int i = 0; i < n; i++){
        int x = nums[i];
        if(mp.find(target - x) != mp.end()){
            ans.push_back(mp[target - x]);
            ans.push_back(i);
        }
        mp[x] = i;
     }
     return ans;        
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {2,7,11,15};
    int target = 9;
    vector<int>ans = twoSum(nums, target);
    for(auto it : ans){
        cout << it << " ";
    }
}