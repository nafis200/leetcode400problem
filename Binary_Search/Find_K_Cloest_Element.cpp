// 0 - 3 months:
// Amazon (7) — Google (4) — Microsoft (2)

// 0 - 6 months:
// Meta (4) — Yandex (3)

// 6 months ago:
// DoorDash (21) — Bloomberg (10) — LinkedIn (8) — Apple (7) — Coupang (4) — TikTok (3) — TCS (2) — Adobe (2) — Flipkart (2) — Uber (2)


// Problem_Link: https://leetcode.com/problems/find-k-closest-elements/

#include<bits/stdc++.h>
using namespace std;

// Time o(n) space o(nlogn)

// static bool cmp(pair<int,int>& a, pair<int,int>& b) {
//     if (a.second == b.second) {
//         return a.first < b.first;
//     }
//     return a.second < b.second;
// }

//  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//     vector<pair<int,int>>v;
    
//     for(auto i : arr){
//         int dis = abs(i - x);
//         v.push_back({i, dis});
//     }

//     sort(v.begin(),v.end(),cmp);

//     vector<int>ans;

//     for(int i = 0; i < k; i++){
//         ans.push_back(v[i].first);
//     }
//     sort(ans.begin(),ans.end());
//     return ans;
//  }



//  1 2 3 4 5
//  k = 4
//  1 2 3 4
//  2 3 4 5

// Time o(k + log(n - k)) space o(k) extra o(1)

 vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    vector<int>ans;
    int l = 0, r = arr.size() - k;
    int mid = 0;
    
    while(l < r){
        mid = l + (r - l) / 2;
        if(x - arr[mid] > arr[mid + k] - x){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }
    for(int i = l; i < l + k; i++){
         ans.push_back(arr[i]);
    }
    return ans;
 }

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>arr = {1, 2, 3, 4, 5};
    int k = 4, x = 3;

    vector<int>ans = findClosestElements(arr, k, x);

    for(auto it : ans){
        cout << it << " ";
    }
}