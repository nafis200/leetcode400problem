// 0 - 3 months:
// Google (2) — Bloomberg (2) — Zoho (2)

// 0 - 6 months:
// Meesho (3) — Microsoft (2) — Amazon (2)

// 6 months ago:
// Salesforce (12) — Meta (7) — J.P. Morgan (3) — Oracle (3) — Walmart Labs (2) — Coupang (2) — Trilogy (2)

// https://leetcode.com/problems/distinct-subsequences/

#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>>memo;

// time o(n * m) space o(n * m)

int dp(int i, int j, string &s, string &t){
     if(i == n){
        if(j == m){
            return 1;
        }
        return 0;
     }
     if(j == m){
        return 1;
     }
     if(memo[i][j] != -1){
        return memo[i][j];
     }
     int ans = 0;
     if(s[i] == t[j]){
        ans = dp(i + 1, j + 1, s, t) + dp(i + 1, j, s, t);
     }
     else{
         ans += dp(i + 1, j, s, t);
     }
     return memo[i][j] = ans;
     
}


 int numDistinct(string s, string t) {
    n = s.size();
    m = t.size();
    int ans = 0;
    memo.assign(n, vector<int>(m, -1));
    ans = dp(0, 0, s, t);
    return ans;
 }

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = "rabbbit", t = "rabbit";
    int ans = numDistinct(s, t);
    cout << ans << "\n";
}