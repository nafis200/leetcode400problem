// 0 - 3 months:
// Google (3) — Meta (2) — Microsoft (2)

// 0 - 6 months:
// Amazon (5) — Bloomberg (2) — Infosys (2) — Oracle (2)

// 6 months ago:
// Arista Networks (7) — Apple (5) — Revolut (5) — TikTok (4) — Adobe (3) — Nutanix (3) — Walmart Labs (2) — EPAM Systems (2) — Nvidia (2)

// Problem_Link: https://leetcode.com/problems/reverse-linked-list-ii/


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

ListNode* reverseList(ListNode* head, ListNode* tail) {
   ListNode* prev = NULL;
   ListNode* cur = head;
   while(cur != tail){
     ListNode* next = cur->next;
     cur->next = prev;
     prev = cur;
     cur = next;
   }
   return prev;
}


 ListNode* reverseBetween(ListNode* head, int left, int right) {

    if(left == right){
        return head;
    }

    ListNode* leftNode = head;
    ListNode* rightNode = head;

    ListNode* prev = NULL;
    ListNode* next = NULL;
    
    for(int i = 1; i < left; i++){
         prev = leftNode;
         leftNode = leftNode->next;
    }

    for(int i = 1; i < right; i++){
         rightNode = rightNode->next;
    }
    
    next = rightNode->next;

    ListNode* reverseHead = reverseList(leftNode, rightNode->next);
 
    // 1 2 3 4 5
    // 1 4 3 2 5

    if(prev != NULL){
        prev->next = reverseHead;
        
    }
    else
    {
        head = reverseHead;
    }
    leftNode->next = next;
    return head;
    
 }


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {1, 2, 3, 4, 5};

    ListNode* head = CreateNode(nums);

    int left = 1, right = 5;

    head = reverseBetween(head, left, right);

    Print(head);
}