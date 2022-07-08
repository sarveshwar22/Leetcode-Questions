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
    int length(ListNode* head)
    {
        int count=0;
        while(head)
        {
            head=head->next;
            count++;
            
        }
        return count;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int steps=k;
        if(length(head)<k)
            return head;
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next;
        while(steps-- && curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        // if(next!=NULL)
        head->next=reverseKGroup(next,k);
        return prev;
    }
};