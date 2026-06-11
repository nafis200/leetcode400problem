// 0 - 3 months:
// Amazon (5) — Google (4)

// 0 - 6 months:
// Meta (4) — Microsoft (2) — Bloomberg (2) — TikTok (2) — Arista Networks (2) — Snap (2)

// 6 months ago:
// Adobe (12) — Apple (9) — Uber (5) — Goldman Sachs (3) — LinkedIn (2) — Yahoo (2)

// Problem_Link: https://leetcode.com/problems/reorder-list/description/


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

// Time o(n) space o(n)

// void reorderList(ListNode* head) {
//     vector<ListNode*>v;

//     ListNode* temp = head;

//     while(temp != NULL){
//         v.push_back(temp);
//         temp = temp->next;
//     }

//     int i = 0, j = v.size() - 1;

//     while(i < j){
//         v[i]->next = v[j];
//         i++;
//         if(i == j){
//             break;
//         }
//         v[j]->next = v[i];
//         j--;
//     }
//     v[i]->next = NULL;
// }

//  1 2 3 4 5

//  4 5
// 

// Time o(n) space o(1)

ListNode* reverseList(ListNode* head){
    ListNode* prev = NULL;
    ListNode* cur = head;
    
    while (cur != NULL)
    {
       ListNode* nextnode = cur->next;
       cur->next = prev;
       prev = cur;
       cur = nextnode;   
    }
    return prev;
    
    
}

// 1 2 3
// 5 4
// first = 1
// second = 5

// temp1 = 2
// temp2 = 4

// 1 5 2 4 3

void reorderList(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    ListNode* secondHalf =  reverseList(slow->next);
    slow->next = NULL;
    
    ListNode* firstHalf = head;
    while(secondHalf != NULL){
       ListNode* temp1 = firstHalf->next;
       ListNode* temp2 = secondHalf->next;

       firstHalf->next = secondHalf;
       secondHalf->next = temp1;

       firstHalf = temp1;
       secondHalf = temp2;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {1, 2, 3, 4, 5};

    ListNode* head = CreateNode(nums);
    
    reorderList(head);
   
    Print(head);
}