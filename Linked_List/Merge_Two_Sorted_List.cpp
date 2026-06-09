// 0 - 3 months:
// Google (10) — Amazon (8) — Bloomberg (6) — Meta (5) — Microsoft (3) — Yandex
// (2) — Palo Alto Networks (2)

// 0 - 6 months:
// LinkedIn (3) — Apple (3) — Wix (2) — HPE (2) — Huawei (2)

// 6 months ago:
// Adobe (34) — Uber (22) — Yahoo (17) — Hubspot (10) — Oracle (9) — Media.net
// (6) — TCS (3) — Flipkart (3) — Walmart Labs (3) — EPAM Systems (3)

// Problem_Link:
// https://leetcode.com/problems/merge-two-sorted-lists/description/

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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
  ListNode* head = NULL;
  ListNode* temp = NULL;

  while (list1 != NULL && list2 != NULL) {
    ListNode* newnode = NULL;
    if (list1->val <= list2->val) {
      newnode = new ListNode(list1->val);
      list1 = list1->next;
    } else {
      newnode = new ListNode(list2->val);
      list2 = list2->next;
    }
    if (head == NULL) {
      head = newnode;
      temp = newnode;
    } else {
      temp->next = newnode;
      temp = newnode;
    }
  }

  while (list1 != NULL) {
    ListNode* newnode = NULL;
    newnode = new ListNode(list1->val);
    list1 = list1->next;
    if (head == NULL) {
      head = newnode;
      temp = newnode;
    } else {
      temp->next = newnode;
      temp = newnode;
    }
  }

  while (list2 != NULL) {
    ListNode* newnode = NULL;
    newnode = new ListNode(list2->val);
    list2 = list2->next;
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

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> list1 = {1, 2, 4};

  vector<int> list2 = {1, 3, 4};

  ListNode* head1 = CreateNode(list1);

  ListNode* head2 = CreateNode(list2);

  ListNode* head = mergeTwoLists(head1, head2);

  Print(head);
}