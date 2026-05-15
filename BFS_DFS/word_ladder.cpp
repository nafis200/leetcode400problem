// 0 - 3 months:
// Amazon (19) — Meta (10) — Google (6) — LinkedIn (5) — Apple (3) — TikTok (3)
// — eBay (3) — Bloomberg (2) — Reddit (2)

// 0 - 6 months:
// Microsoft (5) — Uber (2) — Samsung (2) — Snap (2) — Yelp (2)

// 6 months ago:
// Adobe (3) — PhonePe (3) — Box (3) — Citadel (2) — Agoda (2) — Salesforce (2)
// — Cruise (2) — Nutanix (2) — Yahoo (2) — MSCI (2)

// problem_Link: https://leetcode.com/problems/word-ladder/description/

// hit
//  |
// hot
//  / \
// dot lot
//  |    |
// dog  log
//   \  /
//    cog

#include <bits/stdc++.h>
using namespace std;

// time o(n * L) space o (n)

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
  set<string> st(wordList.begin(), wordList.end());

  st.insert(beginWord);

  if (st.find(endWord) == st.end()) {
    return 0;
  }
  queue<pair<string, int>> q;
  q.push({beginWord, 1});

  while (!q.empty()) {
    auto front = q.front();
    q.pop();
    string word = front.first;
    int steps = front.second;
    if (word == endWord) {
      return steps;
    }

    for (int i = 0; i < word.size(); i++) {
      string mainWord = word;
      for(char c = 'a'; c <= 'z'; c++){
         word[i] = c;
         if(st.find(word) != st.end()){
            q.push({word, steps + 1});
            st.erase(word);
         }
        }
        word = mainWord;
    }
  }
  return 0;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string beginWord = "hit";
  string endWord = "cog";

  vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

  cout << ladderLength(beginWord, endWord, wordList) << "\n";

  return 0;
}