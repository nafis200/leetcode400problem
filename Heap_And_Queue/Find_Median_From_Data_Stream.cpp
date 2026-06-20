// 0 - 3 months:
// Microsoft (4) — Amazon (4) — Citadel (4) — Google (3)

// 0 - 6 months:
// Meta (4) — Apple (4) — Bloomberg (3) — Anduril (3) — PayPal (3) — Flipkart (2) — Intuit (2) — Spotify (2) — IXL (2)

// 6 months ago:
// Oracle (16) — Pinterest (12) — TikTok (8) — Uber (8) — Goldman Sachs (6) — Nvidia (5) — Walmart Labs (4) — Tinder (4) — Splunk (3) — Okta (3)

// Problem_Link: https://leetcode.com/problems/find-median-from-data-stream/description/

#include<bits/stdc++.h>
using namespace std;

// Time o(n^2logn)

// class MedianFinder {
// public:
//     vector<int>v;
//     MedianFinder() {
        
//     }
    
//     void addNum(int num) {
//         v.push_back(num);
//         sort(v.begin(),v.end());
//     }
    
//     double findMedian() {
//         int x = (int)v.size();
//         double ans = 0;
//         if(x % 2){
//            ans = v[x / 2];
//         }
//         else{
//             ans = (v[x / 2] + v[x / 2 - 1]) / 2.0;
//         }
//         return ans;
//     }
// };

// Time nlogn space o(n)

class MedianFinder {
public:
    priority_queue<int>right;
    priority_queue<int,vector<int>,greater<int>>left;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        left.push(num);
        int x = left.top();
        left.pop();
        right.push(x);
        if(right.size() > left.size()){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size() > right.size()){
            return left.top();
        }
        else{
            return(left.top() + right.top()) / 2.0;
        }
    }
};

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MedianFinder* m = new MedianFinder();

}