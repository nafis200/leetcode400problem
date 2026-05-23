// 0 - 3 months:
// Google (5) — Micro1 (2)

// 0 - 6 months:
// Meta (4) — Amazon (3) — Microsoft (2)

// 6 months ago:
// Bloomberg (8) — Salesforce (8) — DoorDash (5) — Oracle (3) — ByteDance (3) — Walmart Labs (3) — TikTok (3) — Optum (3) — Accolite (2) — TCS (2)

// Problem_Link: https://leetcode.com/problems/longest-common-subsequence/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>memo;
int n, m;

int dp(int i, int j, string &s, string & t){
   if(i == n || j == m){
     return 0;
   }
   if(memo[i][j] != -1){
    return memo[i][j];
   }
   int ans = 0;
   if(s[i] == t[j]){
     ans += dp(i + 1, j + 1, s, t) + 1;
   }
   ans = max(ans, dp(i + 1, j, s, t));
   ans = max(ans, dp(i, j + 1, s, t));
   return memo[i][j] = ans;
}

int longestCommonSubsequence(string text1, string text2) {
     n = text1.size();
     m = text2.size();
     memo.assign(n, vector<int>(m,-1));
     int ans = 0;
     ans = dp(0, 0, text1, text2);
     return ans;   
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s, t;
    s = "ace";
    t = "abcde";
    int ans = longestCommonSubsequence(s, t);
    cout << ans << "\n";
}