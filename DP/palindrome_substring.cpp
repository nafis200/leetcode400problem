// 0 - 3 months:
// Meta (4) — Microsoft (3) — Capital One (2)

// 0 - 6 months:
// Amazon (3) — Bloomberg (3) — Oracle (2) — Walmart Labs (2) — Pure Storage (2)
// — Intuit (2) — HCL (2)

// 6 months ago:
// Google (22) — Citadel (19) — Salesforce (10) — Goldman Sachs (9) — LinkedIn
// (3) — PayPal (3) — Apple (2) — SoFi (2) — Epic Systems (2) — Cisco (2)

// Problem_Link: https://leetcode.com/problems/palindromic-substrings/

#include <bits/stdc++.h>
using namespace std;

// time o(n^3) space o(1)

// int n;

// bool palidrome(int l, int r, string &s){
//     bool ok = true;
//     while(l < r){
//         if(s[l] != s[r]){
//             ok = false;
//             break;
//         }
//         l++;
//         r--;
//     }
//     return ok;
// }

// int countSubstrings(string s) {
//      n = s.size();
//      int cnt = 0;

//      for(int i = 0; i < n; i++){
//         for(int j = i; j < n; j++){
//             if(palidrome(i, j, s)){
//                 cnt++;
//             }
//         }
//      }

//      return cnt;
// }

// madam
// abba

// time o(n^2) space o(1)

int countSubstrings(string s) {
  int n = s.size();
  int cnt = 0;
  // odd
  for (int center = 0; center < n; center++) {
    int l = center;
    int r = center;
    while (l >= 0 && r < n && s[l] == s[r]) {
      cnt++;
      l--;
      r++;
    }
  }

  // even

  for (int center = 1; center < n; center++) {
    int l = center - 1;
    int r = center;
    while (l >= 0 && r < n && s[l] == s[r]) {
      cnt++;
      l--;
      r++;
    }
  }
  return cnt;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s = "aaa";
  int ans = 0;
  ans = countSubstrings(s);
  cout << ans << "\n";
}