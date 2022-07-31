class NumArray {
    vector<int> seg;
    int n;// int len_segement_tree;
    void buildSegTree(vector<int> &nums,int left,int right,int pos)
    {
        if(left==right)
        {
            seg[pos] = nums[left];
            return;
        }
        int mid = (left+right)/2;
        buildSegTree(nums,left,mid,2*pos+1);
        buildSegTree(nums,mid+1,right,2*pos+2);
        seg[pos] = seg[2*pos+1]+seg[2*pos+2];
    }
    void updateUtil(int index,int val,int pos,int left,int right)
    {
        if(index<left || index>right)
            return;
        if(left == right)
        {
            if(left == index)
                seg[pos] = val;
            return;
        }
        int mid = (left+right)/2;
        updateUtil(index,val,2*pos+1,left,mid);
        updateUtil(index,val,2*pos+2,mid+1,right);
        seg[pos] = seg[2*pos+1]+seg[2*pos+2];  
    }
    int rangeUtil(int qleft,int qright,int left,int right,int pos)
    {
        if(qleft<=left && qright>=right)
            return seg[pos];
        if(qleft>right || qright<left)
            return 0;
        int mid = (left+right)/2;
        return rangeUtil(qleft,qright,left,mid,2*pos+1)+
            rangeUtil(qleft,qright,mid+1,right,2*pos+2);
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        if(n==0)
            return;
        seg.resize(4*n,0);
        buildSegTree(nums,0,n-1,0);
        // for(int i=0;i<4*n;i++)
        // {
        //     cout<<seg[i]<<" ";
        // }
    }
    
    void update(int index, int val) {
        if(n==0)
            return;
        updateUtil(index,val,0,0,n-1);
    }
    
    int sumRange(int left, int right) {
        if(n==0)
            return 0;
        return rangeUtil(left,right,0,n-1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */