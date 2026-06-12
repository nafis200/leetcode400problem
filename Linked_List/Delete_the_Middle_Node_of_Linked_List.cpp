// 0 - 6 months:
// Google (2)

// 6 months ago:
// Amazon (6) — Bloomberg (4) — Meta (3) — Microsoft (3) — Apple (2) — Uber (2)

// Problem_Link:
// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/?envType=problem-list-v2&envId=linked-list

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

ListNode* deleteMiddle(ListNode* head) {
  ListNode* temp = NULL;
  ListNode* slow = head;
  ListNode* fast = head;

  if(head == NULL || head->next == NULL){
     return NULL;
  }

  while (fast != NULL && fast->next != NULL) {
    temp = slow;
    slow = slow->next;
    fast = fast->next->next;
  }

    temp->next = slow->next;
  
  return head;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {1, 2, 3, 4};

  ListNode* head = CreateNode(nums);
  head = deleteMiddle(head);
  Print(head);
}