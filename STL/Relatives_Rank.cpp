// Google (14) — Amazon (6) — Bloomberg (6) — Meta (2) — Microsoft (2) — Adobe (2) — Electronic Arts (2)

// Problem_Link: https://leetcode.com/problems/relative-ranks/

#include<bits/stdc++.h>
using namespace std;
vector<string> findRelativeRanks(vector<int>& score) {
   vector<pair<int,int>>place;
   for(int i = 0; i < score.size(); i++){
     place.push_back({score[i], i});
   }
   int n = place.size();
   vector<string>ans(n, "");
   sort(place.begin(),place.end());
   reverse(place.begin(),place.end());

   for(int i = 0; i < n; i++){
      if(i == 0){
         ans[place[i].second] = "Gold Medal";
      }
      else if(i == 1){
        ans[place[i].second] = "Silver Medal";
      }
      else if(i == 2){
       ans[place[i].second] = "Bronze Medal"; 
      }
      else{
         ans[place[i].second] = to_string(i + 1);
      }
      
   }
   return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>score = {10,3,8,9,4};

    vector<string>ans = findRelativeRanks(score);

    for(auto i : ans){
        cout << i << " ";
    }

}