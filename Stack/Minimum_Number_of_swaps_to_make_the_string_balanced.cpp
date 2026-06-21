// 6 months ago:
// Google (9) — Amazon (9) — Bloomberg (5) — Meta (4) — Expedia (4) — Microsoft (2) — PayPal (2) — Nutanix (2) — Twilio (2)

// Problem_Link: https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/description/

#include<bits/stdc++.h>
using namespace std;

// Time o(n) space o(n)

int minSwaps(string s) {
    stack<char>st;
    int imbalaced = 0;

    for(int i = 0; i <(int)s.size(); i++){
        if(s[i] == '['){
            st.push(s[i]);
        }
        else{
            if(st.empty()){
                imbalaced++;
            }
            else{
                st.pop();
            }
        }
    }

    return (imbalaced + 1) / 2;
}


// Time o(n) space o(1)
// int minSwaps(string s) {
//     int imbalanced = 0;
//     int balanced = 0;
//     for(int i = 0; i < (int)s.size(); i++){
//         if(s[i] == '['){
//             balanced++;
//         }
//         else{
//             balanced--;
//         }
//         if(balanced < 0){
//             balanced = 0;
//             imbalanced++;
//         }
//     }
//     return (imbalanced + 1) / 2;
// }
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = "]]][[[";
    int ans = minSwaps(s);
    cout << ans << "\n";
}