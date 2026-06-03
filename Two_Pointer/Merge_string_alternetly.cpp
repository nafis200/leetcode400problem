// 0 - 3 months:
// Google (31) — Meta (7) — Amazon (6) — Microsoft (5) — Bloomberg (3)

// 0 - 6 months:
// IBM (3)

// 6 months ago:
// Adobe (25) — Apple (24) — Uber (8) — Yahoo (6) — Zoho (4) — tcs (2) — Walmart Labs (2) — Wells Fargo (2)

// Problem_Link: https://leetcode.com/problems/merge-strings-alternately/description/

#include<bits/stdc++.h>
using namespace std;

 string mergeAlternately(string word1, string word2) {
    int n1 = word1.size();
    int n2 = word2.size();
    int i = 0, j = 0;
    string s;
    while(i < n1 && j < n2){
        s += word1[i];
        s += word2[j];
        i++;
        j++;
    }

    if(i == n1){
        while(j < n2){
            s += word2[j];
            j++;
        }
    }
    else{
        while(i < n1){
            s += word1[i];
            i++;
        }
    }
    return s;
 }

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string word1 = "abc", word2 = "pqr";
    string ans = mergeAlternately(word1, word2);
    cout << ans << "\n";
}