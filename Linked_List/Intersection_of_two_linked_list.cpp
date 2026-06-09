// Google (4) — Microsoft (2) — Amazon (2)


#include<bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;

    ListNode(int val){
        this->val = val;
        next = NULL;
    }
};

ListNode* CreateNode(vector<int>& nums){
    ListNode* head = NULL;
    ListNode* temp = NULL;

    for(auto x : nums){
        ListNode* newNode = new ListNode(x);

        if(head == NULL){
            head = newNode;
            temp = newNode;
        }
        else{
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

ListNode* GetTail(ListNode* head){
    while(head->next != NULL){
        head = head->next;
    }
    return head;
}

void Print(ListNode* head){
    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << '\n';
}

// Time o((m + n) * log(m + n)) space o(m + n)

// ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//      map<ListNode*, int>mp;    
     
//      ListNode* temp = headA;
//      while(temp != NULL){
//          mp[temp]++;
//          temp = temp->next;
//      }

//      temp = headB;
//      while(temp != NULL){
//          mp[temp]++;
//          temp = temp->next;
//      }
//      ListNode* ans = NULL;

//      for(auto it : mp){
//          if(it.second == 2){
//              ans = it.first;
//              break;
//          }
//      }
//      return ans;
// }

// Time o(n + m) space o(1)

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
     ListNode* pa = headA;
     ListNode* pb = headB;

     while(pa != pb){
        if(pa == NULL){
            pa = headB;
        }
        else{
            pa = pa->next;
        }
        if(pb == NULL){
            pb = headA;
        }
        else{
            pb = pb->next;
        }
     }
     return pa;
}

int main(){


    vector<int> a = {4,1};
    vector<int> b = {5,6,1};
    vector<int> common = {8,4,5};

    ListNode* headA = CreateNode(a);
    ListNode* headB = CreateNode(b);
    ListNode* commonHead = CreateNode(common);

    GetTail(headA)->next = commonHead;
    GetTail(headB)->next = commonHead;

    ListNode* ans = getIntersectionNode(headA, headB);

    if(ans == NULL){
        cout << 0 << "\n";
    }
    else{
        cout << ans->val << "\n";
    }

    return 0;
}