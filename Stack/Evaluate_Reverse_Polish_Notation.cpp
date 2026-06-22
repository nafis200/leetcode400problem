// 0 - 3 months:
// Amazon (4) — Google (3) — Meta (2) — Citadel (2) — Citigroup (2)

// 0 - 6 months:
// Bloomberg (4) — Microsoft (3) — Oracle (2) — Grammarly (2)

// 6 months ago:
// LinkedIn (5) — Canonical (4) — Apple (3) — Apollo.io (3) — Infosys (2) — Goldman Sachs (2) — Anduril (2)

// Problem_Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/

#include<bits/stdc++.h>
using namespace std;
int evalRPN(vector<string>& tokens) {
   stack<int>st;
   for(int i = 0; i < tokens.size(); i++){
      if(tokens[i] == "+"){
          int x = st.top();
          st.pop();
          int y = st.top();
          st.pop();
          st.push(y + x);
      }
      else if(tokens[i] == "-"){
         int x = st.top();
          st.pop();
          int y = st.top();
          st.pop();
          st.push(y - x);
      }
      else if(tokens[i] == "*"){
          int x = st.top();
          st.pop();
          int y = st.top();
          st.pop();
          st.push(y * x);
      }
      else if(tokens[i] == "/"){
           int x = st.top();
          st.pop();
          int y = st.top();
          st.pop();
          st.push(y / x);
      }
      else{
         int x = stoi(tokens[i]);
         st.push(x);
      }
   }     
   int ans = 0;
   while(!st.empty()){
      ans += st.top();
      st.pop();
   }
   return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<string> tokens= {"2","1","+","3","*"};

    cout << evalRPN(tokens) << "\n";
}