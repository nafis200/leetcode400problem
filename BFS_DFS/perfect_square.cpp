// 0 - 3 months:
// Google (4)

// 0 - 6 months:
// Microsoft (3) — Amazon (3)

// 6 months ago:
// Bloomberg (9) — Revolut (6) — Yandex (6) — Accenture (3) — Adobe (2) — Walmart Labs (2) — Goldman Sachs (2) — Zoho (2) — Citadel (2)

// problem_Link: https://leetcode.com/problems/perfect-squares/description/

#include<bits/stdc++.h>
using namespace std;
 int numSquares(int n) {
    vector<int>dp(n + 2, INT_MAX);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j * j <= i; j++){
            int square = j * j;
            dp[i] = min(dp[i],dp[i - square] + 1);
        }
    }
    return dp[n];
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 12;
    int ans = numSquares(n);
    cout << ans << "\n";

}