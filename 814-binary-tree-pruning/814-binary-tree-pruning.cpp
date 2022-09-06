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
public:
    TreeNode* pruneTree(TreeNode* root) {
        
        if(root==NULL)
            return NULL;
        bool l=(pruneTree(root->left)!=NULL);
        bool r=(pruneTree(root->right)!=NULL);
        bool flag=l||r;
        if(!l)
            root->left=NULL;
        if(!r)
            root->right=NULL;
        
        if(flag || root->val==1)
            return root;
        return NULL;
        
    }
};