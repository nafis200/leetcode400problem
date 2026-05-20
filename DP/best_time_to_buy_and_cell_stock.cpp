// Amazon (34) — Google (22) — Meta (18) — Microsoft (12) — Bloomberg (9) — Morgan Stanley (5) — TikTok (4) — Nvidia (3) — Accenture (3) — Salesforce (3)


// problem_Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

#include<bits/stdc++.h>
using namespace std;

// time o(n) space o(1)

//  int maxProfit(vector<int>& prices) {
//     int n = prices.size();
//     int mx = prices[n - 1];
//     int ans = 0;
//     for(int i = n - 2; i >= 0; i--){
//         if(prices[i] > mx){
//             mx = prices[i];
//         }
//         else{
//             if(prices[i] < mx){
//                 ans = max(ans, mx - prices[i]);
//             } 
//         }
//     }
//     return ans;
//  }


// time o(n ^ 2) space o(1)

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int ans = 0;
    for(int i = n - 1; i > 0; i--){
        for(int j = i - 1; j >= 0; j--){
            ans = max(ans, prices[i] - prices[j]);
        }
    }
    return ans;
 }


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>prices = {7,1,5,3,6,4};
    int ans = maxProfit(prices);
    cout << ans << "\n";
}