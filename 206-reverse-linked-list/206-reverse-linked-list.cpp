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
    pair<ListNode*, ListNode*> helper(ListNode *head){
        if(head==NULL || head->next==NULL) return {head, head};
        auto it=helper(head->next);
        head->next=NULL;
        it.second->next=head;
        return {it.first, head};
    }
    ListNode* reverseList(ListNode* head) {
        return helper(head).first;
    }
};