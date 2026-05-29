// 0 - 3 months:
// Microsoft (7) — Amazon (3)

// 0 - 6 months:
// Nvidia (3)

// 6 months ago:
// TikTok (15) — Google (12) — Meta (12) — Arista Networks (8) — Oracle (7) — Zoho (6) — Adobe (4) — Visa (4) — Bloomberg (3) — Palo Alto Networks (3)

// Problem_Link: https://leetcode.com/problems/restore-ip-addresses/

#include<bits/stdc++.h>
using namespace std;

// string s = "25 525 511 135";

vector<string> result;

void solve(vector<string>&path, string &s, int start){
  if(path.size() == 4){
      if (start == s.length()) {
            result.push_back(path[0] + "." + path[1] + "." + path[2] + "." + path[3]);
        }
        return;
  }
  for(int len = 1; len <= 3; len++){
     if(start + len > s.size()){
        break;
     }
     string sub = s.substr(start, len);
     if(sub.size() > 1 && sub[0] == '0'){
        continue;
     }
     if(stoi(sub) <= 255){
        path.push_back(sub);
        solve(path, s, start + len);
        path.pop_back();
     }
  }
}

vector<string> restoreIpAddresses(string s) {
    vector<string>path; 
    solve(path, s, 0);
    return result;;
 }

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = "25525511135";
    vector<string>ans = restoreIpAddresses(s);
    for(auto it : ans){
        cout << it << " ";
    }
}