// 0 - 3 months:
// Bloomberg (15) — Google (13) — Amazon (8) — Meta (7) — Microsoft (3) — Zoho (3) — Razorpay (2)

// 0 - 6 months:
// TikTok (8) — Wix (4) — Tinkoff (2) — Apple (2) — Huawei (2) — Coupang (2) — Yelp (2)

// 6 months ago:
// Oracle (12) — Adobe (9) — Cisco (6) — Mountblue (5) — Walmart Labs (4) — Yahoo (4) — ByteDance (3) — Goldman Sachs (3) — Uber (3) — eBay (3)

// Problem_Link: https://leetcode.com/problems/decode-string/description/

#include<bits/stdc++.h>
using namespace std;

// Time o(n) space o(n)

string decodeString(string s) {
     int num = 0;
     string cur = "";
     stack<string>words;
     stack<int>nums;
     for(int i = 0; i < s.size(); i++){
        if(isdigit(s[i])){
            num = num * 10 + s[i] - '0';
        }
        else if(s[i] == '['){
            words.push(cur);
            nums.push(num);
            cur = "";
            num = 0;
        }
        else if(s[i] == ']'){
            int k = nums.top();
            nums.pop();

            string prev = words.top();
            words.pop();
            string temp = "";
            for(int i = 0; i < k; i++){
                temp += cur;
            }
            cur = prev + temp;
        }
        else{
            cur += s[i];
        }
     }
     return cur;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = "3[a]2[bc]";

    string ans = decodeString(s);
    cout << ans << "\n";
}