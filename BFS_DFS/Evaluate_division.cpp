

// 0 - 3 months:
// Amazon (7) — Uber (5) — Bloomberg (2)

// 0 - 6 months:
// Google (7) — Meta (5) — Nuro (3) — TikTok (2) — Snap (2) — PhonePe (2)

// 6 months ago:
// Citadel (9) — Stripe (9) — Rippling (8) — GE Healthcare (7) — BlackRock (4) —
// Microsoft (3) — Zeta (2) — Flipkart (2) — Snowflake (2) — MakeMyTrip (2)

// Problem_Link: https://leetcode.com/problems/evaluate-division/description/

#include <bits/stdc++.h>
using namespace std;

// time complexity O(Q × (V + E)) space O(V + E)


map<string,vector<pair<string,double>>>graph;
set<string>visted;


double DFS(string src, string dist, double product){
    if(dist == src){
        return product;
    }
    visted.insert(src);
    for(auto it : graph[src]){
        if(!visted.count(it.first)){
            double result = DFS(it.first, dist, product * it.second);
            if(result != -1.0){
                return result;
            }
        }
    }
    return -1.0;
}


vector<double> calcEquation(vector<vector<string>>& equations,vector<double>& values,vector<vector<string>>& queries) {
     for(int i = 0; i < equations.size(); i++){
        string a = equations[i][0];
        string b = equations[i][1];
        graph[a].push_back({b, values[i]});
        graph[b].push_back({a, 1.0 / values[i]});
     }

     vector<double>ans;
     
     for(auto query : queries){
         string src = query[0];
         string dist = query[1];
         visted.clear();
         if(!graph.count(src) || !graph.count(dist)){
            ans.push_back(-1.0);
         }
         else{
            double result = DFS(src, dist, 1.0);
            ans.push_back(result);
         }
     }
     return ans;
 }

int main() {
  vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
  vector<double> values = {2.0, 3.0};
  vector<vector<string>> queries = {
      {"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};

      vector<double>result = calcEquation(equations,values,queries);
      for(auto i : result){
        cout << i << " ";
      }

  return 0;
}