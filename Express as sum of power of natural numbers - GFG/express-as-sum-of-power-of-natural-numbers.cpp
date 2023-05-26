//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
#define ll long long
#define M 1000000007
class Solution{
    public:
    int dp[1001][1001];
    int solve(int i,vector<int> &v,int tot,int x){
        if(tot<0)return 0;
        if(i==v.size()){
            return 0==tot;
        }
        if(dp[i][tot]==-1){
            dp[i][tot] = solve(i+1,v,tot-v[i],x)%M+solve(i+1,v,tot,x)%M;
            dp[i][tot] %=M;
        }
        return dp[i][tot];
            
    }
    int numOfWays(int n, int x)
    {
        memset(dp,-1,sizeof(dp));
        vector<int> v;
        for(int i=1;pow(i,x)<=n;i++){
            v.push_back(pow(i,x));
        }
        
        return solve(0,v,n,n);
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