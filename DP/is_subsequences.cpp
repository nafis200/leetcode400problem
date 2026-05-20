// Meta (6) — Google (4)


// Problem_Link: https://leetcode.com/problems/is-subsequence/description/

#include<bits/stdc++.h>
using namespace std;


// time o(n * m) space o (n * m)

vector<vector<int>>memo;

int n, n1;

bool solve(int i, int j, string & s, string & t){
    if(i == s.size()){
        return true;
    }
    if(j == t.size() && i < s.size() - 1){
          return false;
    }
    if(memo[i][j] != -1){
        return memo[i][j];
    }
    bool ans = false;
    if(s[i] == t[j]){
        ans = solve(i + 1, j + 1, s, t);
    }
    else{
        ans = solve(i, j + 1, s, t);
    }
    return memo[i][j] = ans;

}

bool isSubsequence(string s, string t) {
   n = s.size();
   n1 = t.size();
   memo.assign(n + 1, vector<int>(n1 + 1, - 1));   
   bool ans = solve(0, 0, s, t);
   return ans;
 
}


// time o(n) space o(1)

// bool isSubsequence(string s, string t) {
//    int n = s.size();
//    int n1 = t.size();   
//    int j = 0;
//    for(int i = 0; i < n1; i++){
//       if(s[j] == t[i]){
//          j++;
//       }
//    }   
   
//    if(j == n){
//     return true;
//    }
//    return false;
// }

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = "abc", t = "ahbgdc";
    bool ans = isSubsequence(s, t);

    cout << ans << "\n";
}