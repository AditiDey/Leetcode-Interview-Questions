class Solution {
public:
   
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<vector<int>>dp(1005,vector<int>(1005,-1));
        vector<vector<int>>grp;
        for(int i=0;i<scores.size();i++)
        {
            grp.push_back({scores[i],ages[i]});
        }
        sort(grp.begin(),grp.end());     
      
        return recur(grp,0,ages.size(),0,dp);
    }
    
    int recur(vector<vector<int>>&grp , int i , int n , int maxiAge,vector<vector<int>>&dp)
    {
        if(i==n)
            return 0;
        if(dp[i][maxiAge]!=-1)
            return dp[i][maxiAge];
        
        if(grp[i][1]>=maxiAge)
        {
            return dp[i][maxiAge] = max(grp[i][0]+recur(grp,i+1,n,grp[i][1],dp),recur(grp,i+1,n,maxiAge,dp));
        }
        return dp[i][maxiAge] = recur(grp,i+1,n,maxiAge,dp);
    }
};