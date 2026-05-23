// 0 - 3 months:
// Google (6) — Amazon (6) — Meta (3) — Bloomberg (3) — TikTok (2)

// 0 - 6 months:
// Microsoft (5) — Apple (4) — ByteDance (2) — Uber (2) — Airbnb (2) — X (2) — Snowflake (2) — WorldQuant (2)

// 6 months ago:
// Yahoo (6) — Citadel (4) — Confluent (4) — Coupang (4) — Adobe (3) — Zoho (3) — Oracle (2) — Turing (2) — Coursera (2) — Luxoft (2)

// problem_Link: https://leetcode.com/problems/regular-expression-matching/submissions/2010360949/


#include<bits/stdc++.h>
using namespace std;

// a* here a* means 0, or aa, aaa.....
// main difference * star are not set aloneit is always set with character

// ab
// a*ab
// true

vector<vector<int>>memo;
int n, m;

int dp(int i,int j,string &s,string &p){

    if(j == m){
        return i == n;
    }

    if(memo[i][j] != -1){
        return memo[i][j];
    }

    bool firstMatch =
        (i < n &&
        (s[i] == p[j] || p[j] == '.'));

    bool ans = false;

    if(j + 1 < m && p[j+1] == '*'){

        ans =
            dp(i,j+2,s,p);

        if(firstMatch){
            ans |= dp(i+1,j,s,p);
        }
    }
    else{

        if(firstMatch){
            ans = dp(i+1,j+1,s,p);
        }
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
}
    