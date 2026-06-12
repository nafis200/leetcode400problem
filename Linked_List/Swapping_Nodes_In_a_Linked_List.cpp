// 0 - 6 months:
// Google (3) — Amazon (2)

// 6 months ago:
// Meta (8) — Adobe (3) — Oracle (2) — Uber (2) — Nvidia (2) — Snowflake (2)

// Problem_Link: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/?envType=problem-list-v2&envId=linked-list

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


// Time o(n) space o(1) Two pass

// ListNode* swapNodes(ListNode* head, int k) {
//     int n = 0;
//     ListNode* temp = head;
//     while(temp != NULL){
//         n++;
//         temp = temp->next;
//     }
    
//     ListNode* first = head;
//     ListNode* second = head;

//     for(int i = 1; i < k; i++){
//          first = first->next;
//     }

//     for(int i = 1; i <= n - k; i++){
//         second = second->next;
//     }

//     swap(first->val, second->val);
//     return head;
// }


// One pass

//  1 2 3 4 5


ListNode* swapNodes(ListNode* head, int k) {
    
    ListNode* first = head;
    for(int i = 1; i < k; i++){
        first = first->next;
    }

    ListNode* second = head;
    ListNode* cur = first;

    while(cur->next != NULL){
        cur = cur->next;
        second = second->next;
    }

    swap(first->val, second->val);

    return head;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {1, 2, 3, 4, 5};

    ListNode* head = CreateNode(nums);

    head = swapNodes(head, 2);
    
    Print(head);
    
}