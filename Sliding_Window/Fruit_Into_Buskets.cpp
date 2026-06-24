// 0 - 3 months:
// Amazon (12) — Google (8)

// 0 - 6 months:
// Bloomberg (4) — ServiceNow (2)

// 6 months ago:
// Meta (13) — Microsoft (10) — Adobe (5) — Zoho (3) — Netflix (2)

// Problem_Link: https://leetcode.com/problems/fruit-into-baskets/description/

#include<bits/stdc++.h>
using namespace std;
// Time o(n) space o(n)
int totalFruit(vector<int>& fruits) {
     int n = fruits.size();
     int l = 0;
     map<int,int>mp;
     int ans = 0;
     for(int r = 0; r < n; r++){
          mp[fruits[r]]++;
          while(mp.size() > 2){
              mp[fruits[l]]--;
              if(mp[fruits[l]] == 0){
                 mp.erase(fruits[l]);
              }
              l++;
          }
        int len = r - l + 1;
        ans = max(ans, len);
     }     
     return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>fruits = {1,2,3,2,2};
    int ans = totalFruit(fruits);
    cout << ans << "\n";
}