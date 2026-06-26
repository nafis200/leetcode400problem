// 6 months ago:
// Google (15) — Microsoft (6) — Meta (5) — Amazon (5) — Bloomberg (4) — Apple
// (2)

// Problem_Links: https://leetcode.com/problems/hand-of-straights/description/

#include <bits/stdc++.h>
using namespace std;

// Time o(nlogn) space o(n)

bool isNStraightHand(vector<int>& hand, int groupSize) {
  if (hand.size() % groupSize) {
    return false;
  }
  map<int, int> mp;
  for (auto i : hand) {
    mp[i]++;
  }
  while(!mp.empty()){
     int start = mp.begin()->first;
     for(int i = start; i < start + groupSize; i++){
        if(mp.find(i) == mp.end()){
            return false;
        }
        mp[i]--;
        if(mp[i] == 0){
            mp.erase(i);
        }
     }
  }
  return true;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};
  int groupSize = 3;
  bool ans = isNStraightHand(hand, groupSize);
  cout << ans << "\n";
}