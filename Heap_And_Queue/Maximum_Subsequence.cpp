// 6 months ago:
// Google (9) — DE Shaw (6) — Microsoft (4) — Amazon (2) — Bloomberg (2)

// Problem_Link: https://leetcode.com/problems/maximum-subsequence-score/description/

#include<bits/stdc++.h>
using namespace std;

// Time o(nlogn) space o(n)

long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
    priority_queue<int,vector<int>,greater<int>>pq;

    vector<pair<int,int>>v;
    for(int i = 0; i < (int)nums1.size(); i++){
         v.push_back({nums2[i], nums1[i]});
    }
    sort(v.rbegin(),v.rend());

    long long ans = 0;
    long long sum = 0;
    for(auto i : v){
        int x = i.first;
        int y = i.second;
        sum += y;
        pq.push(y);

        if(pq.size() > k){
            sum -= pq.top();
            pq.pop();
        }
        if(pq.size() == k){
            ans = max(ans, sum * x);
        }
    }
    return ans;
 }

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums1 = {1, 3, 3, 2};
    vector<int>nums2 = {2, 1, 3, 4};
    int k = 3;
}