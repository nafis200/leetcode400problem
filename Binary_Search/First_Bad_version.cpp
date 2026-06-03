// Google (5) — Meta (5) — Microsoft (2) — Amazon (2) — Apple (2)

// Problem_Link: https://leetcode.com/problems/first-bad-version/description/


#include<bits/stdc++.h>
using namespace std;

bool isBadVersion(int version){
    if(version >= 4){
        return true;
    }
    return false;
}

// Time o(n)

// int firstBadVersion(int n) {
//    int l = 1, r = n;
//    for(int i = 1; i <= n; i++){
//       if(isBadVersion(i)){
//         return i;
//       }
//    }   
//    return -1;  
// }

int firstBadVersion(int n) {
   int l = 1, r = n;
   int ans = -1; 
   while(l <= r){
      int mid = l + (r - l) / 2;
      if(isBadVersion(mid)){
         r = mid - 1;
         ans = mid;
      }
      else{
         l = mid + 1;
      }
   }
   return ans;  
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; 
    n = 5;
    
}