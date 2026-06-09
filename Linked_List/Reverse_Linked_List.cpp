// Google (11) — Amazon (7) — Meta (5) — Microsoft (5) — Oracle (4) — SAP (3) — Bloomberg (2)

// Problem_Link: https://leetcode.com/problems/reverse-linked-list/description/

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

ListNode* CreateNode(vector<int>&nums){
    ListNode* head = NULL;
    ListNode* temp = NULL;
    
    for(auto it : nums){
        ListNode* newnode = new ListNode(it);
        if(head == NULL){
             head = newnode;
             temp = newnode;
        }
        else{
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;

}

void Print(ListNode* head){
   while(head != NULL){
     cout << head->val << " ";
     head = head->next;
   }
}

ListNode* reverseList(ListNode* head) {
   ListNode* prev = NULL;
   ListNode* cur = head;
   while(cur != NULL){
     ListNode* next = cur->next;
     cur->next = prev;
     prev = cur;
     cur = next;
   }
   return prev;
}



int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {1, 2, 3, 4, 5};

    ListNode* head = CreateNode(nums);

    ListNode* tail = reverseList(head);

    Print(tail);
}