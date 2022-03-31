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
    ListNode* swapPairs(ListNode* head) {
        ListNode* curr=NULL,*prev=NULL,*next=NULL;
        
        for(prev=head;prev && prev->next;prev=prev->next)
        {
            next=prev->next;
            prev->next=next->next;
            next->next=prev;
            
            if(curr!=NULL)
            {
                curr->next=next;
            }
            curr=prev;
            if(head==prev)
                head=next;
        }
        return head;
    }
};