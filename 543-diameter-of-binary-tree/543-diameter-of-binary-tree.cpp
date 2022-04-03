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
    int diameterOfBinaryTree(TreeNode* root, int& result) {
        if (root == NULL) 
            return 0;
        int l = diameterOfBinaryTree(root->left , result);
        int r = diameterOfBinaryTree(root->right, result);
        result = max(result, l + r);
        return max(l, r) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        diameterOfBinaryTree(root, result);
        return result;
    }
    
    
};