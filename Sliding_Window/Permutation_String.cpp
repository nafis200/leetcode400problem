// 0 - 3 months:
// Amazon (4) — Google (3) — Microsoft (2) — Bloomberg (2) — Walmart Labs (2) — Yandex (2)

// 0 - 6 months:
// Databricks (4) — Meta (2)

// 6 months ago:
// Oracle (4) — TikTok (3) — Goldman Sachs (3) — TCS (2) — Adobe (2) — Cisco (2) — Accenture (2)

// Problem_Link: https://leetcode.com/problems/permutation-in-string/description/

// abc
// badd
// 
// l = 0 
// r = 0 r = 1 r = 2
// abb
// aba
// eidbaooo
#include<bits/stdc++.h>
using namespace std;

// o(n^mlogn logn space o(n*m))

// bool checkInclusion(string s1, string s2) {
//     sort(s1.begin(),s1.end());
//     int n = s2.size();
//     unordered_set<string>st;
//     for(int i = s1.size() - 1; i < n; i++){
//         int l = i - s1.size() + 1;
//         string s = s2.substr(l, s1.size());
//         sort(s.begin(),s.end());
//         st.insert(s);
//     }
//     if(st.find(s1) != st.end()){
//         return true;
//     }
//     return false;
            
// }
// Time o(n) space o(1)
bool checkInclusion(string s1, string s2) {
    vector<int>cnt(30),cnt1(30);
    for(auto it : s1){
        cnt[it - 'a']++;
    }        
    int n = s1.size();
    int m = s2.size();
    if(n > m){
        return false;
    }

    for(int i = 0; i < n; i++){
        cnt1[s2[i] - 'a']++;
    }
    if(cnt == cnt1){
        return true;
    }
    for(int i = n; i < m; i++){
        cnt1[s2[i] - 'a']++;
        cnt1[s2[i - n] - 'a']--;
        if(cnt == cnt1){
            return true;
        }
    }
    return false;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s1 = "ab", s2 = "eidbaooo";

    bool ans = checkInclusion(s1, s2);
    cout << ans << "\n";
}