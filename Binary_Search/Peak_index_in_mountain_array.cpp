// 0 - 3 months: Google (8) — Meta (4) — Amazon (3) — Bloomberg (2)
// 6 months ago: Adobe (12) — Microsoft (7) — Apple (7) — Yahoo (6) — Uber (5) — Infosys (2) — TCS (2) — DE Shaw (2)

// Problem_Link: https://leetcode.com/problems/peak-index-in-a-mountain-array/description/


#include<bits/stdc++.h>
using namespace std;

// 3, 5, 3, 2, 0

//  0  4
//  2
// 1
//  0 + 1
//  0

int peakIndexInMountainArray(vector<int>& arr) {
     int l = 0, r = arr.size() - 1;
     int ans = 1;
     while(l <= r){
        int mid = l + (r - l) / 2;
        if(mid > 0 && arr[mid] > arr[mid - 1]){
             ans = mid;
             l = mid + 1;
        }
        else{
            r = mid - 1;
        }
     }        
     return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int>arr = {3, 5, 3, 2, 0};

    int ans = peakIndexInMountainArray(arr);

    cout << ans << "\n";
}