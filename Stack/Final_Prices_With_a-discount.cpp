// 6 months ago:
// Google (7) — Microsoft (5) — Meta (2) — Amazon (2) — Bloomberg (2) — Dream11 (2) — Accenture (2)

// Problem_Link: https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/?envType=problem-list-v2&envId=stack

#include<bits/stdc++.h>
using namespace std;

// Time o(n ^ 2) space o(1)

// vector<int> finalPrices(vector<int>& prices) {
//     vector<int>ans;
//     int sz = prices.size() - 1;
//     for(int i = 0; i <= sz; i++){
//         bool ok = true;
//         for(int j = i + 1; j <= sz; j++){
//             if(prices[j] <= prices[i]){
//                 ans.push_back(prices[i] - prices[j]);
//                 ok = false;
//                 break;
//             }
//         }
//         if(ok){
//             ans.push_back(prices[i]);
//         }
//     }        
//     return ans;
// }


vector<int> finalPrices(vector<int>& prices) {
    int n = prices.size();
    vector<int>ans(n);
    stack<int>st;
    for(int i = n - 1; i >= 0; i--){
         while (!st.empty() && prices[i] < st.top())
         {
            st.pop();
         }
         if(st.size() > 0){
            ans[i] = (prices[i] - st.top());
         }
         else{
            ans[i] = (prices[i]);
         }
         st.push(prices[i]);
         
    }
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int>prices = {8,4,6,2,3};
    vector<int>ans = finalPrices(prices);
    for(auto i : ans){
        cout << i << " ";
    }
}