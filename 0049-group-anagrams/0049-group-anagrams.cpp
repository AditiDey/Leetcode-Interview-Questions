class Solution {
public:
    /*
         vector<vector<string>>ans;
 
    vector<string> temp = strs ;
        map<string, vector<string>> mp;
        for(int i=0; i < temp.size() ; i++)
		{
            string t = temp[i];
            sort(temp[i].begin(), temp[i].end());
            mp[temp[i]].push_back(t);
        }
        for(auto i:mp) ans.push_back(i.second);
        return ans;
        */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(auto i:strs)
        {
            string temp=i;
            sort(i.begin(),i.end());
            mp[i].push_back(temp);
            
        }
        for(auto x:mp)
        {
            vector<string>temp=x.second;
            ans.push_back(temp);
        }
        return ans;
    }
};
