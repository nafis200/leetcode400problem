// 0 - 3 months:
// Meta (2)

// 0 - 6 months:
// Google (2) — Microsoft (2) — Bloomberg (2) — Uber (2)

// 6 months ago:
// Nordstrom (3) — Docusign (2)

// https://leetcode.ca/all/266.html

#include<bits/stdc++.h>
using namespace std;

// time o(n * n!)

// bool isPalindrome(string s){
//     int l = 0;
//     int r = s.size()-1;

//     while(l < r){
//         if(s[l] != s[r]){
//             return false;
//         }
//         l++;
//         r--;
//     }
//     return true;
// }

// bool canPermutePalindrome(string s) {
//     sort(s.begin(), s.end());

//     do{
//         if(isPalindrome(s)){
//             return true;
//         }
//     }while(next_permutation(s.begin(), s.end()));

//     return false;
// }

// o(n)
bool canPermutePalindrome(string s) {
    unordered_map<char,int> mp;

    for(char c : s){
        mp[c]++;
    }

    int odd = 0;

    for(auto it : mp){
        if(it.second % 2 == 1){
            odd++;
        }
    }

    return odd <= 1;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}