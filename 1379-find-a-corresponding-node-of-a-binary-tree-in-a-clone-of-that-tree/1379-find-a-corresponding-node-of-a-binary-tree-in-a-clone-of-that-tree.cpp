/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* ans=NULL;
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original==NULL || cloned==NULL)
            return ans;
        if(target->val==cloned->val)
            ans=cloned;
        ans = getTargetCopy(original->left,cloned->left,target);
        ans = getTargetCopy(original->right,cloned->right,target);
        return ans;
    }
};