// Google (5) — Amazon (4) — Meta (2) — Bloomberg (2)

// Problem_Link:
// https://leetcode.com/problems/palindrome-linked-list/description/

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

//  1 2 3 3 2 1

// Time o(n) space o(n)

// bool isPalindrome(ListNode* head) {
//   stack<int> st;
//   ListNode* temp = head;

//   while(temp != NULL){
//      st.push(temp->val);
//      temp = temp->next;
//   }

//   temp = head;

//   while(temp != NULL){
//      if(st.top() != temp->val){
//         return false;
//      }
//      st.pop();
//      temp = temp->next;
//   }
//   if(st.empty()){
//     return true;
//   }
//   return false;
// }

// 1 2 3 3 2 1


//  3 2 1

//  1 2 3 
//  1 2 3

// Time o(n) space o(1)

ListNode* reverseList(ListNode* head){
    ListNode* prev = NULL;
    ListNode* cur = head;
    while (cur != NULL)
    {
        ListNode* newnode = cur->next;
        cur->next = prev;
        prev = cur;
        cur = newnode;
    }

    return prev;
    
}

bool isPalindrome(ListNode* head) {
  ListNode* temp = head;
  ListNode* slow = head;
  ListNode* fast = head;

  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }

  ListNode* secondHalf = reverseList(slow);
  
  while(secondHalf != NULL){
     if(secondHalf->val != temp->val){
        return false;
     }
     secondHalf = secondHalf->next;
     temp = temp->next;
  }
  return true;

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
  vector<int> nums = {1, 2, 3, 3, 2, 1};

  ListNode* head = CreateNode(nums);

  bool ans = isPalindrome(head);

  cout << ans << "\n";

  Print(head);
}