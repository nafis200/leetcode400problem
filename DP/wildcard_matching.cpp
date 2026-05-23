// 0 - 3 months:
// Bloomberg (3) — Google (2)

// 0 - 6 months:
// Meta (7) — Amazon (5) — Microsoft (3) — X (2) — Snap (2) — Two Sigma (2) — Instacart (2)

// 6 months ago:
// Apple (10) — Adobe (8) — Zoho (5) — Confluent (5) — Walmart Labs (3) — Uber (3) — Yahoo (3) — Salesforce (2) — Coursera (2)

// Problem_Link: https://leetcode.com/problems/wildcard-matching/description/

// string LCS

// aaaa
// a?a***


#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>memo;
int n, m;

int dp(int i, int j, string &s, string &p){
    if(i == n && j == m){
        return true;
    }
    if(i == n){
        for(int k = j; k < m; k++){
            if(p[k] != '*'){
                return false;
            }
        }
        return true;
    }
    if(j == m){
        return false;
    }
    if(memo[i][j] != -1){
        return memo[i][j];
    }
    bool ans = 0;
    if(s[i] == p[j] || p[j] == '?'){
        ans = dp(i + 1, j + 1, s ,p);
    }
    else if(p[j] == '*'){
        ans = dp(i + 1, j, s, p) || dp(i, j + 1, s , p);
    }
    return memo[i][j] = ans;

}

 bool isMatch(string s, string p) {
      n = s.size();
      m = p.size();
      memo.assign(n + 1, vector<int>(m + 1, -1));
      int ans = dp(0, 0, s, p);
      return ans;
 }
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = "aabcd";
    string p = "a?bc**";
    bool ans = isMatch(s, p);
    cout << ans << "\n";
}