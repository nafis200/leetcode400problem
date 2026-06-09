// Google (4) — Microsoft (3) — Amazon (3) — Bloomberg (3)

// Problem_Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

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
//  1  200 -->  2  300 --> 2 400 --> 3 null 

//  1 200 --> 1 300 --> 3 400 --> 3 500 --> 5 NULL

 ListNode* deleteDuplicates(ListNode* head) {
    ListNode* temp = head;
    if(head == NULL){
        return head;
    }
    while(temp->next != NULL){
        if(temp->val == temp->next->val){
            ListNode* del = temp->next;
            temp->next = temp->next->next;
            delete del;
        }
        else{
            temp = temp->next;
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
    vector<int>nums = {1, 1, 3, 3, 5};
    ListNode* head = CreateNode(nums);
    head = deleteDuplicates(head);
    Print(head);
}