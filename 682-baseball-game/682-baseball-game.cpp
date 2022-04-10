class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        for(int i=0;i<ops.size();i++)
        {
            if(ops[i]=="C")
            {
                if(!s.empty())
                {
                    s.pop();
                } 
            }
            
            else if(ops[i]=="D")
            {
                if(!s.empty())
                {
                    s.push(2*s.top());
                }
            }
            
            else if(ops[i]=="+")
            {
                int num1=s.top();
                s.pop();
                int num2=s.top()+num1;
                s.push(num1);
                s.push(num2);
            }
            
            else
            {
                s.push(stoi(ops[i]));
            }
        }
        int sum=0;
        while(!s.empty())
        {
            sum+=s.top();
            s.pop();
        }
        return sum;
    }
};