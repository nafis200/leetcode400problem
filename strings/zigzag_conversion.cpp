// 0 - 3 months:
// Google (6) — Amazon (5) — Microsoft (3) — Meta (2) — Bloomberg (2) —
// Salesforce (2)

// 0 - 6 months:
// Apple (2) — PayPal (2)

// 6 months ago:
// Zopsmart (26) — Zoho (11) — Oracle (9) — MicroStrategy (5) — Walmart Labs (4)
// — ServiceNow (3) — Mitsogo (2) — Intuit (2) — PayPay (2)

// problem link: https://leetcode.com/problems/zigzag-conversion/description/

#include <bits/stdc++.h>
using namespace std;

// time o(n) space o(n)

// string convert(string s, int numRows) {
//     vector<string>rows(numRows);
//     bool go = false;
//     int currentRow = 0;

//     if(numRows == 1){
//         return s;
//     }

//     for(auto c : s){
//         rows[currentRow] += c;
//         if(currentRow == 0 || currentRow + 1 == numRows){
//              if(go == false){
//                 go = true;
//              }
//              else{
//                 go = false;
//              }
//         }
//         if(go){
//             currentRow++;
//         }
//         else{
//             currentRow--;
//         }
//     }
//     string s1 = "";
//     for(auto it : rows){
//         s1 += it;
//     }
//     return s1;
// }


// Row 0:  0           6           12          (P . . . . . I . . . . . N)
// Row 1:  1        5  7        11 13          (A . . . L S . . . I G . .)
// Row 2:  2     4     8     10                (Y . A . . H . R . . . . .)
// Row 3:  3           9                       (P . . . . I . . . . . . .)

// up = (numRows - 1)
// down = (numsRows - 1)

// cyclelen = up + down
// cyclelen = 2 * numsRow - 2

// diagonal = cycleLen - row

string convert(string s, int numRows) {
    if (numRows == 1) return s;

    string ans = "";
    int n = s.length();
    int cycleLen = 2 * numRows - 2;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j + i < n; j += cycleLen) {
            ans += s[j + i];
            if (i != 0 && i != numRows - 1 && j + cycleLen - i < n) {
                ans += s[j + cycleLen - i];
            }
        }
    }
    return ans;
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s = "AB";
  int numRows = 2;
  string ans = convert(s, numRows);

  cout << ans << "\n";
}


