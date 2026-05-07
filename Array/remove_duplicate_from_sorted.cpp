 
// 0 - 3 months:
// Google (5) — Bloomberg (2) — FreshWorks (2)

// 0 - 6 months:
// Amazon (3)

// 6 months ago:
// Meta (18) — Microsoft (15) — TikTok (3) — Accolite (2) — TCS (2) — Uber (2) — Nykaa

// time o(nlogn) space o(n)

#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
     map<int,int>mp;
     int k = 0;
     for(auto it : nums){
         if(mp[it] < 2){
            mp[it]++;
            k++;
         }
     } 
     vector<int>ans;

     for(auto it : nums){
        while(mp[it] > 0){
            ans.push_back(it);
            mp[it]--;
        }
     }
     nums = ans;

     return k;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int>nums = {0,0,1,1,1,1,2,3,3};

    int ans = removeDuplicates(nums);

    cout << ans << "\n";
    for(auto it : nums){
       cout << it << " ";
    }
    
}