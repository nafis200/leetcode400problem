// 0 - 3 months:
// Amazon (39) — Google (28) — Goldman Sachs (20) — Microsoft (9) — Meta (7) —
// Bloomberg (7) — TikTok (4) — Visa (3) — Snowflake (3) — Yandex (3)

// 0 - 6 months:
// Oracle (6) — Salesforce (5) — PhonePe (4) — Apple (3) — Flipkart (3) — Zoho
// (3) — Uber (3) — Airbnb (3) — tcs (2) — Wix (2)

// 6 months ago:
// Adobe (46) — Yahoo (14) — ServiceNow (11) — Walmart Labs (9) — Samsung (9) —
// Intel (9) — Cisco (6) — Intuit (5) — Nvidia (5) — PayPal (5)

// Problem_Link: https://leetcode.com/problems/trapping-rain-water/description/

#include<bits/stdc++.h>
using namespace std;

// O(n^2)

// int trap(vector<int>& height){
//     int n = height.size();
//     int water = 0;

//     for(int i = 0; i < n; i++){

//         int left_max = 0;
//         for(int j = 0; j <= i; j++){
//             left_max = max(left_max, height[j]);
//         }

//         int right_max = 0;
//         for(int j = i; j < n; j++){
//             right_max = max(right_max, height[j]);
//         }

//         water += min(left_max, right_max) - height[i];
//     }

//     return water;
// }


// o(n)
int trap(vector<int>& height){
   int left_max = 0, right_max = 0;
   int l = 0, r = (int)height.size() - 1;
   
   int water = 0;

   while(l < r){
      if(height[l] <= height[r]){
         if(height[l] >= left_max){
            left_max = height[l];
         }
         else{
            water += left_max - height[l];
         }
         l++;
      }
      else{
        if(height[r] >= right_max){
            right_max = height[r];
        }
        else{
            water += right_max - height[r];
        }
        r--;
      }
   }
   return water;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>height = {0,1,0,2,1,0,1,3,2,1,2,1};
    
    int ans = trap(height);

    cout << ans << "\n";

}