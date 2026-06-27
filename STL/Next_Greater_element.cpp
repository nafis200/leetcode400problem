// 0 - 3 months:
// Google (7) — Amazon (4)

// 0 - 6 months:
// Microsoft (5) — Meta (3) — Oracle (2)

// 6 months ago:
// Apple (10) — Bloomberg (8) — Adobe (5) — Uber (3) — Goldman Sachs (2) — Accenture (2) — Sprinklr (2) — Yahoo (2)

// Problem_Link: https://leetcode.com/problems/next-greater-element-i/description/

//  4 1 2
//  1 3 4 2

//  1 --> 3
//  3 --> 4

// stack 4 and 2

#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
   
    int n = nums2.size();
    unordered_map<int,int>mp;
    stack<int>st;
    for(auto i : nums2){
        while(!st.empty() && i > st.top()){
            int x = st.top();
            st.pop();
            mp[x] = i;
        }
        st.push(i);
    }
    while (!st.empty())
    {
        int x = st.top();
        mp[x] = -1;
        st.pop();
    }
    vector<int>ans;
    for(auto i : nums1){
        ans.push_back(mp[i]);
    }
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums1 = {4,1,2};
    vector<int>nums2 = {1,3,4,2};

}