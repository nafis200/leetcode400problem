// 0 - 3 months:
// Amazon (4)

// 0 - 6 months:
// Google (2)

// 6 months ago:
// Nvidia (10) — PayPal (6) — Microsoft (4) — Meta (3) — Oracle (3) — Bloomberg (2) — Flipkart (2) — Visa (2) — Salesforce (2) — Rippling (2)

// Problem_Link: https://leetcode.com/problems/last-stone-weight/

#include<bits/stdc++.h>
using namespace std;

// Time complexity n^2 logn

//  int lastStoneWeight(vector<int>& stones) {
//       int sz = stones.size();
//     //    2 7 4 1 8 1
//       if(sz == 0){
//         return 0;
//       }  
//       sort(stones.begin(),stones.end());
//       while(stones.size() > 1){
//          int x = stones.back();
//          stones.pop_back();
//          int y = stones.back();
//          stones.pop_back();
         
//          int mid = x - y;
//          stones.push_back(mid);
//          sort(stones.begin(),stones.end());
//       }
//       return stones[0];
//  }

// Time o(nlogn) space o(n)

int lastStoneWeight(vector<int>& stones) {
      int sz = stones.size();
    //    2 7 4 1 8 1
      if(sz == 0){
        return 0;
      }  
      priority_queue<int>pq;
      for(int i = 0; i < sz; i++){
         pq.push(stones[i]);
      }

      while(pq.size() > 1){
         int x = pq.top();
         pq.pop();
         int y = pq.top();
         pq.pop();
         int mid = x - y;
         pq.push(mid);
      }
      return pq.top();
 }

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>stones = {2,7,4,1,8,1};

    cout << lastStoneWeight(stones) << "\n";
}