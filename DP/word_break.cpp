// 0 - 3 months: Meta (18) — Amazon (8) — Microsoft (4) — TikTok (4) — Intuit (3) — Google (2) — Bloomberg (2) — BuyHatke (2)

// 0 - 6 months: Uber (3) — Salesforce (3) — LinkedIn (2) — Walmart Labs (2) — Coupang (2) — Yahoo (2) — Block (2) — Otter.ai (2) — MongoDB (2) — Pocket Gems (2)

// 6 months ago: Apple (15) — Adobe (13) — Tesla (5) — Oracle (4) — Flipkart (3) — Zoho (3) — eBay (3) — Grammarly (3) — IBM (2) — Nordstrom (2)

// Problem_Link: https://leetcode.com/problems/word-break/description/


#include<bits/stdc++.h>
using namespace std;

// time o(n^3) space o(n + m * k)

// vector<int>memo;
// unordered_set<string>st;
// int n;

// bool solve(int i, string &s){
//    if(i == n){
//      return true;
//    }
//    if(memo[i] != -1){
//     return memo[i];
//    }
//    for(int j = i; j < n; j++){
//        string s1 = s.substr(i, j - i + 1);
//        if(st.count(s1)){
//           if(solve(j + 1, s)){
//             return memo[i] = 1;
//           }
//        }
//    }
//    return memo[i] = 0;
// }

// bool wordBreak(string s, vector<string>& wordDict) {
//    n = s.size();
//    memo.assign(n, -1);
//    st.insert(wordDict.begin(),wordDict.end());
//    bool ans = solve(0, s);
//    return ans;
// }


// timeo(n^3) space o(n)

// vector<int>memo;
// int n;

// bool solve(int i, string &s,vector<string>& wordDict){
//    if(i == n){
//      return true;
//    }
//    if(memo[i] != -1){
//     return memo[i];
//    }
//    for(auto word : wordDict){
//       int len = word.size();
//       if(i + len <= n && s.substr(i,len) == word){
//          if(solve(i + len, s, wordDict)){
//             return memo[i] = true;
//          }
//       }

//    }
//    return memo[i] = 0;
// }

// bool wordBreak(string s, vector<string>& wordDict) {
//    n = s.size();
//    memo.assign(n, -1);
  
//    bool ans = solve(0, s, wordDict);
//    return ans;
// }

 bool wordBreak(string s, vector<string>& wordDict) {

        int n = s.size();

        vector<bool> dp(n + 1, false);

        dp[0] = true;

        for(int i = 1; i <= n; i++) {

            for(auto word : wordDict) {

                int len = word.size();

                if(i >= len &&
                   dp[i - len] &&
                   s.substr(i - len, len) == word) {

                    dp[i] = true;
                }
            }
        }

        return dp[n];
    }


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = "catsandog";
    vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
    bool ans = wordBreak(s, wordDict);
}