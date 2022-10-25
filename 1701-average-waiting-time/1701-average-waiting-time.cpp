class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double lasttime = customers[0][0] + customers[0][1];
    double count = customers[0][1];
    
    for(int i = 1 ; i < customers.size() ; i++)
    {
        if(lasttime > customers[i][0])
        {
            count += lasttime - customers[i][0] + customers[i][1];
            lasttime = lasttime + customers[i][1];
        }
        else
        {
            count += customers[i][1];
            lasttime = customers[i][0] + customers[i][1];;
        }
    }
    
    return count / (customers.size());
    }
};