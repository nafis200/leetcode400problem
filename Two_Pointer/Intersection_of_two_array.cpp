// 0 - 3 months: Google (6) — Amazon (6) — Microsoft (2)
// 0 - 6 months: Wix (2) — Nvidia (2) — Two Sigma (2)
// 6 months ago: Apple (21) — Adobe (12) — Uber (10) — Bloomberg (7) — Meta (6) — Yandex (5) — LinkedIn (4) — J.P. Morgan (3) — Yahoo (3) — IBM (2)

// Problem_Link: https://leetcode.com/problems/intersection-of-two-arrays/description/

#include<bits/stdc++.h>
using namespace std;

// Time o(nlogn) space o(n)

//  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//     vector<int>ans;
//     vector<bool>take(1002, false);
//     set<int>st;
//     for(auto it : nums1){
//         take[it] = true;
//     }

//     for(auto it : nums2){
//         if(take[it] == true){
//             if(st.find(it) == st.end()){
//                ans.push_back(it);
//                st.insert(it);
//             }
//         }
//     }
//     return ans;
//  }

// time o(n) space o(n)

 vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int>ans;
    vector<bool>take(1002, false);
   
    for(auto it : nums1){
        take[it] = true;
    }

    for(auto it : nums2){
        if(take[it] == true){
           ans.push_back(it);
           take[it] = false;
        }
    }
    return ans;
 }



int32_t main(){
    ios_base:: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums1 = {1, 2, 2, 1};
    vector<int>nums2 = {2, 2};
    vector<int>ans = intersection(nums1, nums2);
    for(auto it : ans){
        cout << it << " ";
    }
}