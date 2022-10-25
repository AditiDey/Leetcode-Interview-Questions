class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        string ans[numRows];
        int currow=0,mod=1;
        for(auto e:s)
        {
            ans[currow].push_back(e);
            if(currow==0)
                mod=1;
             if(currow==numRows-1)
                mod=-1;
            currow+=mod;
        }
        s.clear();
        for(auto e:ans)
        {
            s.append(e);
        }
        return s;
    }
};