// 0 - 3 months: Google (2) — Meta (2) — Microsoft (2) — Amazon (2)
// 6 months ago: Apple (5) — Adobe (2) — Uber (2) — Yandex (2)

// Problem_Link: https://leetcode.com/problems/jewels-and-stones/description/

#include<bits/stdc++.h>
using namespace std;
int numJewelsInStones(string jewels, string stones) {
 
    unordered_map<char,int>mp;
    for(auto i : stones){
         mp[i]++;
    }

    int sum = 0;

    for(auto i : jewels){
         if(mp.find(i) != mp.end()){
              sum += mp[i];
         }
    }
    return sum;
    
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string jewels = "aA", stones = "aAAbbbb";
    int ans = numJewelsInStones(jewels, stones);
    cout << ans << "\n";
}