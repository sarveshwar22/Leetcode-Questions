/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
//     TreeNode* temp;
//     TreeNode* f(TreeNode* root)
//     {
//         TreeNode* head = new TreeNode(root->val);
//         temp =head;
//         head->left=NULL;
//         if(root->left!=NULL){
//             head->right = f(root->left);
//             root->left=NULL;
//             head = head->right;
//             head->left = NULL;
//         }
//         if(root->right!=NULL)
//         {
//             head->right = f(root->right);
//             root->right=NULL;
//             head=head->right;
//             head->left=NULL;
//         }
//         root=NULL;
//         return temp;
        
//     }
    TreeNode* prev=NULL;
public:
    void flatten(TreeNode* root) {
        if(root==NULL)return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left=NULL;
        prev=root;
    }
};