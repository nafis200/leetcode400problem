// 0 - 6 months:
// Amazon (2)

// 6 months ago:
// Google (5) — Microsoft (5) — Yahoo (5) — Flipkart (3) — Meta (2) — Bloomberg (2) — Apple (2)

// Problem_Link: https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/

#include<bits/stdc++.h>
using namespace std;
int countStudents(vector<int>& students, vector<int>& sandwiches) {
    vector<int>cnt(2, 0);
    for(int s : students){
         cnt[s]++;
    }        
    for(int s : sandwiches){
        if(cnt[s] == 0){
            return cnt[0] + cnt[1];
        }
        cnt[s]--;
    }
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}