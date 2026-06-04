// 0 - 6 months: Bloomberg (2) — GoDaddy (2)
// 6 months ago: Amazon (6) — Microsoft (4) — Google (3) — Adobe (2) — Apple (2)

// Problem_Link: https://leetcode.com/problems/arranging-coins/description/

#include<bits/stdc++.h>
using namespace std;

// Time Complexity o(n)

//  int arrangeCoins(int n) {
//      long long ans = 0;
//      int index = 0;
//      for(int i = 1; i <= n; i++){
//          if(1LL * (ans + i) <= n){
//             ans += i;
//             index = i;
//          }
//      }
//      return index;
//  }



 int arrangeCoins(int n) {
     int l = 0, r = n;
     int mid = 0, ans = 0;
     while(l <= r){
         mid = l + (r - l) / 2;
         long long row = 1LL * mid * (mid + 1) / 2;
         if(row <= n){
             ans = mid;
             l = mid + 1;
         }
         else{
            r = mid - 1;
         }
     }
     return ans;
 }


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 5;
    
    int ans = arrangeCoins(n);

    cout << ans << "\n";
}