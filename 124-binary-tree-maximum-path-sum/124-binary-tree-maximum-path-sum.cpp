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
    int maxPathSum(TreeNode* root,int& maxval)
    {
        if(root==NULL)
            return 0;
        int l=max(maxPathSum(root->left,maxval),0);
        int r=max(maxPathSum(root->right,maxval),0);
        maxval=max({maxval,root->val+l+r});
        return root->val+max(l,r);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxVal=INT_MIN;
        maxPathSum(root,maxVal);
        return maxVal;
    }
};