// 0 - 3 months:
// Meta (10)

// 0 - 6 months:
// Amazon (2)

// 6 months ago:
// TikTok (5) — Google (3) — Oracle (2) — eBay (2)

// https://algo.monster/liteproblems/159

#include<bits/stdc++.h>
using namespace std;

int LongestSubstring(string s){
    int n = s.size();
    unordered_map<char,int>mp;
    int l = 0;
    int ans = 0;
    for(int r = 0; r < n; r++){
        mp[s[r]]++;
        while(mp.size() > 2){
            mp[s[l]]--;
            if(mp[s[l]] == 0){
                mp.erase(s[l]);
            }
            l++;
        }
        int len = r - l + 1;
        
        ans = max(ans, len);
    }
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = "ccaabbb";
    int ans = LongestSubstring(s);
    cout << ans << "\n";
}