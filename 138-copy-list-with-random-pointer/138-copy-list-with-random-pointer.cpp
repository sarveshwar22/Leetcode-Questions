/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr=head;
        while(curr)
        {
            Node* newNode= new Node(curr->val);
            newNode->next=curr->next;
            curr->next=newNode;
            curr=newNode->next;
        }
        curr=head;
        while(curr && curr->next)
        {
            if(curr->random)
                curr->next->random=curr->random->next;
            curr=curr->next->next;
        }
        
        Node* newHead=NULL, *newCurr=NULL;
        curr=head;
        
        while(curr && curr->next)
        {
            if(newHead==NULL)
            {
                newHead=curr->next;
                newCurr=newHead;
            }
            else
            {
                newCurr->next=curr->next;
                newCurr=newCurr->next;
            }
            curr->next=curr->next->next;
            curr=curr->next;
        }
        return newHead;
    }
};