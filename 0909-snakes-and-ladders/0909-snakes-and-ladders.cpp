class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<int> moves(n*n+1,-1);
        int count=1;
        bool leftToRight=true;
        for(int i=n-1;i>=0;i--)
        {
            if(leftToRight==true)
            {
                for(int j=0;j<n;j++)
                {
                moves[count]=board[i][j];
                count++;
                }
            }
            else
            {
                for(int j=n-1;j>=0;j--)
                {
                moves[count]=board[i][j];
                count++;
                }
            }
            leftToRight=!leftToRight;
        }
        
        queue<pair<int,int>> q;
        vector<int> vis(n*n+1,0);
        q.push({0,1});
        vis[1]=1;
        while(!q.empty())
        {
            int node=q.front().second;
            int steps=q.front().first;
            q.pop();
            
            if(node==n*n)
            {
                return steps;
            }
            
            for(int i=node+1;i<=node+6 && i<=n*n;i++)
            {
                if(vis[i]==0)
                {
                    if(moves[i]!=-1)
                    {
                        q.push({steps+1,moves[i]});
                    }
                    else
                    {
                        q.push({steps+1,i});
                    }
                    vis[i]=1;
                }
            }
        }
        return -1;
    }
};