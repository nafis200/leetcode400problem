// 0 - 3 months:
// Bloomberg (2)

// 0 - 6 months:
// Google (2)

// 6 months ago:
// Amazon (10) — Microsoft (5) — Goldman Sachs (4) — TikTok (3) — Zoho (3) — Apple (2) — Yahoo (2) — Livspace (2)

// Problem_Link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

#include <bits/stdc++.h>
using namespace std;

// Time o(nlogn) space o(1)

class cmp{
    public:
    bool operator()(vector<int>a, vector<int>b){
        if(a[1] == b[1]){
            return a[0] < b[0];
        }
         if(a[1] < b[1]){
            return true;
         }
         return false;
    }
};

int findMinArrowShots(vector<vector<int>>& points) {
   sort(points.begin(),points.end(),cmp());
    int remove = 1;
    int end = points[0][1];
    for(int i = 1; i < points.size(); i++){
        if(points[i][0] > end){
            remove++;
            end = points[i][1];
        }
    }
    return remove;        
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
}