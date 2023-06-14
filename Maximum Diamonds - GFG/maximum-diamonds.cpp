//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long maxDiamonds(int a[], int n, int k) {
        // code here
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            pq.push(a[i]);
        }
        long long ans =0;
        while(!pq.empty() and k){
            int x = pq.top();
            x/=2;
            ans+=(pq.top());
            k--;
            pq.push(x);
            pq.pop();
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.maxDiamonds(A,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends