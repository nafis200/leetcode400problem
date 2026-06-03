// 0 - 3 months:
// Google (5) — Meta (5) — Salesforce (5) — Microsoft (4) — Yandex (4) —
// ServiceNow (3) — Amazon (2) — Bloomberg (2) — Apple (2) — Nvidia (2)

// 0 - 6 months:
// Goldman Sachs (3) — Affirm (3) — IBM (2) — EPAM Systems (2) — Palo Alto
// Networks (2) — Snap (2) — Lyft (2) — Yelp (2) — GoDaddy (2) — Expedia (2)

// 6 months ago:
// Adobe (9) — Uber (7) — TikTok (6) — Pinterest (6) — Yahoo (5) — Oracle (4) —
// Zoho (2) — PhonePe (2) — ZScaler (2) — CrowdStrike (2)

// Problem_Link: https://leetcode.com/problems/string-compression/description/

#include <bits/stdc++.h>
using namespace std;

//  a bb a
//  a b2 a

//  aabbccc
// a2b2c3

// ans = 6 and vector resize

// Time o(n) space o(1)

int compress(vector<char>& chars) {
  int i = 0, index = 0;
  while (i < (int)chars.size()) {
    char ch = chars[i];
    int count = 0;
    while (i < chars.size() && ch == chars[i]) {
      count++;
      i++;
    }
    chars[index] = ch;
    index++;
    
    if(count > 1){
       string len = to_string(count);
    //    "12"
       for(auto ch : len){
          chars[index] = ch;
          index++;
       }
    }
  }
  return index;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<char> chars = {'a', 'b', 'b', 'b', 'b', 'b', 'b',
                        'b', 'b', 'b', 'b', 'b', 'b'};

  int ans = compress(chars);

  cout << ans << "\n";

  for (auto ch : chars) {
    cout << ch << " ";
  }
}