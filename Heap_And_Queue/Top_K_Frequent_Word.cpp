// 0 - 3 months:
// Google (2) — Amazon (2) — Bloomberg (2)

// 0 - 6 months:
// Meta (2) — PayPal (2) — Box (2)

// 6 months ago:
// Oracle (9) — Uber (9) — Robinhood (8) — Microsoft (6) — Adobe (5) — ServiceNow (3) — Salesforce (3) — Redfin (3) — TikTok (2) — Palo Alto Networks (2)

// Problem_Link: https://leetcode.com/problems/top-k-frequent-words/

#include<bits/stdc++.h>
using namespace std;

// Time o(nlogn) space o(n)

// class cmp{
//     public:
//     bool operator()(pair<int,string>a, pair<int,string>b){
//         if(a.first != b.first){
//             return a.first < b.first;
//         }
//         return a.second > b.second;
//     }
// };

// vector<string> topKFrequent(vector<string>& words, int k) {
//      unordered_map<string, int>mp;
     
//      for(auto i : words){
//          mp[i]++;
//      }

//      vector<pair<int,string>>v;
//      for(auto it : mp){
//         v.push_back({it.second,it.first});
//      }

//      sort(v.rbegin(),v.rend(),cmp());
 
//      vector<string>ans;
//      for(int i = 0; i < k; i++){
//          ans.push_back(v[i].second);
//      }
//      return ans;

// }

class cmp{
    public:
    bool operator()(pair<int,string>a, pair<int,string>b){
        if(a.first != b.first){
            return a.first > b.first;
        }
        return a.second < b.second;
    }
};

vector<string> topKFrequent(vector<string>& words, int k) {
     unordered_map<string, int>mp;
     
     for(auto i : words){
         mp[i]++;
     }

     priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>pq;
     
     for(auto i : mp){
        pq.push({i.second, i.first});
        if(pq.size() > k){
            pq.pop();
        }
     }

   vector<string>ans;

   while(!pq.empty()){
      auto x = pq.top();
      pq.pop();
      ans.push_back(x.second);
   }
   reverse(ans.begin(),ans.end());
   return ans;
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<string>words = {"i","love","leetcode","i","love","coding"};
    int k = 2;
    vector<string>ans = topKFrequent(words, k);

    for(auto i : ans){
        cout << i << " ";
    }
}