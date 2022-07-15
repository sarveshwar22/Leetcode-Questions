class Solution {
public:
    int compareVersion(string version1, string version2) {
       int i = 0; 
        int j = 0;
        int n1 = version1.size(); 
        int n2 = version2.size();
    
        while(i<n1 || j<n2)
        {
            int num1 = 0;
            int num2 = 0;
            while(i<n1 && version1[i]!='.')
            {
                num1 = num1*10+(version1[i]-'0');
                i++;
            }

            while(j<n2 && version2[j]!='.')
            {
                num2 = num2*10+(version2[j]-'0');;
                j++;
            }
            
            i++;
            j++;
            
            if(num1>num2) 
                return 1;
            else if(num1<num2) 
                return -1;
            
        }

        return 0; 
    }
};