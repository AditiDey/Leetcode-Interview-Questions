class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
         unordered_map<char, int> mp; 
        for(int i=0; i<order.size(); i++)
            mp[order[i]] = i;

        for(int i=0; i<words.size()-1; i++)
        {
            int j=0;
            while(j<words[i].size() && j<words[i+1].size()) 
            {
               
                if(mp[words[i][j]] < mp[words[i+1][j]]) 
                    break; 

               
                if(mp[words[i][j]] > mp[words[i+1][j]])
                    return false;
                j++;
            }
          
            if(j==words[i+1].size() && j<words[i].size())
                return false; 
        }
        return true;
    }
};