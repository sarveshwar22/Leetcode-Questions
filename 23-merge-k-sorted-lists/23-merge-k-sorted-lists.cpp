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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i]!=NULL)
                pq.push({lists[i]->val,i});
        }
        
        ListNode* ans=new ListNode(-1);
        ListNode* head=ans;
        while(!pq.empty())
        {
            pair<int,int> top=pq.top();
            pq.pop();
            lists[top.second]=lists[top.second]->next;
            if(lists[top.second]!=NULL)
                pq.push({lists[top.second]->val,top.second});
            ans->next=new ListNode(top.first);
            ans=ans->next;
        }
        return head->next;
    }
};