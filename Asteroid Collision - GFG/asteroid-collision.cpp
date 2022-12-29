//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        // code here
      
        stack<int> st;
        int left = 0;
        st.push(left);
        vector<int> ans;
        left++;
        while(left < N)
        {
            if(!st.empty() && asteroids[st.top()] > 0 && asteroids[left] < 0)
            {
                if(asteroids[st.top()] > (-1*asteroids[left]))
                {
                    left++;
                }
                else if(asteroids[st.top()] == (-1*asteroids[left]))
                {
                    left++;
                    st.pop();
                }
                else
                {
                    st.pop();
                }
            }
            else
            {
                st.push(left);
                left++;
            }
        }
        while(!st.empty())
        {
            ans.push_back(asteroids[st.top()]);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends