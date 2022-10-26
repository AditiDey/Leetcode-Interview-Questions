class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        
        int n=arr.size();
        unordered_map<int,long long> sum_map;
        unordered_map<int,long long> count_map;
        vector<long long> ans(n,0);
        
        for(int i=0;i<n;i++){
            if(count_map.find(arr[i])==count_map.end()){
                count_map[arr[i]]++;
                sum_map[arr[i]]+=i;
                ans[i]=0;
            }
            else{
                long long cnt=count_map[arr[i]];
                long long before_sum=sum_map[arr[i]];
                ans[i]=(long long)cnt*i - (before_sum);
                count_map[arr[i]]++;
                sum_map[arr[i]]+=i;
            }
        }
        
        count_map.clear();
        sum_map.clear();
       
        for(int i=n-1;i>=0;i--){
            if(count_map.find(arr[i])==count_map.end()){
                count_map[arr[i]]++;
                sum_map[arr[i]]+=i;
                ans[i]+=0;
            }
            else{
                long long cnt=count_map[arr[i]];
                long long after_sum=sum_map[arr[i]];
                ans[i]+=after_sum - (long long)(cnt*i);
                count_map[arr[i]]++;
                sum_map[arr[i]]+=i;
            }
        }
       
        return ans;
    }
};