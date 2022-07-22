class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        set<ListNode*> s1, s2;
        ListNode*temp=head;
        while(temp!=NULL){
            if(temp->val<x) s1.insert(temp);
            else s2.insert(temp);
            temp=temp->next;
        }
        ListNode *dummy=new ListNode();
        temp=dummy;
        for(auto i:s1){
            temp->next=i;
            temp=i;
        }
        for(auto i:s2){
            temp->next=i;
            temp=i;
        }
        temp->next=NULL;
        return dummy->next;
    }
};