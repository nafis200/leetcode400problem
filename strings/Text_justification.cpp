

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

//    vector<string> fullJustify(vector<string>& words, int maxWidth) {

//         vector<string> ans;
//         int n = words.size();

//         int i = 0;

//         while(i < n) {

//             int j = i;
//             int totalChars = 0;

//             while(j < n &&
//                   totalChars + words[j].size() + (j - i) <= maxWidth) {

//                 totalChars += words[j].size();
//                 j++;
//             }

//             int wordCount = j - i;
//             string line = "";

//             if(j == n || wordCount == 1) {

//                 line += words[i];

//                 for(int k = i + 1; k < j; k++) {
//                     line += " ";
//                     line += words[k];
//                 }

//                 while(line.size() < maxWidth) {
//                     line += ' ';
//                 }
//             }
//             else {

//                 int gaps = wordCount - 1;

//                 int totalSpaces = maxWidth - totalChars;

//                 int evenSpace = totalSpaces / gaps;

//                 int extra = totalSpaces % gaps;

//                 for(int k = i; k < j - 1; k++) {

//                     line += words[k];

//                     line += string(evenSpace, ' ');

//                     if(extra > 0) {
//                         line += ' ';
//                         extra--;
//                     }
//                 }
//                 line += words[j - 1];
//             }

//             ans.push_back(line);

//             i = j;
//         }

//         return ans;
//     }

vector<string> fullJustify(vector<string>& words, int maxWidth) {
  vector<string> result;
  int i = 0;

  while (i < words.size()) {
    int j = i + 1;
    int lineLength = words[i].length();

    while (j < words.size() && lineLength + 1 + words[j].length() <= maxWidth) {
      lineLength += 1 + words[j].length();
      j++;
    }

    string line = "";
    int numWords = j - i;
    int numSpaces = maxWidth - (lineLength - (numWords - 1));

    if (j == words.size() || numWords == 1) {
      for (int k = i; k < j; k++) {
        line += words[k];
        if (line.length() < maxWidth) line += " ";
      }
      while (line.length() < maxWidth) line += " ";
    } else {
      int spacesBetween = numSpaces / (numWords - 1);
      int extraSpaces = numSpaces % (numWords - 1);

      for (int k = i; k < j; k++) {
        line += words[k];
        if (k < j - 1) {
          int spacesToApply = spacesBetween;

          if (extraSpaces > 0) {
            spacesToApply += 1;
            extraSpaces--;
          }

          line.append(spacesToApply, ' ');
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
  vector<string> word = {"This",          "is", "an", "example", "of", "text",
                         "justification."};

  int maxWidth = 16;

  vector<string> ans = fullJustify(word, maxWidth);

  for (auto i : ans) {
    cout << i << "\n";
  }
}