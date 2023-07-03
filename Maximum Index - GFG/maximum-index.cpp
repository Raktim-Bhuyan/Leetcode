//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
//Prefix Sum + Sliding Window
    int maxIndexDiff(int a[], int n) {
        // code here
       
        //prefix will store the min till date and suffix will store the maximum from end till date
        vector<int>pf(n,0) , sf(n,0);
        pf[0] = a[0] ; sf[n-1] = a[n-1];
        for(int i=1;i<n;i++){
            pf[i] = min(a[i],pf[i-1]);
            sf[n-1-i] = max(a[n-1-i],sf[n-i]);
        }
        int i,j,ans ;
        i =j = ans =0;
        while(j<n){
            if(pf[i]<=sf[j]){
                ans = max(ans,j-i);
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends