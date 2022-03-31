/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)
                break;
        }
        int c=1;
        if(fast==NULL || fast->next==NULL)
            return NULL;
        
        slow=slow->next;
        while(slow!=fast)
        {
            slow=slow->next;
            c++;
        }
        
        
        slow=head;
        fast=head;
        while(c--)
        {
            fast=fast->next;
        }
        
        
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
            if(fast->next==slow)
                break;
            
        }
        return slow;
    }
};