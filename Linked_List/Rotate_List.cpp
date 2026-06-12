// 0 - 3 months:
// Google (6) — Amazon (5) — Meta (2) — Bloomberg (2)

// 0 - 6 months:
// Nvidia (5) — LinkedIn (3)

// 6 months ago:
// Microsoft (11) — Apple (6) — Adobe (4) — Oracle (4) — Morgan Stanley (2) — Siemens (2) — Yahoo (2)

// Problem_Link: https://leetcode.com/problems/rotate-list/description/?envType=problem-list-v2&envId=linked-list

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

//  1 2 3 4 5
//  4 5 1 2 3

ListNode* rotateRight(ListNode* head, int k) {
     ListNode* temp = head;
     if(head == NULL || head->next == NULL){
        return head;
     }
     int n = 1;
     while(temp->next != NULL){
         temp = temp->next;
         n++;
     }
     
     k = k % n;

     if(k == 0){
        return head;
     }

     int pos = n - k;

     ListNode* newTail = head;
     for(int i = 1; i < pos; i++){
           newTail = newTail->next;
     }
     
     ListNode* newHead = newTail->next;
     temp->next = head;
     newTail->next = NULL;
     return newHead;
}



int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {1, 2, 3, 4, 5};

    ListNode* head = CreateNode(nums);
 
    head = rotateRight(head, 2);
    Print(head);
  
}