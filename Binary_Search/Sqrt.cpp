// Google (7) — Amazon (6) — TikTok (4) — tcs (2) — Zoho (2)
// 0 - 6 months: Meta (5) — Bloomberg (4) — Microsoft (3) — Apple (2) — Citadel (2)
// 6 months ago: Adobe (17) — Uber (15) — Yahoo (7) — Goldman Sachs (3) — Accenture (3) — SAP (3) — Infosys (2) — Oracle (2) — Morgan Stanley (2) — Samsung (2)

// Problem_Link: https://leetcode.com/problems/sqrtx/description/

#include<bits/stdc++.h>
using namespace std;

int mySqrt(int x) {
    int l = 0, r = x;
    int mid = 0, ans = 0;
    while(l <= r){
         mid = l + (r - l) / 2;
         if(1LL * mid * mid <= x){
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
    
    int ans = mySqrt(8);
}