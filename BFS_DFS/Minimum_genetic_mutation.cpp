// 0 - 3 months:
// Google (2) — Amazon (2)

// 6 months ago:
// Microsoft (4) — Bloomberg (4) — Oracle (2) — X (2)

// problem_Link:
// https://leetcode.com/problems/minimum-genetic-mutation/description/

#include <bits/stdc++.h>
using namespace std;

vector<char> ch = {'A', 'C', 'G', 'T'};
int minMutation(string startGene, string endGene, vector<string>& bank) {
  set<string> st(bank.begin(), bank.end());
  if (st.find(endGene) == st.end()) {
    return -1;
  }
  queue<pair<string, int>> q;
  q.push({startGene, 0});
  while (!q.empty()) {
    auto x = q.front();
    q.pop();
    string s = x.first;
    int steps = x.second;
    if (s == endGene) {
      return steps;
    }

    for(auto it : ch){
       char c = it;
       for(int i = 0; i < 8; i++){
         string original = s;
         s[i] = c;
         if(st.find(s) != st.end()){
            st.erase(s);
            q.push({s, steps + 1});
         }
         s = original;
       }
    }
  }
  return -1;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string startGene = "AACCGGTT";
  string endGene = "AAACGGTA";

  vector<string> bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
  int ans = minMutation(startGene, endGene, bank);
  cout << ans << "\n";
}