// 0 - 3 months:
// Meta (13)

// 6 months ago:
// Google (10) — TikTok (5) — Amazon

// problem Link: Premium Lock https://medium.com/@sanu.here1993/leet-code-163-missing-ranges-f799bdd2ba53

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> missingRanges(vector<int>& ranges , int lower, int upper){
     vector<vector<int>>ans;

     if(ranges.size() == 0){
         ans.push_back({lower,upper});
         return ans;
     }

     if(ranges[0] > lower){
        ans.push_back({lower, ranges[0] - 1});
     }

     int size = ranges.size() - 1;

     for(int i = 1; i <= size; i++){
        if(ranges[i] - ranges[i - 1] != 1){
           ans.push_back({ranges[i - 1] + 1, ranges[i] - 1});
        }
     }

     if(ranges[ranges.size() - 1] < upper){
        ans.push_back({ranges[ranges.size() - 1] + 1, upper});
     }
     

     return ans;
}

int32_t main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0); 
  
   vector<int> vec ={0, 1, 3, 50, 75};

   int lower = 0, upper = 99;

   vector<vector<int>>ans = missingRanges(vec,lower,upper);

   for(auto it : ans){
    cout << "[";
     for(auto i : it){
        cout << i << " ";
     }
     cout << "]";
     cout << "\n";
   }
}