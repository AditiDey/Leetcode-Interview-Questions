class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count0 = 0, left = 0;
        int maxi = 0;
        for( int right = 0 ; right < nums.size() ; right++ ) {
            if( nums[right] == 0 ) 
                count0++;
            while( count0>k )
            {
                if( nums[left] == 0 )
                {
                    count0--;
                }
                left++;
            }
            maxi = max( maxi, right - left + 1 );
        }
        return maxi;
    }
};