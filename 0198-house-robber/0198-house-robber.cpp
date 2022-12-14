class Solution {
public:
    
    int f(int i,vector<int>&nums,vector<int>&dp)
    {
        if(i==0)
            return nums[i];
        if(i<0)
            return 0;
        int take=0,nottake=0;
        if(dp[i]!=-1)
            return dp[i];
        take=nums[i]+f(i-2,nums,dp);
        nottake=0+f(i-1,nums,dp);
        return dp[i]=max(take,nottake);
        
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return f(n-1,nums,dp);
    }
    
};