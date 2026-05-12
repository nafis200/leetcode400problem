// 0 - 3 months:
// Amazon (5) — Google (4) — Microsoft (4) — Meta (3) — Apple (3)

// 0 - 6 months:
// LinkedIn (3) — Bloomberg (2) — Oracle (2) — TikTok (2)

// 6 months ago:
// Accenture (6) — TCS (5) — Nvidia (5) — Infosys (4) — Zopsmart (4) — IBM (3) —
// Zoho (3) — Cisco (3) — Adobe (2) — EPAM Systems (2)

// problem link: https://leetcode.com/problems/reverse-words-in-a-string/

#include <bits/stdc++.h>
using namespace std;

// time o(n) space o(n)

// string reverseWords(string s) {
//     vector<string>ans;
//     stringstream ss(s);
//     string temp;
//     while(getline(ss, temp, ' ')){
//         if(temp != ""){
//            ans.push_back(temp);
//         }
//     }

//     string s1 = "";
//     int n = ans.size() - 1;

//     for(int i = n; i >= 0; i--){
//        s1 += ans[i];
//        if(i != 0){
//          s1 += " ";
//        }
//     }
//     return s1;
// }

string reverseWords(string s) {
  int i = 0, j = 0;
  int n = s.size();
  while (j < n) {
    while (j < n && s[j] == ' ') {
      j++;
    }
    while(j < n && s[j] != ' '){
       s[i] = s[j];
       j++;
       i++;
    }
    while(j < n && s[j] == ' '){
      j++;
    }
    if(j < n){
       s[i] = ' ';
       i++;
    }
  }
  s.resize(i);
  return s;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s = "  hello   world  ";

  string ans = reverseWords(s);
  cout << ans << "\n";
}