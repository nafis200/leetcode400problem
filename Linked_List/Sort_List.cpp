// 0 - 3 months:
// Google (4)

// 0 - 6 months:
// Microsoft (3) — Amazon (3)

// 6 months ago:
// Adobe (8) — Apple (8) — Bloomberg (7) — Meta (6) — TikTok (6) — Yahoo (5) —
// ByteDance (3) — Uber (3) — Oracle (2)

// Problem_Link: https://leetcode.com/problems/sort-list/description/

#include <bits/stdc++.h>
using namespace std;

class ListNode {
 public:
  int val;
  ListNode* next;
  ListNode(int val) {
    this->val = val;
    next = NULL;
  }
};

ListNode* CreateNode(vector<int>& nums) {
  ListNode* head = NULL;
  ListNode* temp = NULL;

  for (auto it : nums) {
    ListNode* newnode = new ListNode(it);
    if (head == NULL) {
      head = newnode;
      temp = newnode;
    } else {
      temp->next = newnode;
      temp = newnode;
    }
  }
  return head;
}

void Print(ListNode* head) {
  while (head != NULL) {
    cout << head->val << " ";
    head = head->next;
  }
}

// O(n^2)

// ListNode* sortList(ListNode* head) {
//   ListNode* temp = head;
//   if (head == NULL) {
//     return head;
//   }
//   for (ListNode* i = head; i->next != NULL; i = i->next) {
//     if (i != NULL) {
//       for (ListNode* j = i->next; j != NULL; j = j->next) {
//         if (i->val > j->val) {
//           swap(i->val, j->val);
//         }
//       }
//     }
//   }
//   return temp;
// }

//  1 2 3 4 5

//  1 2 3 4
//    p s f
// [5 -> 4 -> 1 -> 2 -> 3]  (শুরুতে মূল লিস্ট)
//                         /         \
//                        /           \  (মাঝখান থেকে ভাগ)
//                       v             v
//                [5 -> 4 -> 1]       [2 -> 3]
//                 /        \           /    \
//                v          v         v      v
//             [5 -> 4]     [1]       [2]    [3]
//             /     \       |         |      |
//            v       v      |         |      |
//           [5]     [4]     |         |      |
//  ------------------|------|---------|------|--------------------
//   (এখানে বিভাজন শেষ, এখন নিচে থেকে ওপরে মার্জ করা শুরু হবে)
//            \       /      |         |      |
//             v     v       |         |      |
//             [4 -> 5]     [1]       [2]    [3]
//                \         /           \    /
//                 v       v             v  v
//                [1 -> 4 -> 5]       [2 -> 3]
//                       \               /
//                        \             /
//                         v           v
//                   [1 -> 2 -> 3 -> 4 -> 5]  (চূড়ান্ত সর্টেড লিস্ট)

ListNode* getMid(ListNode* head) {
  ListNode* slow = head;
  ListNode* fast = head;
  ListNode* prev = NULL;

  while (fast && fast->next) {
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }

  if (prev) {
    prev->next = NULL;
  }
  return slow;
}

ListNode* merge(ListNode* a, ListNode* b) {
  

  ListNode* tail = new ListNode(0);
  ListNode* dummy = tail;
  while (a != nullptr && b != nullptr) {
    if (a->val < b->val) {
      tail->next = a;
      a = a->next;
    } else {
      tail->next = b;
      b = b->next;
    }
    tail = tail->next;
  }

  while (a != nullptr) {
  tail->next = a;
  a = a->next;
  tail = tail->next;
}

while (b != nullptr) {
  tail->next = b;
  b = b->next;
  tail = tail->next;
}

  return dummy->next;
}

ListNode* sortList(ListNode* head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  ListNode* mid = getMid(head);
  ListNode* left = sortList(head);
  ListNode* right = sortList(mid);
  return merge(left, right);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {5, 2, 1, 4, 3};

  ListNode* head = CreateNode(nums);
 
  head = sortList(head);

  Print(head);
}