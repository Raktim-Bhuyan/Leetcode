//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int M = 1e9 + 7;
    int dp[1001][1001];
    
    int solve(int i,vector<int> &v,int tot){
        if(tot<0)return 0;
        if(i==v.size()){
            return 0==tot;
        }
        if(dp[i][tot]!=-1)return dp[i][tot];
       
         return  dp[i][tot] = (solve(i+1,v,tot-v[i])%M+solve(i+1,v,tot)%M)%M;
      
            
    }
    int numOfWays(int n, int x)
    {
        memset(dp,-1,sizeof(dp));
        vector<int> v;
        for(int i=1;pow(i,x)<=n;i++){
            v.push_back(pow(i,x));
        }
        
        return solve(0,v,n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends