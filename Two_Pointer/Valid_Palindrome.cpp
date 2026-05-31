// Meta (48) — Google (5) — Amazon (4) — Microsoft (2) — Apple (2)
// 0 - 6 months: Bloomberg (4) — Uber (3) — tcs (2) — Goldman Sachs (2) — Zenefits (2)
// 6 months ago: Yandex (45) — Adobe (21) — Yahoo (6) — EPAM Systems (5) — Toast (5) — Spotify (4) — TikTok (3) — Accenture (3) — Deloitte (2) — Wipro (2)

// Problem_Link: https://leetcode.com/problems/valid-palindrome/description/

#include<bits/stdc++.h>
using namespace std;

// time o(n) space o(n)

// bool palindrome(string &s){
//    int n = s.size();
//    int l = 0, r = n - 1;
//    while(l < r){
//       if(s[l] != s[r]){
//         return false;
//       }
//       l++;
//       r--;
//    }
//    return true;
// }

// bool isPalindrome(string s) {
//    string s1;
//    for(int i = 0; i < (int)s.size(); i++){
//         if(s[i] >= 'a' && s[i] <= 'z'){
//             s1 += s[i];
//         }
//         else if(s[i] >= 'A' && s[i] <= 'Z'){
//             s1 += tolower(s[i]);
//         }
//         else if(s[i] >= '0' && s[i] <= '9'){
//             s1 += s[i];
//         }
//    }
   
//    return palindrome(s1);
// }

// time o(n) space o(1)

bool palindrome(string &s, int n){
   int l = 0, r = n - 1;
   while(l < r){
      if(s[l] != s[r]){
        return false;
      }
      l++;
      r--;
   }
   return true;
}

bool isPalindrome(string s) {
 
   int j = 0;
   for(int i = 0; i < (int)s.size(); i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
             s[j] = s[i];
             j++;       
        }
        else if(s[i] >= 'A' && s[i] <= 'Z'){
           s[j] = tolower(s[i]);
           j++;
        }
        else if(s[i] >= '0' && s[i] <= '9'){
           s[j] = s[i];
           j++;
        }
   }
  
   return palindrome(s, j);

}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s ="A man, a plan, a canal: Panama";

    bool ans = isPalindrome(s);
    cout << ans << "\n";

}