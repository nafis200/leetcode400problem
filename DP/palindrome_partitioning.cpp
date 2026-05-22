// 0 - 3 months:
// Google (4) — Meta (3) — Microsoft (3) — Amazon (3) — Bloomberg (2)

// 6 months ago:
// Apple (10) — Adobe (7) — Uber (5) — Infosys (4) — Yahoo (4) — Walmart Labs
// (2)

// problem_Link:
// https://leetcode.com/problems/palindrome-partitioning/description/

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>>ans;
string t;

bool palindrome(int l, int r){
    while(l <= r){
       if(t[l] != t[r]){
         return false;
       }
       l++;
       r--;
    }
    return true;
}

void f(vector<string>&a, int i, int n){
   if(i == n){
     ans.push_back(a);
     return;
   }
   for(int j = i; j < n; j++){
      if(palindrome(i, j)){
         string s1 = t.substr(i, j - i + 1);
         a.push_back(s1);
         f(a, j + 1, n);
         a.pop_back();
      }
   }
}

vector<vector<string>> partition(string s) {
  vector<string>a;
  t = s;
  int n = s.size();
  f(a, 0, n);
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s = "aaa";
  vector<vector<string>>result = partition(s);
  for(auto st : result){
    cout << "[";
    for(auto i : st){
        cout << i << " ";
    }
    cout << "]";
  }
}