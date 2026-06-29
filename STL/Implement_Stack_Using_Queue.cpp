// 0 - 3 months:
// Google (3) — Meta (3) — Microsoft (2)

// 0 - 6 months:
// Amazon (2) — Goldman Sachs (2)

// 6 months ago:
// Bloomberg (4) — Apple (4) — Adobe (3) — Oracle (3) — DE Shaw (2)


// Problem_Link: https://leetcode.com/problems/implement-stack-using-queues/description/

#include<bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> q1, q2;

    MyStack() {
        
    }

    void push(int x) {
        q2.push(x);

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }

    int pop() {
        int x = q1.front();
        q1.pop();
        return x;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */