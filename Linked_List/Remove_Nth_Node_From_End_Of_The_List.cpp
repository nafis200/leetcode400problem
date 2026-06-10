// 0 - 3 months:
// Meta (13) — Google (9) — Microsoft (6) — Amazon (5) — Apple (2)

// 0 - 6 months:
// Bloomberg (2)

// 6 months ago:
// Adobe (11) — Oracle (8) — Yahoo (6) — Uber (5) — Nvidia (2) — Yandex (2) —
// PayPal (2) — Capgemini (2)

// Problem_Link:
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

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

// Time o(n) space o(1)

// ListNode* removeNthFromEnd(ListNode* head, int n) {
//   int len = 0;
//   ListNode* temp = head;
//   while (temp != NULL) {
//     temp = temp->next;
//     len++;
//   }

//   if (len == n) {
//     return head->next;
//   }

//   int pos = len - n;
  
//   temp = head;

//   for (int i = 1; i < pos; i++) {
//     temp = temp->next;
//   }

//   ListNode* cur = temp->next;
//   temp->next = temp->next->next;

//   delete cur;

//   return head;
// }

ListNode* removeNthFromEnd(ListNode* head, int n) {
   ListNode* fast = head;
   ListNode* slow = head;

   for(int i = 1; i <= n; i++){
       fast = fast->next;
   }
   
   if(fast == NULL){
      ListNode* cur = head;
      head = head->next;
      delete cur;
      return head;
   }

   while(fast->next != NULL){
       slow = slow->next;
       fast = fast->next;
   }

   ListNode* cur = slow->next;
   slow->next = slow->next->next;
   delete cur;
   return head;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {1, 2, 3, 4, 5};

  ListNode* head = CreateNode(nums);

  int n = 2;

  head = removeNthFromEnd(head, n);

  Print(head);
}