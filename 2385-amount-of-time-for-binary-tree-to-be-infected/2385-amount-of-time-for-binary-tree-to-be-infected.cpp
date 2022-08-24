class Solution {
public:
    int ans = 0;
    void makeGraph(TreeNode *root,vector<vector<int>>& adj,int parent){
        if(root == NULL)
        {
            return;
        }

        if(parent!=-1)
        {
            adj[root->val].push_back(parent);
            adj[parent].push_back(root->val);
        }

        makeGraph(root->left,adj,root->val);
        makeGraph(root->right,adj,root->val);
    } 
    
    void dfs(int curr,vector<vector<int>> &adj, vector<int> &depth, int parent){
        if(parent!=-1) 
            depth[curr] = depth[parent]+1;

        ans = max(ans,depth[curr]);
        for(auto x : adj[curr]){
            if(x!=parent){
                dfs(x,adj,depth,curr);
            }
        }
    }
    
    int amountOfTime(TreeNode* root, int start) {
        int N = 1e5 + 1;
        vector<vector<int>> adj(N);
        makeGraph(root,adj,-1); 
        vector<int> depth(N); 
        dfs(start,adj,depth,-1);
        return ans;
    }
    
//     int dist = 0;
//     pair<int, int> dfs(TreeNode* root, int start) {
//         if (root == nullptr)
//             return {0, 0};
//         auto [d1, inf_d1] = dfs(root->left, start);
//         auto [d2, inf_d2] = dfs(root->right, start);
//         if (inf_d1 != inf_d2)
//             dist = max(dist, inf_d1 > 0 ? d2 + inf_d1 : d1 + inf_d2);
//         return {max(d1, d2) + 1, max(inf_d1, inf_d2) + (n->val == start || inf_d1 != inf_d2) };
// }
// int amountOfTime(TreeNode* root, int start) {
//     auto [depth, inf_depth] = dfs(root, start);
//     return max(dist, depth - inf_depth);
// }
};