// 0 - 3 months:
// Google (5) — Microsoft (4) — Amazon (3) — ByteDance (2)

// 0 - 6 months:
// Flipkart (2) — Booking.com (2)

// 6 months ago:
// Wise (11) — Meta (9) — PayPal (9) — Oracle (5) — TikTok (4) — Salesforce (4) — Karat (4) — Apple (3) — Goldman Sachs (3) — Citadel (3)

// Problem_Link: https://leetcode.com/problems/maximal-square/

#include <bits/stdc++.h>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));
    int mx = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == '1'){
                if(i == 0 || j == 0){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1],dp[i - 1][j - 1]});
                }
            }
            mx = max(mx, dp[i][j]);
        }
    }
    return 1LL * mx * mx;

}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    cout << maximalSquare(matrix);

    return 0;
}