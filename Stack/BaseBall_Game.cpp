// 0 - 3 months:
// Google (2)

// 0 - 6 months:
// Meta (2) — Amazon (2)

// 6 months ago:
// Turing (12) — Microsoft (4) — Apple (2)

// Problem_Link: https://leetcode.com/problems/baseball-game/description/

#include<bits/stdc++.h>
using namespace std;
int calPoints(vector<string>& operations) {
    vector<int>st;
    for(int i = 0; i < operations.size(); i++){
        string x = operations[i];
        if(x == "D"){
            int num = st.back();
            num = num * 2;
            st.push_back(num);
        }
        else if(x == "C"){
            st.pop_back();
        }
        else if(x == "+"){
            int n = st.size();
            int num = st[n - 1] + st[n - 2];
            st.push_back(num);
        }
        else{
            int num = stoi(x);
            st.push_back(num);
        }
    }
    int ans = 0;
    for(int i = 0; i < st.size(); i++){
        ans += st[i];
    }
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<string>v = {"5","2","C","D","+"};

    int ans = calPoints(v);
    cout << ans << "\n";
}