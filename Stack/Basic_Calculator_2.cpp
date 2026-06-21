// 0 - 3 months:
// Meta (117) — Amazon (17) — Google (4) — Microsoft (3) — Tesla (3) — Verkada (2) — Rokt (2)

// 0 - 6 months:
// TikTok (3) — Zoho (3) — Apple (2) — Airbnb (2) — Zoox (2) — The Trade Desk (2) — Highspot (2)

// 6 months ago:
// Adobe (9) — DoorDash (9) — Snap (6) — Bloomberg (4) — Snowflake (3) — DE Shaw (2) — Anduril (2) — Atlassian (2) — Accenture (2) — Coupang (2)

// Problem_Link: https://leetcode.com/problems/basic-calculator-ii/description/

#include<bits/stdc++.h>
using namespace std;
int calculate(string s) {
    long long num = 0;
    char sign = '+';
    stack<int>st;
    for(int i = 0; i < s.size(); i++){
        if(isdigit(s[i])){
            num = 1LL * num * 10 + s[i] - '0';
        }
        if((!isdigit(s[i]) && s[i] != ' ') || (i == s.size() - 1)){
             if(sign == '+'){
                st.push(num);
             }
             if(sign == '-'){
                st.push(-num);
             }
             if(sign == '*'){
                int num1 = st.top();
                st.pop();
                st.push(num1 * num);
             }
             if(sign == '/'){
                int num1 = st.top();
                st.pop();
                st.push(num1 / num);
             }
             sign = s[i];
             num = 0;
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
    string s = " 3+5 / 2 ";
    int ans = calculate(s);
    cout << ans << "\n";
}