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
    int currSum=0;
    void convert(TreeNode* root)
    {
        if(root==NULL)
            return;
        if(root->right!=NULL)
            convert(root->right);
        root->val+=currSum;
        currSum=root->val;
        if(root->left!=NULL)
            convert(root->left);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        convert(root);
        return root;
    }
};