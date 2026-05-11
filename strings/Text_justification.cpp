

// 0 - 3 months:
// Capital One (8) — Visa (5) — TikTok (4) — Roblox (3) — Google (2) — Robinhood
// (2) — Anyscale (2)

// 0 - 6 months:
// Microsoft (4) — Meta (3) — Amazon (2) — Airbnb (2) — Karat (2) — Lime (2) —
// Sentry (2)

// 6 months ago:
// Uber (28) — Moveworks (16) — Coursera (10) — Atlassian (9) — Databricks (6) —
// SIG (6) — BCG (6) — Bloomberg (5) — Apple (5) — MongoDB (5)

// problem link: https://leetcode.com/problems/text-justification/

#include <bits/stdc++.h>
using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
  int n = words.size();
  int i = 0;
  vector<string> result;
  while (i < n) {
    int j = i + 1;
    int lineLength = words[i].size();
    while (j < n && lineLength + 1 + words[j].size() <= maxWidth) {
      lineLength += 1 + words[j].size();
      j++;
    }

    int wordCount = j - i;
    int numSpaces = maxWidth - (lineLength - (wordCount - 1));
    string line = "";
    if (wordCount == 1 || j == n) {
      for (int k = i; k < j; k++) {
        line += words[k];
        if(line.length() < maxWidth){
            line += " ";
        }
      }
      while (line.size() < maxWidth) {
        line += " ";
      }
    } else {
      int spaceBetween = numSpaces / (wordCount - 1);
      int extraSpace = numSpaces % (wordCount - 1);
      for (int k = i; k < j; k++) {
        line += words[k];
        if (k < j - 1) {
          int spaceApply = spaceBetween;
          if (extraSpace) {
            spaceApply += 1;
            extraSpace--;
          }
          while (spaceApply) {
            line += " ";
            spaceApply--;
          }
        }
      }
    }
    result.push_back(line);
    i = j;
  }
  return result;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<string> word = {"This","is","an","example","of","text" "justification."};

  int maxWidth = 16;

  vector<string> ans = fullJustify(word, maxWidth);

  for (auto i : ans) {
    cout << i << "\n";
  }
}