// 6 months ago:
// Google (3)

// Problem_Link: https://leetcode.com/problems/merge-triplets-to-form-target-triplet/description/

#include<bits/stdc++.h>
using namespace std;
bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
   bool first = false;
   bool second = false;
   bool third = false;
   
   for(auto i : triplets){
     if(i[0] > target[0] || i[1] > target[1] || i[2] > target[2]){
        continue;
     }
     if(i[0] == target[0]){
        first = true;
     }
     if(i[1] == target[1]){
        second = true;
     }
     if(i[2] == target[2]){
        third = true;
     }
   }
   return first && second && third;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}