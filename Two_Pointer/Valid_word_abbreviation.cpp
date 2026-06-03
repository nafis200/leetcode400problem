// 0 - 3 months:
// Meta (135) — Google (3) — Amazon (3) — Datadog (3)

// 6 months ago:
// Apple (4) — TikTok (3) — Disney (2) — Rokt (2)

// Problem_Link: https://neetcode.io/problems/valid-word-abbreviation/question

#include<bits/stdc++.h>
using namespace std;

// time o(n) space o(1)

 bool validWordAbbreviation(string word, string abbr) {
    int n1 = word.size();
    int n2 = abbr.size();

    int i = 0, j = 0;

    while(i < n1 && j < n2){
        if(isalpha(abbr[j])){
            if(word[i] != abbr[j]){
                return false;
            }
            i++;
            j++;
        }
        else{
            if(abbr[j] == '0'){
                return false;
            }
            int num = 0;
            while(j < n2 && isdigit(abbr[j])){
               int num1 = abbr[j] - '0';
               num = num * 10 + num1;
               j++;
            }
            i += num;
        }
    }
    return (i == n1 && j == n2);
 }

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string word = "apple", abbr = "a3e";

    bool ans = validWordAbbreviation(word, abbr);

    cout << ans << "\n";
}