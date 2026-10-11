/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
// ListNode* reverse(ListNode* l1){
//    ListNode* curr=l1;
//    ListNode* pre=NULL;
//    while(curr){
//     ListNode* newnode=curr->next;
//     curr->next=pre;
//     pre=curr;
//     curr=newnode;
//    }
   //return pre;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode* a=l1;
        ListNode* b=l2;
        int carry=0;
        ListNode* temp=new ListNode(-1);
        ListNode* m=temp;
        while(a&&b){
          int p=a->val+b->val+carry;
          int d=p%10;
          carry=p/10;
          ListNode* ans=new ListNode(d);
          m->next=ans;
          m=m->next;
          a=a->next;
          b=b->next;
        }
        if(a==NULL&&b==NULL){
          if(carry!=0){
             ListNode* ans=new ListNode(carry);
          m->next=ans;
         m=m->next;
          }
        }
        if(a){
          while(a){
             int p=a->val+carry;
              int d=p%10;
          carry=p/10;
           ListNode* ans=new ListNode(d);
          m->next=ans;
         m=m->next;
          a=a->next;

          }
          if(carry!=0){
             ListNode* ans=new ListNode(carry);
          m->next=ans;
         m=m->next;
          }
        }
         if(b){
          while(b){
             int p=b->val+carry;
              int d=p%10;
          carry=p/10;
           ListNode* ans=new ListNode(d);
          m->next=ans;
         m=m->next;
          b=b->next;

          }
          if(carry!=0){
             ListNode* ans=new ListNode(carry);
          m->next=ans;
         m=m->next;
          }
        }
      // ListNode* final= reverse(temp->next);

      return temp->next;
    }
};