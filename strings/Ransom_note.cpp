// 0 - 3 months:
// Google (6) — Amazon (2)

// 0 - 6 months:
// Meta (2) — Karat (2)

// 6 months ago:
// Microsoft (22) — Bloomberg (11) — Apple (4) — Disney (4) — Spotify (3) — Criteo (2) — Uber (2) — Tripadvisor (2)


// problem_link: https://leetcode.com/problems/ransom-note/

#include<bits/stdc++.h>
using namespace std;

// time complexity n(nlogn) space o(1)

//  bool canConstruct(string ransomNote, string magazine) {
    
//     string s = ransomNote;
//     string t = magazine;

//     sort(s.begin(),s.end());
//     sort(t.begin(),t.end());

//     int n = s.size();
//     int n1 = t.size();

//     int j = 0;

//     for(int i = 0; i < n1; i++){
//         if(j < n && s[j] == t[i]){
//             j++;
//         }
//     }
//     if(j == n){
//         return true;
//     }
//     return false;
//  }

// time o(n) space o(1)

bool canConstruct(string ransomNote, string magazine) {
    
    string s = ransomNote;
    string t = magazine;

    unordered_map<char,int>r,m;
    for(auto i : s){
        r[i]++;
    }

    for(auto i : t){
        m[i]++;
    }

    bool ok = true;

    for(auto it : r){
        if(!m.count(it.first)){
             ok = false;
        }
        if(m.count(it.first) && it.second > m[it.first]){
            ok = false;
        }
    }
   return ok;
 }


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s, t;

    s = "aac";
    t = "aab";

    bool ans = canConstruct(s, t);
    cout << ans << "\n";
}