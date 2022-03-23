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
    bool isBalanced(TreeNode* root,int &h)
    {
        if(root==NULL)
            return true;
        int leftHeight=0;
        int rightHeight=0;
        if(!isBalanced(root->left,leftHeight) || !isBalanced(root->right,rightHeight))
            return false;
        if(abs(leftHeight-rightHeight)>1)
            return false;
        h=max(leftHeight,rightHeight)+1;
        return true;
    }
public:
    bool isBalanced(TreeNode* root) {
        int h=0;
        return isBalanced(root,h); 
    }
};