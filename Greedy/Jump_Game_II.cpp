// 0 - 3 months:
// Google (9) — Amazon (7) — Meta (2) — TCS (2) — Atlassian (2) — DoorDash (2)

// 0 - 6 months:
// Bloomberg (5) — Microsoft (4) — Apple (2) — TikTok (2) — PhonePe (2)

// 6 months ago:
// Uber (16) — Adobe (11) — Oracle (9) — Walmart Labs (3) — DE Shaw (3) — MakeMyTrip (3) — Expedia (3) — Flipkart (2) — Goldman Sachs (2) — Siemens (2)

// Problem_Link: https://leetcode.com/problems/jump-game-ii/description/

#include<bits/stdc++.h>
using namespace std;
int jump(vector<int>& nums) {
    int farthest = 0;
    int jump = 0;
    int current_end = 0;
    for(int i = 0; i < nums.size() - 1; i++){
        farthest = max(farthest, i + nums[i]);
        if(i == current_end){
            jump++;
            current_end = farthest;
        }
    }   
    return jump;     
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {2,3,1,1,4};
    int ans = jump(nums);
}