

// 0 - 6 months: Amazon (2) — Tripadvisor (2)
// 6 months ago: Bloomberg (11) — Meta (6) — Google (5) — Microsoft (4) — Apple
// (3) — Yahoo (3) — Uber (2)

// problem link:
// https://leetcode.com/problems/find-common-characters/description/

#include <bits/stdc++.h>
using namespace std;

// time o(n * k) space o (n)

// vector<string> commonChars(vector<string>& words) {
//   vector<string> ans;

//   map<char, vector<int>> mp;
//   for (auto s : words) {
//     int freq[26] = {0};

//     for (auto i : s) {
//       freq[i - 'a']++;
//     }
//     for (int i = 0; i < 26; i++) {
//       mp[i + 'a'].push_back(freq[i]);
//     }
//   }

//   for (auto v : mp) {
//     int g = 1e9;

//     for (auto i : v.second) {
//       g = min(g, i);
//     }

//     char c = v.first;
//     while (g > 0) {
//       string word(1, c);
//       ans.push_back(word);
//       g--;
//     }
//   }

//   return ans;
// }


// time o(n * k) space o(1)

vector<string> commonChars(vector<string>& words) {
  vector<string> ans;
  int minFreq[26];
  for (int i = 0; i < 26; i++) {
    minFreq[i] = 1e9;
  }
  for (auto s : words) {
    int freq[26] = {0};
    for (auto i : s) {
      freq[i - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
      minFreq[i] = min(minFreq[i], freq[i]);
    }
  }
  for(int i = 0; i < 26; i++){
     while(minFreq[i] > 0){
        string c = string(1, i + 'a');
        ans.push_back(c);
        minFreq[i]--;
     }
  }

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<string> words = {"bella", "label", "roller"};

  vector<string> ans = commonChars(words);
  for (auto it : ans) {
    cout << it << " ";
  }
}