// 0 - 6 months: Zappos (2)
// 6 months ago: Amazon (9) — Microsoft (6) — Yandex (4) — Yahoo (4) — Adobe (3) — Google (2) — Bloomberg (2) — Apple (2) — Walmart Labs (2) — PayPal (2)

// Problem_Link: https://leetcode.com/problems/reverse-words-in-a-string-iii/description/

#include<bits/stdc++.h>
using namespace std;

// Time o(n) space o(n)

 string reverseWords(string s) {
     stringstream ss(s);
     string word;
     string ans;
     while(getline(ss, word, ' ')){
          reverse(word.begin(),word.end());
          ans += word;
          ans += " ";
     }
     ans.pop_back();
     return ans;
 }

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = "Let's take";

    string ans = reverseWords(s);
    cout << ans << "\n";
}