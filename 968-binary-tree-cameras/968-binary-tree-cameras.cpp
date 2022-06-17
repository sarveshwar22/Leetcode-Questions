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
    int cameras=0;
    int minCamera(TreeNode* root)
    {
        if(root==NULL)
            return 1;
        
        int left = minCamera(root->left);
        int right = minCamera(root->right);
        if(left==-1 || right ==-1)
        {    
            cameras++;
            return 0;
        }
        if(left==0 || right ==0)
            return 1;
        
        return -1;
    }
public:
    int minCameraCover(TreeNode* root) {
        if(minCamera(root)==-1)
            cameras++;
        return cameras;
    }
};