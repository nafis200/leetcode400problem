// 0 - 3 months:
// Amazon (9) — Dream11 (3) — Google (2) — Meta (2) — Goldman Sachs (2) — Nvidia (2) — PayPal (2)

// 0 - 6 months:
// Microsoft (3) — Bloomberg (3) — Salesforce (2) — OpenAI (2)

// 6 months ago:
// DoorDash (17) — Oracle (15) — TikTok (13) — Apple (9) — Adobe (8) — Flipkart (7) — Sprinklr (7) — Qualtrics (6) — IMC (6) — SoFi (4)

// Problem_Link: https://leetcode.com/problems/asteroid-collision/description/
// Time o(n) space o(n)

#include<bits/stdc++.h>
using namespace std;
vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int>st;
    for(int x : asteroids){
       bool destoried = false;
 
       while(!st.empty() && st.top() > 0 && x < 0){
        
          if(abs(x) > st.top()){
            st.pop();
          }

           else if(st.top() == abs(x)){
             destoried = true;
             st.pop();
             break;
           }
           else{
             destoried = true;
             break;
           }
       }

       if(!destoried){
          st.push(x);
       }
    }
   
    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {3,5,-6,2,-1,4};

    nums = asteroidCollision(nums);

    for(auto i : nums){
        cout << i << " ";
    }
}