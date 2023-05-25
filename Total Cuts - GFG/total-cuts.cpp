//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int n,int k,vector<int> &a){
        // Code here
        vector<int>largest(n),smallest(n);
        largest[0] = a[0];
        for(int i=1;i<n;i++){
            largest[i] = max(a[i],largest[i-1]);
        }
        smallest[n-1] = a[n-1];
        for(int i=n-2;i>=0;i--){
            smallest[i] = min(a[i],smallest[i+1]);
        }
        int ans = 0;
        for(int i=0;i<n-1;i++){
            if(largest[i]+ smallest[i+1]>=k){
                ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends