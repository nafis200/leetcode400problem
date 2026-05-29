// 0 - 3 months:
// Amazon (16) — Google (10) — Meta (4) — Bloomberg (4) — Microsoft (2) — Apple (2)

// 0 - 6 months:
// Yandex (4) — TikTok (3) — Goldman Sachs (3) — Huawei (3) — Texas Instruments (3) — Infosys (2) — Adobe (2) — Uber (2) — Zenefits (2)

// 6 months ago:
// Yahoo (14) — Zoho (7) — J.P. Morgan (6) — ServiceNow (6) — Oracle (4) — Tesla (4) — Walmart Labs (3) — DE Shaw (3) — Intuit (3) — Avito (3)

// Problem_Link: https://leetcode.com/problems/generate-parentheses/description/

// ("",0,0)
//         |
//         (
//         |
//    ("(",1,0)
//       /      \
//      (        )
//     /          \
// ("((",2,0)    ("()",1,1)
//       |           |
//       )           (
//       |           |
// ("(()",2,1)    ("()(",2,1)
//       |           |
//       )           )
//       |           |
// ("(())",2,2)  ("()()",2,2)


// Time: O(Catalan(n) * n)
// Space: O(n)
// Catalan Number: Cn = (1 / n + 1) * (2n combination n)

// O(4 ^ n / root(n))

// 2^(2n) = 4^n * n (both are acurate)


#include<bits/stdc++.h>
using namespace std;

int si;
vector<string>result;
string s;

void generateBracket(int open, int close){
    if(s.size() == 2 * si){
        result.push_back(s);
    }

    if(open < si){
        s.push_back('(');
        generateBracket(open + 1, close);
        s.pop_back();
    }
    if(close < open){
        s.push_back(')');
        generateBracket(open, close + 1);
        s.pop_back();
    }
}

 vector<string> generateParenthesis(int n) {
      si = n;  
      generateBracket(0, 0);
      return result;
 }

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 3;
    vector<string>ans = generateParenthesis(n);
    for(auto it : ans){
        cout << it << "\n";
    }
}