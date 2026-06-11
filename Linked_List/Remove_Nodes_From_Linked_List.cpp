// 0 - 6 months:
// Google (2)

// 6 months ago:
// Amazon (12) — Meta (7) — Bloomberg (5) — Adobe (4) — Uber (2)

// Problem_Link: https://leetcode.com/problems/remove-nodes-from-linked-list/description/?envType=problem-list-v2&envId=linked-list


//  5 2 13 3 8

//  8 3 13 2 5
//  8 13 

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


// Time o(n) space o(1)

ListNode* Reverse(ListNode* head){
     ListNode* prev = NULL;
     ListNode* temp = head;
     while(temp != NULL){
        ListNode* cur = temp->next;
        temp->next = prev;
        prev = temp;
        temp = cur;   
     }
     return prev;
}

// 5 2 13 3 8 
// 8 3 13 2 5


ListNode* removeNodes(ListNode* head) {
     head = Reverse(head);    
     ListNode* temp = head;
     while(temp != NULL && temp->next != NULL){
         if(temp->next->val < temp->val){
              temp->next = temp->next->next;
         }
         else{
            temp = temp->next;
         }
     }  
     head = Reverse(head);
     return head;  
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int>v = {5, 2, 13, 3, 8};

    ListNode* head = CreateNode(v);

    head = removeNodes(head);

    Print(head);
}