// 0 - 3 months:
// Amazon (6) — Google (5) — Apple (3)

// 0 - 6 months:
// Meta (6) — Microsoft (3) — TikTok (3) — Goldman Sachs (3) — ServiceNow (3) — Careem (2)

// 6 months ago:
// Bloomberg (23) — Visa (3) — J.P. Morgan (2) — Infosys (2) — TCS (2) — Walmart Labs (2) — Zoho (2) — DE Shaw (2) — Nvidia (2) — Nike (2)

// Problem_Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

#include<bits/stdc++.h>
using namespace std;
 int maxProfit(vector<int>& prices) {
     int profit = 0;
     for(int i = 1; i < prices.size(); i++){
         if(prices[i] > prices[i - 1]){
             profit += prices[i] - prices[i - 1];
         }
     }       
     return profit;
 }
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

}