// 0 - 3 months:
// Google (12) — Amazon (11) — Meta (7) — Microsoft (4) — LinkedIn (3) —
// Accenture (3) — Bloomberg (2) — IBM (2) — Uber (2) — Citadel (2)

// 0 - 6 months:
// Epic Systems (7) — Yandex (2) — Dropbox (2)

// 6 months ago:
// Apple (24) — Adobe (22) — DE Shaw (14) — Tesla (9) — Yahoo (8) — Oracle (4) —
// Goldman Sachs (3) — Siemens (3) — Flexport (3) — J.P. Morgan (2)

// Problem_Link:
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

#include <bits/stdc++.h>
using namespace std;

// Time Complexity = O(n * 4^n)
// Space Complexity = O(n)

map<char, string> mapping = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                             {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                             {'8', "tuv"}, {'9', "wxyz"}};
                            
int n;
vector<string>result;
string ans;

void Bracktrack(int i, string digits){
    if(i == n){
        result.push_back(ans);
        return;
    }
    for(auto ch : mapping[digits[i]]){
        ans.push_back(ch);
        Bracktrack(i + 1, digits);
        ans.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    n = digits.size();
    Bracktrack(0, digits);
    return result;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string digits = "23";
  vector<string>a = letterCombinations(digits);
  for(auto i : a){
    cout << i << " ";
  }
}