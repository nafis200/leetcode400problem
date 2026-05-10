// 0 - 3 months:
// Meta (7) — Amazon (3) — Pinterest (3)

// 0 - 6 months:
// Google (3) — Microsoft (2)

// 6 months ago:
// Apple (9) — Akuna Capital (8) — Yahoo (7) — Bloomberg (4) — Adobe (4) — Zoho (4) — PayPal (2) — Wells Fargo (2) — ConsultAdd (2)

#include<bits/stdc++.h>
using namespace std;

// time o(2^n) space o(2^n)

// প্রতিটি নতুন পদের দৈর্ঘ্য তার আগের পদের চেয়ে গড়ে প্রায় ৩০% থেকে ১০০% পর্যন্ত বৃদ্ধি পেতে পারে।

// 1 + 2 + 4 + 8 + ..... + 2^{n-1} = 2^n - 1

// string countAndSay(int n) {
//      if(n == 1){
//         return "1";
//      }
//     string ans = countAndSay(n - 1);


//     string ans2 = "";
//     for(int i = 0; i < (int)ans.size();){
//          char start = ans[i];
//          int point = i;
//          while(i < (int)ans.size() && ans[i] == start){
//              i++;
//          }

//          int len = i - point;
//          ans2 += to_string(len);
//          ans2 += start;
//     }
//     return ans2;
// }

string countAndSay(int n) {
     string ans = "1";
     string ans2 = "";
     for(int i = 2; i <= n; i++){
         for(int j = 0; j < ans.size();){
             char start = ans[j];
             int point = j;
             while(j < ans.size() && ans[j] == start){
                 j++;
             }
             ans2 += to_string(j - point);
             ans2+= start;
         }
         ans = ans2;
         ans2 = "";
     }
     return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 4;
    string ans = countAndSay(n);
    cout << ans << "\n";
}