// 0 - 6 months:
// Google (3) — Amazon (3)

// 6 months ago:
// Meta (3)

// Problem_Link: https://leetcode.com/problems/detect-squares/description/

#include<bits/stdc++.h>
using namespace std;

class StockPrice {
public:
    unordered_map<int,int>mp;
    multiset<int>st;
    int latest = 0;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(mp.count(timestamp)){
            int x = mp[timestamp];
            st.erase(st.find(x));
        }
        mp[timestamp] = price;
        st.insert(price);
        latest = max(latest, timestamp);
    }
    
    int current() {
        return mp[latest];
    }
    
    int maximum() {
        return *st.rbegin();
    }
    
    int minimum() {
        *st.begin();
    }
};

