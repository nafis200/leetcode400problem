

// 0 - 3 months:
// IBM (4) — Google (2) — Meta (2) — Microsoft (2) — Amazon (2) — Bloomberg (2)
// — UiPath (2) — AMD (2)

// 0 - 6 months:
// Verkada (4)

// 6 months ago:
// Wix (18) — Adobe (7) — Oracle (5) — TikTok (5) — LinkedIn (4) — Walmart Labs
// (4) — Salesforce (4) — Booking.com (4) — Goldman Sachs (3) — Zoho (3)

// problem link: https://leetcode.com/problems/integer-to-roman/description/

#include <bits/stdc++.h>
using namespace std;

string intToRoman(int num) {
  vector<pair<int, string>> val = {
      {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
      {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
      {5, "V"},    {4, "IV"},   {1, "I"}};

  string res = "";

  for (auto p : val) {
    while (num >= p.first) {
      res += p.second;
      num -= p.first;
    }
  }

  return res;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string ans = intToRoman(3775);
  cout << ans << "\n";
}