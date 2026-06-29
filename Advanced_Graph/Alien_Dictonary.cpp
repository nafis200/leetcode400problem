// 0- 3 months:
// Uber (7) — Amazon (3) — Google (2) — Meta (2)

// 0 - 6 months:
// Airbnb (2) — Nuro (2)

// 6 months ago:
// Microsoft (8) — TikTok (8) — Apple (4) — Oracle (3) — Coupang (3) — Wix (2) — X (2) — Tencent (2) — Snap (2) — NetApp (2)

// Problem_Link: https://neetcode.io/problems/foreign-dictionary/question

// ["hrn","hrf","er","enn","rfnn"]

//  n --> f
//  h-->e
//  r--> n
//  e --> r

//  h --> 0 e--> 0 r--> 0 n--> 0 f--> 0
// ab
// abc

//  a--> b
//  a--> b take it one ignore duplicate
#include<bits/stdc++.h>
using namespace std;
 string foreignDictionary(vector<string>& words) {
    unordered_map<char,unordered_set<char>>graph;
    unordered_map<char,int>indeg;

    for(auto word : words){
         for(auto w : word){
             indeg[w] = 0;
         }
    }
    for(int i = 1; i < words.size(); i++){
        string word1 = words[i - 1];
        string word2 = words[i];

        int len1 = word1.size();
        int len2 = word2.size();

        // abc and ab return ""

        if(len1 > len2 && word1.substr(0, len2) == word2){
            return "";
        }
        int len = min(len1, len2);
        for(int j = 0; j < len; j++){
             if(word1[j] != word2[j]){
                if(!graph[word1[j]].count(word2[j])){
                    graph[word1[j]].insert(word2[j]);
                    indeg[word2[j]]++;
                    break;
                }
             }
        }
    }       

   queue<char>q;
   for(auto i : indeg){
      if(i.second == 0){
         q.push(i.first);
      }
   }    
   string ans;

   while(!q.empty()){
      char x = q.front();
      q.pop();
      ans += x;
      for(char c : graph[x]){
         indeg[c]--;
         if(indeg[c] == 0){
            q.push(c);
         }
      }
   }

   if(ans.size() != indeg.size()){
     return "";
   }
   return ans;  
 }
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<string>words = {"hrn","hrf","er","enn","rfnn"};

    string ans = foreignDictionary(words);

    cout << ans << "\n";
}