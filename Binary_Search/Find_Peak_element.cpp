// 0 - 3 months:
// Meta (80) — Google (17) — Amazon (9) — Bloomberg (4) — TikTok (2) — PayPal (2)

// 0 - 6 months:
// Microsoft (8) — Uber (4) — Wix (2) — Accenture (2) — Zepto (2) — Commvault (2) — IXL (2)

// 6 months ago:
// Adobe (19) — Apple (19) — Oracle (3) — Goldman Sachs (3) — Yahoo (3) — tcs (2) — Flipkart (2) — Cisco (2) — Nvidia (2) — Snap (2)

// Problem_Link: https://leetcode.com/problems/find-peak-element/description/


#include<bits/stdc++.h>
using namespace std;

 int findPeakElement(vector<int>& nums) {
    int l = 0, r = nums.size() - 1, ans = 0,  mid = 0;
    while(l < r){
        mid = l + (r - l) / 2;
        if(nums[mid] < nums[mid + 1]){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }
    return l;       
 }
 

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int>nums = {1,2};

    int ans = findPeakElement(nums);

    cout << ans << "\n";
}