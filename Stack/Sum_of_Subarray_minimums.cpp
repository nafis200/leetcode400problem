// 0 - 3 months:
// Amazon (6) — Google (2)

// 0 - 6 months:
// Bloomberg (2) — TikTok (2) — Sprinklr (2)

// 6 months ago:
// Microsoft (13) — Meta (12) — Flipkart (4) — Apple (3) — Avito (2)

// Problem_Link: https://leetcode.com/problems/sum-of-subarray-minimums/description/

#include<bits/stdc++.h>
using namespace std;
 int mod = 1e9 + 7;
 int sumSubarrayMins(vector<int>& arr) {
   long long sum = 0;
   int n = arr.size();
   int mn = INT_MAX;
   for(int i = 0; i < n; i++){
     mn = INT_MAX;
     for(int j = i; j < n; j++){
         if(i == j){
            sum += arr[j] % mod;
         }
         else{
           sum = (sum + mn + arr[j]) % mod;
         }
         mn = min(mn, arr[j]);
     }
   }   
   return mn;    
 }
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> arr = {3,1,2,4};
}