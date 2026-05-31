// 0 - 3 months:
// Amazon (9) — Google (6) — Goldman Sachs (2)

// 0 - 6 months:
// Gusto (8) — Apple (3) — Fractal Analytics (3) — Microsoft (2)

// 6 months ago:
// Meta (30) — Warnermedia (12) — Palantir Technologies (12) — Roblox (9) —
// Oracle (6) — Bloomberg (4) — Zoho (4) — TCS (3) — Adobe (3) — Nordstrom (3)

// Problem_Link:
// https://leetcode.com/problems/integer-to-english-words/description/

#include <bits/stdc++.h>
using namespace std;

vector<string> below20 = {"",        "One",       "Two",      "Three",
                          "Four",    "Five",      "Six",      "Seven",
                          "Eight",   "Nine",      "Ten",      "Eleven",
                          "Twelve",  "Thirteen",  "Fourteen", "Fifteen",
                          "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

vector<string> tens = {"",      "",      "Twenty",  "Thirty", "Forty",
                       "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

vector<string> place = {"", "Thousand", "Million", "Billion"};

string calculate(int num){
    if(num == 0){
        return "";
    }
    if(num < 20){
        return below20[num] + " ";
    }
    if(num < 100){
        return tens[num / 10] + " " + calculate(num % 10);
    }
    return below20[num / 100] + " Hundred " + calculate(num % 100);
}

string numberToWords(int num) {
    if(num == 0){
        return "Zero";
    }
    int i = 0;
    string ans = "";
    while(num){
        int part = num % 1000;
        if(part != 0){
            ans = calculate(part) + place[i] + " " + ans;
        }
        i++;
        num /= 1000;
    }
    ans.pop_back();
    while(!ans.empty() && ans.back() == ' '){
        ans.pop_back();
    }
    return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string ans = numberToWords(20);
  cout << ans << "\n";
}