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
    TreeNode* preNode=NULL,*firstNode=NULL,*secondNode=NULL;
    void recoverTreeHelper(TreeNode* root)
    {
        if(root==NULL)
            return;
        recoverTreeHelper(root->left);
        if(preNode!=NULL)
        {
            if(preNode->val>root->val)
            {
                if(firstNode==NULL)
                    firstNode=preNode;
                secondNode=root;
            }
        }
        preNode=root;
        recoverTreeHelper(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        recoverTreeHelper(root);
        swap(firstNode->val,secondNode->val);
    }
};