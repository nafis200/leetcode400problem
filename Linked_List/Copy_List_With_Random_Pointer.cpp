// 0 - 3 months:
// Meta (43) — Amazon (22) — Microsoft (5) — Google (3) — Bloomberg (3)

// 0 - 6 months:
// Intel (3) — Oracle (2) — Wix (2) — Uber (2)

// 6 months ago:
// Apple (10) — Adobe (8) — Walmart Labs (5) — Nvidia (5) — Docusign (5) — Yahoo
// (3) — Flipkart (2) — Morgan Stanley (2) — eBay (2) — PhonePe (2)

// Problem_Link:
// https://leetcode.com/problems/copy-list-with-random-pointer/description/

#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int x) {
    val = x;
    next = NULL;
    random = NULL;
  }
};

//  A   B    C

//  Make a copy

// A1   B1   C1

// mp[cur]->next

// mp[cur->next] = B

//  A1 next == B1

// Time o(n) space o(n)

// Node* copyRandomList(Node* head) {
//   if (!head) return NULL;

//   unordered_map<Node*, Node*> mp;

//   Node* cur = head;


//   while (cur) {
//     mp[cur] = new Node(cur->val);
//     cur = cur->next;
//   }

//   cur = head;

//   while (cur) {
//     mp[cur]->next = mp[cur->next];
//     mp[cur]->random = mp[cur->random];
//     cur = cur->next;
//   }

//   return mp[head];
// };

// While think link and random same

// A-->B (connected)
// A-->B (A Random B)

 Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        Node* cur = head;

        // 🔥 Step 1: Insert copied nodes after original nodes
        // A -> B -> C
        // A -> A' -> B -> B' -> C -> C'
        while (cur) {
            Node* copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
            cur = copy->next;
        }

        // 🔥 Step 2: Assign random pointers
        cur = head;
        while (cur) {
            if (cur->random) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
          
        // // A -> A' -> B -> B' -> C -> C'

        // A  B  C
        // A' B' C'
        // 🔥 Step 3: Separate original and copied list
        cur = head;
        Node* copyHead = head->next;

        while (cur) {
            Node* copy = cur->next;

            cur->next = copy->next;

            if (copy->next) {
                copy->next = cur->next->next;
            }

            cur = cur->next;
        }

        return copyHead;
    }


int main() {
  // Create nodes
  Node* node1 = new Node(7);
  Node* node2 = new Node(13);
  Node* node3 = new Node(11);
  Node* node4 = new Node(10);
  Node* node5 = new Node(1);

  // Next pointers
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;

  node1->random = NULL;
  node2->random = node1;  // 13 -> 7
  node3->random = node5;  // 11 -> 1
  node4->random = node3;  // 10 -> 11
  node5->random = node1;  // 1 -> 7

  // Print
  Node* head = node1;

  

  return 0;
}