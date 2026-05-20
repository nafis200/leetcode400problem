 

 	// Google (22) — Amazon (14) — Microsoft (7) — Accenture (6) — Meta (4) — TikTok (2) — Goldman Sachs (2) — Grammarly (2)

    // Problem_Link: https://leetcode.com/problems/climbing-stairs/description/

    // time o(n) space o(n)

    #include<bits/stdc++.h>
    using namespace std;
    vector<int>dp;

    // int f(int n){
    //     if(n == 0){
    //         return 1;
    //     }
    //     if(n < 0){
    //         return 0;
    //     }
    //     if(dp[n] != -1){
    //         return dp[n];
    //     }
    //     return dp[n] = f(n - 1) + f(n - 2);


    // }

    // int climbStairs(int n) {
    //     dp.assign(n + 2, -1);
    //     dp[0] = 1;
    //     int ans = f(n);
    //     return ans;
    // }


   

    int climbStairs(int n) {
        dp.assign(n + 2, -1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    int32_t main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = 3;
        int ans = climbStairs(n);
        cout << ans << "\n";
    }