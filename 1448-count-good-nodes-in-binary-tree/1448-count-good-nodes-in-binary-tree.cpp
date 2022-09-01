class Solution {
public:
    int ans=0;
    void pre(TreeNode* root,int maxi=INT_MIN){
        if(root==NULL)
            return;
        if(root->val>=maxi){
            ans++;
            maxi = root->val;
        }
        pre(root->left,maxi);
        pre(root->right,maxi);
    }
    int goodNodes(TreeNode* root) {
        pre(root);
        return ans;
    }
};