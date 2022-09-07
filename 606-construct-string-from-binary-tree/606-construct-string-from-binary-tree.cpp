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
public:
    string tree2str(TreeNode* t) {
        if(t==nullptr)
            return "";
        if(t->left!=nullptr || t->right!=nullptr){
            if(t->left!=nullptr && t->right==nullptr){
                string left=tree2str(t->left);
                return to_string(t->val)+"("+left+")";
            }
            else{
                string left=tree2str(t->left);
                return to_string(t->val)+"("+left+")"+"("+tree2str(t->right)+")";
            }
        }
        else{
            return to_string(t->val);
        }
    }
};