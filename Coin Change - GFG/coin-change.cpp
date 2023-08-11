//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  long long int solve(int i,int coins[],int sum,vector<vector<long long int>>&dp){
      if(i ==0){
          return sum % coins[i] == 0;
      }
      if(dp[i][sum]!=-1)return dp[i][sum];
      long long int notTake = solve(i-1,coins,sum,dp);
      long long int take = 0;
      if(coins[i]<=sum){
          take = solve(i,coins,sum - coins[i],dp);
      }
      return dp[i][sum] = take + notTake;
  }
    long long int count(int coins[], int n, int sum) {

        // code here.
        vector<vector<long long int>>dp(n,vector<long long int>(sum+1,-1));
        return solve(n-1,coins,sum,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends