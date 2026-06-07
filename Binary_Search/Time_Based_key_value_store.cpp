// 0 - 3 months:
// Google (4) — Amazon (3) — Apple (3) — Axon (3) — Microsoft (2) — Bloomberg (2) — Oracle (2) — Uber (2) — Databricks (2) — Lyft (2)

// 0 - 6 months:
// Verkada (4) — OpenAI (3) — Cockroach Labs (3) — Meta (2) — Anduril (2) — Netflix (2) — Gusto (2) — Ramp (2)

// 6 months ago:
// Confluent (15) — Coinbase (15) — Instacart (7) — Snowflake (5) — eBay (4) — TikTok (3) — CARS24 (3) — Palantir Technologies (3) — CrowdStrike (3) — Airbnb (2)

// Problem_Link: https://leetcode.com/problems/time-based-key-value-store/description/


#include<bits/stdc++.h>
using namespace std;

class TimeMap {
public:
    map<string,vector<pair<int,string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()){
            return "";
        }

        vector<pair<int, string>> &v = mp[key];
        
        int l = 0, r = v.size() - 1;
        
        string ans = "";
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(v[mid].first <= timestamp){
                l = mid + 1;
                ans = v[mid].second;  
            }
            else{
                r = mid - 1;
            }
        }
        return ans;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
