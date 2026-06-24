// 0 - 3 months:
// Databricks (5) — Snowflake (4) — Google (3) — Meta (3) — Yandex (2)

// 0 - 6 months:
// Microsoft (3) — Amazon (2)

// 6 months ago:
// Bloomberg (12) — Apple (4) — Revolut (4) — Bolt (3) — Splunk (2) — Accenture (2) — Syfe (2)

// Problem_Link: https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

// abab
// ab
// 0 1 2

#include<bits/stdc++.h>
using namespace std;

// Time o(n) space o(1)

vector<int> findAnagrams(string s, string p) {
    
    int n = s.size();
    int m = p.size();
    vector<int>ans;
    if(m > n){
        return ans;
    }       
    vector<int>cnt(40),cnt1(40);
    for(auto i : p){
        cnt[i - 'a']++;
    }
    for(int i = 0; i < m; i++){
        cnt1[s[i] - 'a']++;
    }
    if(cnt == cnt1){
        ans.push_back(0);
    }

    for(int i = m; i < n; i++){
         cnt1[s[i - m] - 'a']--;
         cnt1[s[i] - 'a']++;
         if(cnt == cnt1){
            ans.push_back(i + 1 - m);
         }
    }
    return ans;
 }
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = "abab", p = "ab";

    vector<int>ans = findAnagrams(s, p);

    for(auto it : ans){
        cout << it << " ";
    }
}