class Solution {
public:
    
	int solve(int e,int f,vector<vector<int>>&dp)
	{
		if(f==0||f==1)
		{
			return f;
		}
		if(e==1)
		{
			return f;
		}
		if(dp[e][f]!=-1)
		{
			return dp[e][f];
		}
		int mini=INT_MAX;
		for(int k=1;k<=f;k++)
		{
			int temp=1+max(solve(e-1,k-1,dp),solve(e,f-k,dp));
			mini=min(mini,temp);
		}
		return dp[e][f]=mini;

	}
	int twoEggDrop(int n) {
	
        vector<vector<int>>dp(3,vector<int>(1001,-1));
		return solve(2,n,dp);

	}
};