// 0 - 3 months:
// Amazon (6) — Google (5) — Meta (3)

// 0 - 6 months:
// Microsoft (3) — Bloomberg (2) — TCS (2)

// 6 months ago:
// Apple (12) — Adobe (4) — Uber (4) — Goldman Sachs (3) — Intuit (3) — Qualcomm (3) — Walmart Labs (2) — Zoho (2) — Accenture (2) — Yahoo (2)

// Problem_Link: https://leetcode.com/problems/middle-of-the-linked-list/description/


#include<bits/stdc++.h>
using namespace std;

//  1 2 3 4 5 

//  slow = 1 first = 1

// slow2 first 3
// slow 3 first 5

//  1 2 3 4 5 6
// slow = 1 first = 1
// slow = 2 first = 3
// slow = 3 first = 5
// slow = 4 first = NULL


// Time o(n) space o(1)

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

ListNode* middleNode(ListNode* head) {
   
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL){
         slow = slow->next;
         fast = fast->next->next;
    }
    return slow;
    
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
    vector<int>nums = {1, 2, 3, 4 ,5, 6};

    ListNode* head = CreateNode(nums);
   
    ListNode* mid = middleNode(head);

    cout << mid->val << "\n";
 
    return 0;
}