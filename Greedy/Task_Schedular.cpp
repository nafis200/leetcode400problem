// 0 - 3 months:
// Amazon (7) — TCS (3) — Google (2) — Microsoft (2) — Micro1 (2)

// 6 months ago:
// Roblox (21) — Meta (14) — BCG (10) — Apple (7) — Oracle (7) — Uber (6) — Bloomberg (5) — DoorDash (5) — Snowflake (4) — Rubrik (4)

// Problem_Link: https://leetcode.com/problems/task-scheduler/

// 3A 3B 2C 1D
// n = 2
//  AbcAbcAbd

#include<bits/stdc++.h>
using namespace std;
int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int>mp;
    for(auto i : tasks){
        mp[i]++;
    }       
    int curMax = 0;
    for(auto i : mp){
        curMax = max(curMax, i.second);
    }

    int maxCount = 0;
    for(auto i : mp){
        if(i.second == curMax){
            maxCount++;
        }
    }

    int gap = (curMax - 1);
    
    int time_need = gap * (n + 1) + maxCount;

    int len = tasks.size();
    return max(time_need, len);
 }
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}