class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int c = 0;
        for(int i=0; i<strs[0].size(); i++)
        {
            for(int j=1; j<strs.size(); j++)
            {
                if(strs[j-1][i] > strs[j][i] )
                {
                    c++;
                    break;
                }
            }
        }
        return c;
    }
};