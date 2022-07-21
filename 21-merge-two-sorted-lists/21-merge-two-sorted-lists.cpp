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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
     ListNode *fh=NULL, *ft=NULL;
        while(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                if(fh==NULL){
                    fh=l1; ft=l1;
                }
                else{
                    ft->next=l1;
                    ft=l1;
                }
                l1=l1->next;
            }else{
                if(fh==NULL){
                    fh=l2; ft=l2;
                }else{
                    ft->next=l2;
                    ft=l2;
                }
                l2=l2->next;
            }
        }

        if(l2==NULL){
            if(ft!=NULL) ft->next=l1;
            else fh=l1;
        }
        if(l1==NULL){
            if(ft!=NULL) ft->next=l2;
            else fh=l2;
        }
    
        return fh;
    }
};