 
 	
// 0 - 3 months:
// Meta (21) — Google (20) — Amazon (15) — Bloomberg (4) — Microsoft (3) — TikTok (3) — TCS (2) — Agoda (2)

// 0 - 6 months:
// Cloudflare (5) — Adobe (3) — Apple (2) — Goldman Sachs (2) — Wix (2) — BNY Mellon (2) — Zomato (2) — Gojek (2) — Works Applications (2) — Shipsy (2)

// 6 months ago:
// Uber (19) — Yahoo (18) — Accenture (7) — Oracle (6) — Walmart Labs (6) — Salesforce (6) — Zoho (4) — Tesla (4) — Intuit (4) — Infosys (3)

// Problem_Link: https://leetcode.com/problems/3sum/description/

#include<bits/stdc++.h>
using namespace std;

// n^3 logn
// space o(n)

//  vector<vector<int>> threeSum(vector<int>& nums) {
//      int n = nums.size();
//      vector<vector<int>>ans;
//      set<vector<int>>st;
     
//      for(int i = 0; i < n - 2; i++){
//         for(int j = i + 1; j < n - 1; j++){
//             for(int k = j + 1; k < n; k++){
//                 vector<int>find;
//                 if(nums[i] + nums[j] + nums[k] == 0){
//                     find.push_back(nums[i]);
//                     find.push_back(nums[j]);
//                     find.push_back(nums[k]);
//                     sort(find.begin(), find.end());
//                     st.insert(find);
//                 }
//             }
//         }
//      }
     
//      for(auto it : st){
//         ans.push_back(it);
//      }

//      return ans;
//  }

// time o(n^2) space o(1)

vector<vector<int>> threeSum(vector<int>& nums) {
     int n = nums.size();
     vector<vector<int>>ans;
     sort(nums.begin(),nums.end());
     for(int i = 0; i < n - 2; i++){
        if(i > 0 && nums[i] == nums[i - 1]){
            continue;
        }
        int j = i + 1, k = n - 1;
        while(j < k){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum == 0){
                ans.push_back({nums[i],nums[j],nums[k]});
                while(j < k && nums[j] == nums[j + 1]){
                    j++;
                }
                while(j < k && nums[k] == nums[k - 1]){
                    k--;
                }
                j++;
                k--;
            }
            else if(sum < 0){
                j++;
            }
            else{
                k--;
            }

        }
     }
     return ans;
 }

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {-1,0,1,2,-1,-4};
     vector<vector<int>>ans = threeSum(nums);

     for(auto v : ans){
        cout << "[";
        for(auto i : v){
            cout << i << " ";
        } 
        cout << "]\n";
     }
}