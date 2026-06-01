// 0 - 3 months:
// Google (15) — Amazon (10) — Microsoft (7) — Bloomberg (7) — Snowflake (2) — SAP (2)

// 0 - 6 months:
// Meta (5) — Goldman Sachs (3) — Adobe (2) — Apple (2) — Wix (2) — Tesla (2)

// 6 months ago:
// Yahoo (27) — Uber (18) — Oracle (15) — Flipkart (11) — Yandex (9) — TikTok (8) — Zoho (7) — TCS (4) — ByteDance (4) — Walmart Labs (3)

// Problem_Link: https://leetcode.com/problems/container-with-most-water/description/

#include<bits/stdc++.h>
using namespace std;

// Time o(n ^ 2) space o(1)

// int maxArea(vector<int>& height) {
//    int n = height.size();
//    int mx = 0;
//    for(int i = 0; i < n - 1; i++){
//      for(int j = i + 1; j < n; j++){
//          int width = j - i;
//          int high = min(height[i], height[j]);
//          int area = width * high;
//          mx = max(mx, area);
//      }
//    }        
//    return mx;
// }

int maxArea(vector<int>& height) {
   int n = height.size();
   int mx = 0;
   int l = 0, r = n - 1;
   while(l < r){
      int width = r - l;
      int high = min(height[l], height[r]);
      int area = width * high;
      mx = max(mx, area);
      if(height[l] < height[r]){
          l++;
      }
      else{
        r--;
      }
   }
   return mx;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>height = {1,8,6,2,5,4,8,3,7};
    int ans = maxArea(height);
    cout << ans << "\n";
}