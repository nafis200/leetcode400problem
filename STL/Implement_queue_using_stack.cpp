// Amazon (6) — Google (2)
// 0 - 6 months: Microsoft (3) — Bloomberg (3)
// 6 months ago: Adobe (7) — Apple (4) — Oracle (3) — Uber (3) — Meta (2) — Netflix (2) — Yahoo (2)

#include<bits/stdc++.h>
using namespace std;

//  

// 

class MyQueue {
public:
    stack<int> st1, st2;

    MyQueue() {
        
    }

    void push(int x) {
        st1.push(x);
    }

    int pop() {

        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }

        int ans = st2.top();
        st2.pop();

        return ans;
    }

    int peek() {

        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }

        return st2.top();
    }

    bool empty() {
        return st1.empty() && st2.empty();
    }
};

int32_t main(){

}