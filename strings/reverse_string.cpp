// Amazon (4) — Google (2) — Meta (2)

// problem Link: https://leetcode.com/problems/reverse-string/description/

#include <bits/stdc++.h>
using namespace std;

// time o(n) space o(n)

// void reverseString(vector<char>& s) {
//     vector<char>t;
//     int n = s.size();

//     for(int i = n - 1; i >= 0; i--){
//         t.push_back(s[i]);
//     }
//     s = t;
// }

// abcde

// time o(n) space o(1)

void reverseString(vector<char>& s) {
    
    int n = s.size();
    for(int i = 0; i < n / 2; i++){
        swap(s[i], s[n - i - 1]);
    }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<char>s = {'h','e','l','l','o','w'};
  reverseString(s);
  for(auto i : s){
     cout << i << " ";
  }
}