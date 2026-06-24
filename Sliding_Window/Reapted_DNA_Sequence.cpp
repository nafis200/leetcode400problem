// 0 - 6 months:
// LinkedIn (4) — Meta (2) — Bloomberg (2)

// 6 months ago:
// Google (12) — Grammarly (11) — Amazon (10) — Microsoft (4)

// Problem_Link: https://leetcode.com/problems/repeated-dna-sequences/

// AAACC
// 0 + 4 < n

#include<bits/stdc++.h>
using namespace std;
vector<string> findRepeatedDnaSequences(string s) {
    int n = s.size();
    vector<string>ans;
    map<string,int>mp;
    for(int i = 0; i + 9 < n; i++){
        string sub = s.substr(i, 10);
        mp[sub]++;
    }       
    for(auto it : mp){
        if(it.second > 1){
            ans.push_back(it.first);
        }
    }
    return ans;
 }
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string>ans = findRepeatedDnaSequences(s);
    for(auto it : ans){
        cout << it << "\n";
    }
}