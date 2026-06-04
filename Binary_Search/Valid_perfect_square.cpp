// 0 - 3 months: Microsoft (4) — Google (3) — LinkedIn (2)
// 0 - 6 months: Bloomberg (2)
// 6 months ago: Meta (7) — Apple (6) — Adobe (5) — Amazon (3) — tcs (2) — SAP (2)

// Problem_Link: https://leetcode.com/problems/valid-perfect-square/description/

bool isPerfectSquare(int num) {
  int l = 0, r = num;
    int mid = 0, ans = 0;
    while(l <= r){
         mid = l + (r - l) / 2;
         if(1LL * mid * mid <= num){
            ans = mid;
            l = mid + 1;
         }
         else{
            r = mid - 1;
         }
    }
    return (ans * ans == num);        
}

#include<bits/stdc++.h>
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int nums = 14;
    int ans = isPerfectSquare(nums);
    cout << ans << "\n";
}