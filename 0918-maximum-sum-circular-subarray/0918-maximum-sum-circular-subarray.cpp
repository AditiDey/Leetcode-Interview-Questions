class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
      int maxi=INT_MIN,mini=INT_MAX,sum1=0,sum2=0,total_sum=0;
        for(auto it:nums)
        {
            total_sum+=it;
             sum1+=it;
            maxi=max(maxi,sum1);
              sum2+=it;
            mini=min(mini,sum2);
            if(sum1<0)
                sum1=0;
            if(sum2>0)
                sum2=0;
        }
            if(total_sum==mini)
                return maxi;
            else 
                return max(maxi,total_sum-mini);
        }
        
    
};