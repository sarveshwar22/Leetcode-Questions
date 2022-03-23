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
        if(head==NULL)
            return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        int n=1;
        while(fast->next!=NULL)
        {
            fast=fast->next;
            n++;
        }
        k%=n;
        fast->next=slow;
        k=n-k-1;
        while(k--)
        {
            slow=slow->next;
        }
        ListNode* newHead=slow->next;
        slow->next=NULL;
        
        return newHead;
        
    }
};