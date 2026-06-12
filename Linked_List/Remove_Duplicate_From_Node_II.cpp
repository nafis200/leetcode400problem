// 0 - 6 months:
// Arista Networks (3) — Google (2) — Bloomberg (2)

// 6 months ago:
// Meta (10) — Microsoft (9) — Amazon (7) — Oracle (3) — BlackBuck (3) — Nvidia
// (2)

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

//  1 2 3 3 4 4 5

// 1 1 1

ListNode* deleteDuplicates(ListNode* head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  ListNode* prev = NULL;
  ListNode* temp = head;

  while (temp != NULL && temp->next != NULL) {
    if (temp->val == temp->next->val) {
      ListNode* del = temp;
      while (del->next != NULL && del->val == del->next->val) {
        del = del->next;
      }
      if (prev == NULL) {
        head = del->next;
        temp = head;
      } else {
        prev->next = del->next;
        temp = del->next;
      }
    } else {
      prev = temp;
      temp = temp->next;
    }
  }
  return head;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {1, 1, 1};

  ListNode* head = CreateNode(nums);

  head = deleteDuplicates(head);

  Print(head);
}