// 0 - 6 months:
// Google (5)

// 6 months ago:
// Meta (8) — Amazon (8) — Bloomberg (7) — Microsoft (5) — Arista Networks (3) — Adobe (2) — Apple (2) — Oracle (2) — Yahoo (2)

// Problem_Link: https://leetcode.com/problems/remove-linked-list-elements/description/?envType=problem-list-v2&envId=linked-list

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

ListNode* removeElements(ListNode* head, int val) {
    while(head != NULL && head->val == val){
        ListNode* newnode = head;
        head = head->next;
        delete newnode;
    }

    //  6 1 6 6 4 2 6

    if(head == NULL){
        return head;
    }

    ListNode* prev = head;
    ListNode* cur = head->next;
    while(cur != NULL){
         if(cur->val == val){
            ListNode* newnode = cur;
            prev->next = cur->next;
            cur = cur->next;
            delete newnode;
         }
         else{
            prev = prev->next;
            cur = cur->next;
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

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {6,1, 2, 6, 3, 4, 5, 6};

    ListNode* head = CreateNode(nums);

    int val = 6;

    head = removeElements(head, val);

    Print(head);
}