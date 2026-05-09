

// Bloomberg (16) — Goldman Sachs (9) — Amazon (7) —
// Google (4) — Meta (2) — Walmart Labs (2)

// problem link:
// https://leetcode.com/problems/first-unique-character-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

// time complexity o(n^2) space o(1)

// int firstUniqChar(string s){
//     int ans = -1;
//     int n = s.size();
//     for(int i = 0; i < n; i++){
//         bool ok = true;
//         for(int j = 0; j < n; j++){
//             if(i == j){
//                 continue;
//             }
//             if(s[i] == s[j]){
//                 ok = false;
//             }
//         }
//         if(ok){
//             ans = i;
//             break;
//         }
//     }
//     return ans;
// }

// time o(nlogn) space o(n)

// int firstUniqChar(string s) {
//     int ans = -1;
//     map<char, int>mp;
//     for(auto i : s){
//         mp[i]++;
//     }
    
//     int n = (int)s.size();
//     for(int i = 0; i < n; i++){
//         if(mp[s[i]] == 1){
//             ans = i;
//             break;
//         }
//     }
//     return ans;
// }

// time o(n) space o(1)

int firstUniqChar(string s){
    int ans = -1;
    int n = s.size();
    int count[26] = {0};

    for(auto i : s){
        count[i - 'a']++;
    }

    for(int i = 0; i < n; i++){
        if(count[s[i] - 'a'] == 1){
            ans = i;
            break;
        }
    }
    return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);

  cin.tie(0);
  cout.tie(0);

  string s = "abba";

  int ans = firstUniqChar(s);
  cout << ans << "\n";
}