// 0 - 3 months:
// Meta (40) — Amazon (16) — Google (9) — Microsoft (6) — Apple (3) — Oracle (3)
// — Bloomberg (2) — Walmart Labs (2) — TikTok (2) — Warnermedia (2)

// 0 - 6 months:
// Nvidia (4) — LinkedIn (3) — Uber (3) — Goldman Sachs (2) — Citadel (2) —
// Airbnb (2) — X (2) — Snowflake (2) — Yandex (2) — Two Sigma (2)

// 6 months ago:
// Adobe (15) — Palantir Technologies (4) — Tesla (3) — eBay (3) — Dell (3) —
// Indeed (3) — IBM (2) — Cisco (2) — Snap (2) — Salesforce (2)

// Problem_Link: https://leetcode.com/problems/merge-k-sorted-lists/description/

#include <bits/stdc++.h>
using namespace std;

class ListNode {
 public:
  int val;
  ListNode* next;

  ListNode(int x) {
    val = x;
    next = NULL;
  }
};

void Print(ListNode* head) {
  while (head != NULL) {
    cout << head->val << " ";
    head = head->next;
  }
}

ListNode* createList(vector<int>& nums) {
  ListNode* head = NULL;
  ListNode* tail = NULL;

  for (int x : nums) {
    ListNode* newNode = new ListNode(x);

    if (head == NULL) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  return head;
}

void InsertArray(vector<int>& v, ListNode* head) {
  ListNode* temp = head;
  while (temp != NULL) {
    v.push_back(temp->val);
    temp = temp->next;
  }
}

// Time o(nlogn) space o(n)

// ListNode* mergeKLists(vector<ListNode*>& lists) {
//      vector<int>v;
//      for(auto it : lists){
//         InsertArray(v, it);
//      }

//      sort(v.begin(),v.end());

//      ListNode* head = createList(v);

//      return head;
// }

class cmp {
 public:
  bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
};

// Time o(NlogK) Space o(k)

ListNode* mergeKLists(vector<ListNode*>& lists) {
  priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

  for (auto it : lists) {
     if(it){
        pq.push(it);
     }
  }

  ListNode* head = NULL;
  ListNode* tail = NULL;

  while (!pq.empty()) {
    ListNode* x = pq.top();
    pq.pop();
    ListNode* newNode = new ListNode(x->val);
    if (head == NULL) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }

    if(x->next){
        pq.push(x->next);
    }

  }

  return head;
}

int main() {
  vector<vector<int>> arr = {{1, 4, 5}, {1, 3, 4}, {2, 6}};

  vector<ListNode*> lists;

  for (auto& v : arr) {
    ListNode* head = createList(v);
    lists.push_back(head);
  }

  ListNode* head = mergeKLists(lists);

  Print(head);

  return 0;
}