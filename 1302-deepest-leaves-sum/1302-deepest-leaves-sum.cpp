class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int sz = q.size();
            sum = 0;
            for(int i=0; i<sz; i++)
            {
                TreeNode* front = q.front();
                q.pop();
                sum += front->val;
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
        }
		
        return sum;
    }
};