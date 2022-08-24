class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int ans=0;
        int n=energy.size();
        for(int i=0;i<n;i++)
        {
            if(energy[i]>=initialEnergy)
            {
                ans+=energy[i]-initialEnergy+1;
                initialEnergy+=energy[i]-initialEnergy+1;
            }
            if(experience[i]>=initialExperience)
            {
                ans+=experience[i]-initialExperience+1;
                initialExperience+=experience[i]-initialExperience+1;
                
            }
            initialEnergy-=energy[i];
            initialExperience+=experience[i];
        }
        return ans;
    }
};