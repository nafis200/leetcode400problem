// 0 - 3 months:
// Udemy (9)

// 0 - 6 months:
// OpenAI (7) — Google (3) — TikTok (2) — CrowdStrike (2)

// 6 months ago:
// Microsoft (10) — Meta (9) — Amazon (9) — Snowflake (3) — Oracle (2)

// Problem_Link: https://neetcode.io/problems/string-encode-and-decode/question

// vector 3ab#2c, 2cd
//  how to preverse this

//  6#3ab#2c 2#cd
// here give len simple

#include <bits/stdc++.h>
using namespace std;
string encode(vector<string>& strs) {
    string encode = "";
    string ans;
    for(int i = 0; i < (int)strs.size(); i++){
         int len = strs[i].size();
         ans = to_string(len) + '#';
         ans += strs[i];
         encode += ans;
    }
    return encode;
}

// 6#3ab#2c4#2#cd0#

vector<string> decode(string s) {
    vector<string> ans;

    int i = 0;

    while (i < s.size()) {

        int j = i;

        while (s[j] != '#')
            j++;

        int len = stoi(s.substr(i, j - i));

        j++; 

        ans.push_back(s.substr(j, len));

        i = j + len;
    }

    return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<string> str = {"3ab#2c", "2#cd", ""};

  string ans = encode(str);

  cout << ans << "\n";

  vector<string>ans1 = decode(ans);
  for(auto i : ans1){
     cout << i << " ";
  }
}
