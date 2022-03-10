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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *t1=l1, *t2=l2;
        ListNode *ans=new ListNode(), *temp=ans;
        int carry=0;
        while(t1!=NULL || t2!=NULL){
            int sum=carry;
            if(t1!=NULL) sum+=t1->val;
            if(t2!=NULL) sum+=t2->val;
            int onesdigit=sum%10;
            carry=sum/10;
            ListNode *newNode = new ListNode(onesdigit);
            temp->next=newNode;
            temp=newNode;
            if(t1!=NULL) t1=t1->next;
            if(t2!=NULL) t2=t2->next;
        }
        if(carry!=0){
            ListNode *newNode = new ListNode(carry);
            temp->next=newNode;
        }
        return ans->next;
    }
};