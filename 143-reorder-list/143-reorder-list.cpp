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
    void reorderList(ListNode* head) {
        if(head==NULL)
            return;
        ListNode* temp=head;
        ListNode* mid=head;
        while(temp!=NULL && temp->next!=NULL)
        {
            mid=mid->next;
            temp=temp->next->next;
        }
        ListNode* head2=mid->next;
        mid->next=NULL;
        ListNode* prev=NULL,*curr=NULL,*next=head2;
        while(next!=NULL)
        {
            prev=curr;
            curr=next;
            next=next->next;
            curr->next=prev;
        }
        
        head2=curr;
        
        
        ListNode* curr1=head,*curr2=head2;
        ListNode*temp1,*temp2;
        
        while(curr1 && curr2)
        {
            temp1=curr1->next;
            temp2=curr2->next;
            curr1->next=curr2;
            curr2->next=temp1;
            curr1=temp1;
            curr2=temp2;
        }
    }
};