// 0 - 3 months:
// Google (8) — Amazon (5) — Meta (4) — Microsoft (3) — Bloomberg (2)

// 6 months ago:
// TCS (4) — Qualcomm (2)

// problem_link: https://leetcode.com/problems/length-of-last-word/

#include <bits/stdc++.h>
using namespace std;

// time complexity o(n) space o (n)

// int lengthOfLastWord(string s) {
//     vector<string>parts;
//     stringstream ss(s);
//     string temp;
//     while(getline(ss, temp, ' ')){
//         if(temp != "") {   
//             parts.push_back(temp);
//         }
       
//     }
//     for(auto i : parts){
//         cout << i << " ";
//     }

//     int ans = 0;
//     if(!parts.empty()){
//         ans = parts[parts.size() - 1].size();
//     }
//     return ans;
// }

// time o(n) space o (1)

// int lengthOfLastWord(string s) {
//     vector<string>parts;
//     stringstream ss(s);
//     string temp;
//      int ans = 0;
//     while(getline(ss, temp, ' ')){
//         if(temp != "") {   
//             ans = temp.size();
//         }
       
//     }   
//     return ans;
// }

// time o(logn) space o(1)

int lengthOfLastWord(string s) {
    reverse(s.begin(),s.end());
    int n = s.size();
    int i = 0;
    string word = "";
    while(i < n && s[i] == ' '){
        i++;
    }
    while(i < n && s[i] != ' '){
        word += s[i];
        i++;
    }

    return word.size();
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s = "   fly me   to   the moon  ";

  int ans = lengthOfLastWord(s);

  cout << ans << "\n";
}