// 0 - 3 months:
// Amazon (2)

// 0 - 6 months:
// Google (3)

// 6 months ago:
// Meta (8) — Microsoft (5) — Bloomberg (5)

// problem_Link: https://leetcode.com/problems/min-cost-climbing-stairs/description/

#include<bits/stdc++.h>
using namespace std;
vector<int>memo;
int n;

int dp(int i,vector<int>& cost){
   if(i == n){
     return 0;
   }
   if(i > n){
    return 1e9;
   }
   if(memo[i] != -1){
     return memo[i];
   }
   int ans = 1e9;
   int oneStep = dp(i + 1, cost) + cost[i];
   int twoStep = dp(i + 2, cost) + cost[i];
   ans = min(oneStep,twoStep);
   return memo[i] = ans;
}

int minCostClimbingStairs(vector<int>& cost) {
    n = cost.size();
    memo.assign(n, -1);
    int ans = dp(0, cost);
    //  memo.assign(n, -1);
    ans = min(ans, dp(1, cost));
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>cost = {10,15,20};
    int ans = 0;
    ans = minCostClimbingStairs(cost);
    cout << ans << "\n";
}