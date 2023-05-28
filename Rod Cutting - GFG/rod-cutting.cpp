//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int dp[1000][1001];
  int solve(int i,int price[],int length){
      if(i==0) return length*price[0];
      if(dp[i][length]!=-1)return dp[i][length];
      int rodLength = i+1;
      int pick =0;
      if(rodLength<=length){
           pick = price[i] + solve(i,price,length-rodLength);
      }
      int skip = solve(i-1,price,length);
      return dp[i][length]= max(pick,skip);
  }
    int cutRod(int price[], int n) {
        //code here
        memset(dp,-1,sizeof(dp));
        return solve(n-1,price,n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends