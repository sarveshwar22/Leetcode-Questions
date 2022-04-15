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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr=head;
        ListNode* prev=head;
        int diff=right-left;
        int temp=left;
        left--;
        while(left--)
        {
            prev=curr;
            curr=curr->next;
        }
        ListNode* newCurr=curr;
        ListNode* newPrev;
        ListNode* newNext=curr->next;
        while(diff--)
        {
            newPrev=newCurr;
            newCurr=newNext;
            newNext=newNext->next;
            newCurr->next=newPrev;
        }
        prev->next=newCurr;
        curr->next=newNext;
        
        if(temp==1)
            return newCurr;
        
        return head;
        
    }
};