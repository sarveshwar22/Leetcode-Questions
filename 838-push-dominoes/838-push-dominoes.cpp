class Solution {
public:
    string pushDominoes(string dominoes) {
        int l=0;
        int n=dominoes.size();
        for(int r=0;r<n;r++)
        {
            if(dominoes[r]=='.')
            {
                continue;
            }
            // L........L R......R                      ...........L
            else if(dominoes[l]==dominoes[r] || (dominoes[l]=='.' && dominoes[r]=='L'))
            {
                for(int k=l;k<r;k++)
                {
                    dominoes[k]=dominoes[r];
                }
            }
            else if (dominoes[l]=='L' && dominoes[r]=='R')
            {
                
            }
            else if(dominoes[l]=='R' && dominoes[r]=='L')
            {
                int mid=(r-l-1)/2;
                for(int k=1;k<=mid;k++)
                {
                    dominoes[r-k]='L';
                    dominoes[l+k]='R';
                }
            }
            l=r;
        }
        if(dominoes[l]=='R')
        {
            for(int k=l;k<n;k++)
            {
                dominoes[k]='R';
            }
        }
        return dominoes;
    }
};