// 0 - 3 months:
// Apple (2)

// 0 - 6 months:
// Amazon (2) — Bloomberg (2)

// 6 months ago:
// Microsoft (8) — Meta (3) — Uber (3) — Nutanix (3) — Glovo (3) — Google (2) —
// Flipkart (2) — TikTok (2) — Salesforce (2)

// Problem_Link:
// https://leetcode.com/problems/maximum-frequency-stack/description/

//  5 7 5 7 4 5

//  5  7  5  7  4  5

//  1  1  2  2  1  3

#include<bits/stdc++.h>
using namespace std;

class FreqStack {
 public:
  unordered_map<int, int> freq;
  unordered_map<int, stack<int>> group;
  int maxFreq = 0;

  FreqStack() {}

  void push(int val) {
        freq[val]++;
        int f = freq[val];

        maxFreq = max(maxFreq, f);
        group[f].push(val);  
    }


  int pop() {
     int val = group[maxFreq].top();
     group[maxFreq].pop();
     freq[val]--;
     if(group[maxFreq].empty()){
        maxFreq--;
     }
     return val;
  }
};