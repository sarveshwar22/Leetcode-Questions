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
    bool isEqual(TreeNode* left,TreeNode* right)
    {
        bool ans=true;
        if(left!=NULL && right!=NULL)
        {
            ans=isEqual(left->left,right->right) &&(left->val==right->val) && isEqual(left->right,right->left);
        }
        else
        {
            if(left==NULL && right==NULL)
                return true;
            else
                return false;
        }
        return ans;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return isEqual(root->left,root->right);
    }
};