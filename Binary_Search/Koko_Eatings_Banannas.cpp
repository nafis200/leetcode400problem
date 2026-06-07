// 0 - 3 months:
// Amazon (16) — Google (15) — Microsoft (8) — Bloomberg (5) — IBM (2) — Oracle (2)

// 0 - 6 months:
// Meta (11) — DoorDash (2) — Snap (2)

// 6 months ago:
// Uber (11) — Flipkart (9) — Turing (8) — TikTok (7) — Atlassian (5) — Accenture (5) — DE Shaw (4) — TCS (3) — LinkedIn (3) — Citadel (3)

// Problem_Link: https://leetcode.com/problems/koko-eating-bananas/

#include<bits/stdc++.h>
using namespace std;

// Time o(n * h)

// bool isFinished(vector<int>& piles, int h, int k){
//     int n = piles.size();
//     long long sum = 0;
//     for(int i = 0; i < n; i++){
//         sum += 1LL * (piles[i] + k - 1) / k;
//     }
//     if(sum <= h){
//         return true;
//     }
//     return false;
// }

//  int minEatingSpeed(vector<int>& piles, int h) {
//        int ans = 0;
//        for(int i = 1; i <= 1e9; i++){
//           if(isFinished(piles, h, i)){
//              ans = i;
//              break;
//           }
//        }
//        return ans;
//  }


// Time o(nlogh) space o(1)

bool isFinished(vector<int>& piles, int h, int k){
    int n = piles.size();
    long long sum = 0;
    for(int i = 0; i < n; i++){
        sum += 1LL * (piles[i] + k - 1) / k;
    }
    if(sum <= h){
        return true;
    }
    return false;
}

 int minEatingSpeed(vector<int>& piles, int h) {
       int ans = 0;
       int l = 1, r = 1e9;
       while(l <= r){
          int mid = l + (r - l) / 2;
          if(isFinished(piles, h, mid)){
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

    vector<int> piles = {3, 6, 7, 11};

    int h = 8;

    int ans = minEatingSpeed(piles, h);

    cout << ans << "\n";
}