
// Bloomberg (15) — Google (13) — Amazon (9)
// — Microsoft (6) — Apple (3) — Meta (2) — EPAM Systems (2) — Affirm (2)

// problem_link: https://leetcode.com/problems/valid-anagram/description/

#include <bits/stdc++.h>
using namespace std;

// time complexity o(nlogn) space o(1)

// bool isAnagram(string s, string t){
//     sort(s.begin(),s.end());
//     sort(t.begin(),t.end());
//     if(s == t){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// } 

// time o(n) space o(1)

bool isAnagram(string s, string t){
    int freq[26] = {0};

    for(auto i : s){
        freq[i - 'a']++;
    }
    for(auto i : t){
        freq[i - 'a']--;
    }

    for(int i = 0; i < 26; i++){
        if(freq[i] != 0){
            return 0;
        }
    }
    return 1;
} 

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s, t; cin >> s >> t;

  int ans = isAnagram(s, t);
  cout << ans << "\n";

}
