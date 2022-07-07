class Solution {
public:
    string numberToWords(int num) {
        string w1[] = {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine"};
        string w2[] = {" Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen" };
        string w3[] = {"",  "",  " Twen", " Thir", " For", " Fif", " Six", " Seven", " Eigh", " Nine" };
        string e[] = {"", " Thousand", " Million", " Billion"};
        
        string s;
        int k=0;
        while(num) {
            string sub;
            int s4=num%1000, s3=s4/100, s2=s4%100;
            if(s4) s.insert(0, e[k]);
            if(s3) sub += w1[s3] + " Hundred";
            if(s2) sub += s2<20? (s2<10? w1[s2%10]: w2[s2%10]): w3[s2/10%10]+"ty"+w1[s2%10];
            s.insert(0, sub);
            num /= 1000;
            k++;
        }
        
        return s.size()? 
            string(s.begin()+1, s.end())
            : "Zero";
    }
};