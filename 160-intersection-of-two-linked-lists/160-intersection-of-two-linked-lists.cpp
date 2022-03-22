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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1=0,n2=0;
        ListNode* head1=headA;
        while(head1)
        {
            head1=head1->next;
            n1++;
        }
        ListNode* head2=headB;
        while(head2)
        {
            head2=head2->next;
            n2++;
        }
        
        head1=headA;
        head2=headB;
        
        while(n1>n2)
        {
            head1=head1->next;
            n1--;
        }
        while(n2>n1)
        {
            head2=head2->next;
            n2--;
        }
        while(head1!=head2)
        {
            head1=head1->next;
            head2=head2->next;
        }
        return head1;
    }
};