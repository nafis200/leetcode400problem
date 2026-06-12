// 0 - 3 months:
// Amazon (5) — Google (3)

// 0 - 6 months:
// Bloomberg (3)

// 6 months ago:
// Meta (12) — Microsoft (6)

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

ListNode* partition(ListNode* head, int x) {
  ListNode* smallHead = new ListNode(0);
  ListNode* largeHead = new ListNode(0);
  ListNode* small = smallHead;
  ListNode* large = largeHead;
  ListNode* temp = head;

  while (temp != NULL) {
    if (temp->val < x) {
      small->next = temp;
      small = small->next;
    } else {
      large->next = temp;
      large = large->next;
    }
    temp = temp->next;
  }

  small->next = largeHead->next;
  large->next = NULL;
  return smallHead->next;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {1, 4, 3, 2, 5, 2};
  int x = 3;

  ListNode* head = CreateNode(nums);

  head = partition(head, x);

  Print(head);
}