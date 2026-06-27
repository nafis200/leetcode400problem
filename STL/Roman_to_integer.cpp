// Google (23) — Amazon (11) — Microsoft (5) — Bloomberg (4) — TCS (2) — Oracle
// (2) 0 - 6 months: Meta (6) — Uber (3) — Accenture (3) — DeltaX (3) — IBM (2)
// — Adobe (2) — LinkedIn (2) — Goldman Sachs (2) — Wix (2) — Yahoo (2) 6 months
// ago: Apple (77) — Zoho (4) — Wipro (2) — Citadel (2) — Visa (2) — Yandex (2)
// — eBay (2) — Intel (2) — Salesforce (2) — Twilio

// Problem_Link: https://leetcode.com/problems/roman-to-integer/description/

#include <bits/stdc++.h>
using namespace std;
int romanToInt(string s) {
  
  unordered_map<char, int> mp;
  mp['I'] = 1;
  mp['V'] = 5;
  mp['X'] = 10;
  mp['L'] = 50;
  mp['C'] = 100;
  mp['D'] = 500;
  mp['M'] = 1000;
  int sum = 0;
  for(int i = 0; i < s.size(); i++){
     if(i + 1 == s.size()){
        sum += mp[s[i]];
        continue;
     }
     if(i + 1 < s.size() && mp[s[i]] >= mp[s[i + 1]]){
         sum += mp[s[i]];
     }
     else{
        sum -= mp[s[i]];
     }
  }
  return sum;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s = "MCMXCIV";
  int ans = romanToInt(s);
  cout << ans << "\n";
}