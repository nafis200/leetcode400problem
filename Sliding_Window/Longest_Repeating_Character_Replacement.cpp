// 0 - 3 months:
// Google (13) — Microsoft (7) — Amazon (4) — Meta (2) — Bloomberg (2)

// 0 - 6 months:
// ServiceNow (2)

// 6 months ago:
// Goldman Sachs (7) — Uber (4) — Yandex (4) — Adobe (3) — Apple (3) — TikTok (3) — Flipkart (2) — ByteDance (2) — Zepto (2) — DocuSign (2)

// Problem_Link: https://leetcode.com/problems/longest-repeating-character-replacement/description/

#include<bits/stdc++.h>
using namespace std;
// AAAA
// Time o(n) space o(1)
int characterReplacement(string s, int k) {
     int n = s.size();
     int ans = 0;
     for(char c = 'A'; c <= 'Z'; c++){
         int l = 0;
         int diff = 0;
         for(int r = 0; r < n; r++){
             if(s[r] != c){
                diff++;
             }
             while(diff > k){
                 if(s[l] != c){
                    diff--;
                 }
                  l++;
             }
             ans = max(ans, r - l + 1);
         }
     }
     return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = "AABABBA";
    int k = 1;
    int ans = characterReplacement(s, k);

    cout << ans << "\n";
}