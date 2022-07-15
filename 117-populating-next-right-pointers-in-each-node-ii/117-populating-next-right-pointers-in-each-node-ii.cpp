/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root,Node* parent=NULL) {
        if(root==NULL)
            return NULL;
        if(parent && parent->left ==  root && parent->right)
        {
            parent->left->next = parent->right;
        }
        else if(parent)
        {
            parent = parent->next;
            while(parent && parent->left==NULL && parent->right==NULL)
            {
                parent=parent->next;
            }
            if(parent)
                root->next=parent->left?parent->left:parent->right;
        }
        if(root->right)
        {
            connect(root->right,root);
        }
        if(root->left)
        {
            connect(root->left,root);
        }
        return root;
    }
};