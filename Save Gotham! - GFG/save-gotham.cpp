//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int save_gotham(int arr[], int n);



int main() {
    
    int t;
    cin>> t;
    while(t--)
    {
        int n;cin>>n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        cout << save_gotham(arr, n) << endl;
    }
    
	return 0;
}
// } Driver Code Ends


int save_gotham(int arr[], int n)
{
    // Complete the function
    stack<int> st;
    st.push(arr[n-1]);
    int sum=0;
    int mod=1e9+1;
    
    for(int i=n-2;i>=0;i--)
    {
        if(st.top()>arr[i])
        sum+=st.top();
        
        else
        {
            while(!st.empty() and st.top()<=arr[i])
            {
                st.pop();
            }
            if(st.empty())
            sum+=0;
            else
            sum+=st.top();
        }
        
        st.push(arr[i]);
    }
    return sum%mod;
}