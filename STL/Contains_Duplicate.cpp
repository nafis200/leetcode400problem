// Google (5) — Amazon (5) — Microsoft (3) — Bloomberg (3) — Meta (2) — Paycom (2)
// 0 - 6 months: Yahoo (3) — Oracle (2) — Airbnb (2) — Palantir Technologies (2)
// 6 months ago: Apple (31) — Adobe (21) — Uber (19) — TCS (7) — Yandex (3) — J.P. Morgan (2) — EPAM Systems (2) — DE Shaw (2) — Siemens (2) — Accenture (2)

// Problem_Link: https://leetcode.com/problems/contains-duplicate/description/

#include<bits/stdc++.h>
using namespace std;
 bool containsDuplicate(vector<int>& nums) {
       unordered_map<int,int>mp;
       for(auto i : nums){
           mp[i]++;
           if(mp[i] > 1){
            return true;
           }
       }  
       return false;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}