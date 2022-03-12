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
    // ListNode* reverse(ListNode* l)
    // {
    //     if(l==NULL)
    //         return l;
    //     ListNode* prev=NULL;
    //     ListNode* curr=l;
    //     ListNode* next=curr->next;
    //     while(next!=NULL)
    //     {
    //         curr->next=prev;
    //         prev=curr;
    //         curr=next;
    //         next=next->next;
    //     }
    //     return curr;
    // }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ListNode* revl1=reverse(l1);
        // ListNode* revl2=reverse(l2);
        
        int carry=0;
        ListNode* curr= new ListNode(0);
        ListNode* head=curr;
        while(l1!=NULL || l2!=NULL || carry==1)
        {
            int sum=0;
            if(l1!=NULL)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            curr->next=new ListNode(sum%10);
            curr=curr->next;
        }
        return head->next;
        
    }
};