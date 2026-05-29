// 0 - 6 months:
// Meta (7) — Google (3) — TikTok (2) — Rubrik (2) — Deliveroo (2)

// 6 months ago:
// Uber (4) — Amazon (3) — Bloomberg (3) — Adobe (3) — Yandex (3) — Apple (2) — Snowflake (2)

// Problem_Link: https://leetcode.com/problems/remove-invalid-parentheses/description/


// ")("

// layer by layer generate

#include<bits/stdc++.h>
using namespace std;

// time o(2^n)
// if i keep or remove so

bool isValid(string s){
    int count = 0;
    for(auto i : s){
        if(i == '('){
            count++;
        }
        else if(i == ')'){
            count--;
        }
        if(count < 0){
            return false;
        }
    }
    if(count == 0){
        return true;
    }
    return false;
}

vector<string> removeInvalidParentheses(string s) {
    vector<string>ans;
    set<string>visited;
    queue<string>q;
    bool found = false;

    visited.insert(s);
    q.push(s);
    while(!q.empty()){
        string x = q.front();
        q.pop();
        if(isValid(x)){
            found = true;
            ans.push_back(x);
        }
        if(found){
            continue;
        }
        for(int i = 0; i < (int)x.size(); i++){
            if(x[i] != '(' && x[i] != ')'){
                continue;
            }
            string next = x.substr(0, i) + x.substr(i + 1);
            if(visited.find(next) == visited.end()){
                visited.insert(next);
                q.push(next);
            }
        }
    }
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = "()())()";
    vector<string>ans = removeInvalidParentheses(s);
    for(auto i : ans){
        cout << i << " ";
    }

}
