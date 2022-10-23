class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
         int count=0;
        vector<int>res;
        for(int i=0; i<rectangles.size();i++)
        {
            int m=rectangles[i][0], n=rectangles[i][1];
            int y=min(m,n);
            res.push_back(y);
        }
        sort(res.begin(),res.end());
        int n=res.size();
        int x=res[n-1];
        for(int i=0;i<n;i++)
        {
            if(res[i]==x)
                count++;
        }
        return count;
    }
};