// 0 - 3 months:
// Meta (11) — Bloomberg (3) — Goldman Sachs (3) — Niantic (3) — Google (2) — Databricks (2)

// 0 - 6 months:
// Microsoft (6) — Amazon (5) — Uber (2)

// 6 months ago:
// Apple (10) — Adobe (8) — Yahoo (4) — Nvidia (3) — Samsung (2)

// problem_link: https://leetcode.com/problems/string-to-integer-atoi/description/

#include<bits/stdc++.h>
using namespace std;

// time o(n) and space o(1)

int myAtoi(string s){
     int n = s.size();
     int i = 0;
     long long result = 0;
     int sign = 1;
     while(i < n && s[i] == ' '){
         i++;
     }
     if(i == n){
        return 0;
     }

     if(s[i] == '+'){
         i++;
     }
     else if(s[i] == '-'){
         i++;
         sign = -1;
     }

     while(i < n && isdigit(s[i])){
         int count = s[i] - '0';
         result = result * 10 + count;
         if(result > INT_MAX){
            if(sign == 1){
                return INT_MAX;
            }
            else if(result > (long)INT_MAX + 1){
                return INT_MIN;
            }
         }
         i++;
     }
     return int(sign * result);

} 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s = " -042";

    int ans = myAtoi(s);
    cout << ans << "\n";

}