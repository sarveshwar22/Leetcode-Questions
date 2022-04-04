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
    Node* connect(Node* root,Node* next=NULL) {
//         if(root==NULL)
//             return root;
//         queue<Node*> q;
//         q.push(root);
//         while(!q.empty()){
//             int n=q.size();
//             for(int i=0;i<n;i++){
//                 Node* x=q.front();
//                 q.pop();
//                 if(i!=n-1)x->next=q.front();
//                 if(x->left)q.push(x->left);
//                 if(x->right)q.push(x->right);
//             }
//         }
//         return root;
        
        if(root==NULL)
            return root;
        root->next=next;
        if(root->left==NULL)
            return root;
        connect(root->left,root->right);
        connect(root->right,next?next->left:NULL);
        return root;
    }
};