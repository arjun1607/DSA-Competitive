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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || head==NULL) return head;
        int len=0;
        ListNode *temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        k=k%len;
        if(k==0) return head;
        int count=len-k, i=1;
        temp=head;
        while(temp!=NULL && i<count){
            i++;
            temp=temp->next;
        }
        ListNode *finalhead=temp->next, *temp2=finalhead;
        while(temp2->next!=NULL){
            temp2=temp2->next;
        }
        temp->next=NULL;
        temp2->next=head;
        return finalhead;
    }
};