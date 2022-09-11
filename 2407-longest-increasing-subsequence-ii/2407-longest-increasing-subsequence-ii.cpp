
class SegTree
{
    int n;
    vector<int> tree;
    
    int qutil(int i,int ql,int qr,int l,int r)
    {
        if(l>=ql && r<=qr)
        {
            return tree[i];
        }
        if(l>qr || r<ql)
        {
            return INT_MIN;
        }
         
        int mid=(l+r)/2;
        return max(qutil(2*i+1,ql,qr,l,mid),qutil(2*i+2,ql,qr,mid+1,r));
    }
    
    void uutil(int i,int l,int r,int pos,int val)
    {
        if(pos<l || pos>r)
        {
            return;
        }
        if(l==r)
        {
            tree[i]=max(tree[i],val);
            return;
        }
        int mid=(l+r)/2;
        uutil(2*i+1,l,mid,pos,val);
        uutil(2*i+2,mid+1,r,pos,val);
        tree[i]=max(tree[2*i+1],tree[2*i+2]);
    }
    public:
    SegTree(int sz)
    {
        n=sz;
        int size=int(ceil(log2(n)));
        size=(2*pow(2,size))-1;
        tree = vector<int> (size);
        
    }
    
    int query(int l,int r)
    {
        return qutil(0,l,r,0,n-1);
    }
    void update(int i,int val)
    {
        uutil(0,0,n-1,i,val);
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int res=0;
        SegTree st(1e5+1);
        for(int num:nums)
        {
            int cur=1+st.query(max(0,num-k),num-1);
            st.update(num,cur);
            res=max(res,cur);
        }
        return res;
    }
};