// Meta (116) — Google (3) — Amazon (3) — Yandex (3) — TikTok (2) — Attentive
// (2)

#include <bits/stdc++.h>
using namespace std;

// Problem_Link: https://leetcode.com/problems/valid-palindrome-ii/description/

// time o(n ^ 2) space o(1)

// bool isPalindrome(string s, int i) {
//   int l = 0, r = s.size() - 1;

//   while (l < r) {
//     if (l == i) {
//       l++;
//     }
//     if (r == i) {
//       r--;
//     }
//     if(l > r){
//         return true;
//     }
//     if(s[l] != s[r]){
//         return false;
//     }
//     l++;
//     r--;
//   }
//   return true;
// }

// bool validPalindrome(string s) {
//   int n = s.size();

//   for (int i = 0; i < n; i++) {
//     if(isPalindrome(s, i)){
//         return true;
//     }
//   }
//   return false;
// }

bool isPalindrome(string &s, int l, int r){
    
    while(l < r){
        if(s[l] != s[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}

bool validPalindrome(string s) {
  int n = s.size();
  int l = 0, r = n - 1;
  while(l < r){
     if(s[l] != s[r]){
        return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
     }
     l++;
     r--;
  }
  return true;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s = "abca";
  bool ans = validPalindrome(s);
  cout << ans << "\n";
}