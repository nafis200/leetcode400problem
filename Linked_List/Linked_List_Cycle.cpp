// 0 - 3 months:
// Google (8) — Bloomberg (2) — Oracle (2)

// 0 - 6 months:
// Amazon (10) — Microsoft (6) — Meta (2) — Yahoo (2)

// 6 months ago:
// Apple (9) — Adobe (8) — Uber (6) — Goldman Sachs (5) — Cisco (4) — Walmart Labs (2) — EPAM Systems (2) — Wipro (2) — Samsung (2) — Yandex (2)

// Problem_Link:https://leetcode.com/problems/linked-list-cycle/description/

#include<bits/stdc++.h>
using namespace std;

class ListNode{
   public: 
   int val;
   ListNode* next;
   ListNode(int val){
       this->val =val;
       next = NULL;
   }
};

ListNode* CreateNode(vector<int>&nums, int pos){
    ListNode* head = NULL;
    ListNode* temp = NULL;
    ListNode* cycleNode = NULL;
    
    for(int i = 0; i < nums.size(); i++){
         ListNode* newnode = new ListNode(nums[i]);
        if(head == NULL){
             head = newnode;
             temp = newnode;
        }
        else{
            temp->next = newnode;
            temp = newnode;
        }
        if(i == pos){
            cycleNode = temp;
        }
    }

    if(cycleNode != NULL){
        temp->next = cycleNode;
    }

    return head;

}

void Print(ListNode* head){
   while(head != NULL){
     cout << head->val << " ";
     head = head->next;
   }
}

 bool hasCycle(ListNode *head) {
     ListNode* slow = head;
     ListNode* fast = head; 
     
     while(fast != NULL && fast->next != NULL){
          slow = slow->next;
          fast = fast->next->next;
          if(slow == fast){
             return true;
          }
     }
    return false;
 }



int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> arr = {3,2,0,-4};
    int pos = 1;

    ListNode* head = CreateNode(arr, pos);

    bool ans = hasCycle(head);
    cout << ans << "\n";
    
}