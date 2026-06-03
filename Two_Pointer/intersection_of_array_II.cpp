// 0 - 3 months:
// Google (5) — Meta (3)

// 6 months ago:
// Amazon (15) — Bloomberg (9) — Yandex (8) — Microsoft (4) — Apple (3)

// Problem_Link: https://leetcode.com/problems/intersection-of-two-arrays-ii/description/

#include<bits/stdc++.h>
using namespace std;

// time o(n) space o(n)

//  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//      vector<int>ans(1005, 0);

//      vector<int>result;
//      for(auto it : nums1){
//          ans[it]++;
//      }

//      for(auto it : nums2){
//         if(ans[it] > 0){
//             ans[it]--;
//             result.push_back(it);
//         }
//      }
//      return result;

//  }

//  11 22
//  22

// Time o(nlogn) space o(1)

 vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int i = 0, j = 0;
    vector<int> ans;

    while(i < n1 && j < n2){

        while(i < n1 && j < n2 && nums1[i] == nums2[j]){
            ans.push_back(nums1[i]);
            i++;
            j++;
        }

        while(i < n1 && j < n2 && nums1[i] < nums2[j]){
            i++;
        }

        while(i < n1 && j < n2 && nums2[j] < nums1[i]){
            j++;
        }
    }

    return ans;
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector <int> nums1 = {4,9,5};

    vector<int> nums2 = {9,4,9,8,4};

    vector<int>ans = intersect(nums1, nums2);

    for(auto i : ans){
        cout << i << " ";
    }
}