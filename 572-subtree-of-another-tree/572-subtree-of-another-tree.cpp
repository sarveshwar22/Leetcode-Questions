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
    bool isEqual(TreeNode* root,TreeNode* subRoot)
    {
       if(!root && !subRoot)
           return true;
        if(!root || !subRoot)
            return false;
        if(root->val!=subRoot->val)
            return false;
        
        return isEqual(root->left,subRoot->left) && isEqual(root->right,subRoot->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)
            return false;
        if(isEqual(root,subRoot))
            return true;
        return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
};