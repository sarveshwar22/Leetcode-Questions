/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * }
 */
class Solution {
    stack<int>s;
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        bool left,right;
        left=isValidBST(root->left);
        if(!s.empty())
        {
            if(s.top()>=root->val)
                return false;
            s.pop();
            s.push(root->val);
        }
        else
        {
            s.push(root->val);
        }
        right=isValidBST(root->right);
        return left && right;
    }
};