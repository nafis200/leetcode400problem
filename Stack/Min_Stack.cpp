// 0 - 3 months:
// Google (11) — Amazon (11) — Apple (6) — Bloomberg (4) — Meta (3) — Microsoft (2) — Vimeo (2)

// 0 - 6 months:
// Yandex (3) — LinkedIn (2) — Oracle (2) — Lyft (2)

// 6 months ago:
// Tinkoff (10) — Paytm (8) — Uber (6) — Salesforce (5) — Adobe (4) — Walmart Labs (4) — Intuit (4) — Odoo (4) — Nike (3) — Snowflake (3)

// Problem_Link: https://leetcode.com/problems/min-stack/description/

#include<bits/stdc++.h>
using namespace std;

// Time o(nlogn) spae o(n)

// class MinStack {
// public:
//     vector<int>st;
//     int mn = INT_MAX;
//     MinStack() {
        
//     }
    
//     void push(int value) {
//         st.push_back(value);
//     }
    
//     void pop() {
//         st.pop_back();
//     }
    
//     int top() {
//         return st.back();
//     }
    
//     int getMin() {
//         vector<int>v;
//         v = st;
//         sort(v.begin(),v.end());
//         return v[0];
//     }
// };


class MinStack {
public:
    stack<int>st,mn;
    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
        if(mn.empty()){
            mn.push(value);
        }
        else{
            mn.push(min(value,mn.top()));
        }
    }
    
    void pop() {
        st.pop();
        mn.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mn.top();
    }
};


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

}