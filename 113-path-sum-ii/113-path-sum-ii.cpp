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
    vector<vector<int>> ans;
    vector<int> currPath;
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return ans;
        currPath.push_back(root->val);
        targetSum-=root->val;
        if(root->left==NULL && root->right==NULL && targetSum==0)
        {
            ans.push_back(currPath);
        }
        ans = pathSum(root->left,targetSum);
        ans = pathSum(root->right,targetSum);
        currPath.pop_back();
        return ans;
    }
};