// 0 - 3 months:
// Amazon (7) — Google (4) — Meta (3)

// 0 - 6 months:
// Bloomberg (3)

// 6 months ago:
// Microsoft (14) — Apple (9) — Adobe (8) — Uber (6) — Yahoo (5) — TikTok (2) —
// Western Digital (2) — MediaTek (2)

// Problem_Link: https://leetcode.com/problems/odd-even-linked-list/description/

#include <bits/stdc++.h>
using namespace std;

// Time o(n) space o(1)

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

ListNode* oddEvenList(ListNode* head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  ListNode* odd = head;
  ListNode* even = odd->next;
  ListNode* evenSave = odd->next;

  while (even != NULL && even->next != NULL) {
    odd->next = even->next;
    odd = odd->next;
    even->next = odd->next;
    even = even->next;
  }
  odd->next = evenSave;
  return head;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {1, 2, 3, 4, 5};

  ListNode* head = CreateNode(nums);

  head = oddEvenList(head);

  Print(head);
}