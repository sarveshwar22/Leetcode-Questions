/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m,vector<int>(n,-1));
        int i=0;
        int j=0;
        while(head!=NULL)
        {
            while(j<n && head!=NULL && res[i][j]==-1)
            {
                res[i][j]=head->val;
                head=head->next;
                j++;
            }
            i++;
            j--;
            while(i<m && head!=NULL && res[i][j]==-1)
            {
                res[i][j]=head->val;
                head=head->next;
                i++;
            }
            i--;
            j--;
            while(j>=0 && head!=NULL && res[i][j]==-1)
            {
                res[i][j]=head->val;
                head=head->next;
                j--;
            }
            j++;
            i--;
            while(i>=0 && head!=NULL && res[i][j]==-1)
            {
                res[i][j]=head->val;
                head=head->next;
                i--;
            }
            i++;
            j++;
            n--;
            m++;
        }
        return res;
    }
};