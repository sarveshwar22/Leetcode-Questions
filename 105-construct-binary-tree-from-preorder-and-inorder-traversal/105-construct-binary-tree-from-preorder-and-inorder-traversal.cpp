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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,int& rootIdx,int start,int end)
    {
        if(start>end)
            return NULL;
        
        int pivot=start;
        while(inorder[pivot]!=preorder[rootIdx])
            pivot++;
        
        rootIdx++;
        
        TreeNode* newNode=new TreeNode(inorder[pivot]);
        newNode->left=buildTree(preorder,inorder,rootIdx,start,pivot-1);
        newNode->right=buildTree(preorder,inorder,rootIdx,pivot+1,end);
        return newNode;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx=0;
        return buildTree(preorder,inorder,rootIdx,0,inorder.size()-1);
    }
};