class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        if(n1%2 == 0 && n2%2 == 0) 
            return 0;
        int ans = 0;
        if(n2 % 2 ) 
            for(auto i: nums1)
                ans = ans^i;
        if(n1 % 2 ) 
            for(auto i: nums2) 
                ans = ans^i;
        return ans;
    }
};