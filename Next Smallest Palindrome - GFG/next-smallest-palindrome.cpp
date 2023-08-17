//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> generateNextPalindrome(int num[], int n) {
	    // code here
	    bool change = 1;
	    for(int i=0;i<n/2;i++){
	        if(num[i]<num[n-i-1]){
	            num[n-i-1] = num[i];
	            change = 1;
	        }
	        else if(num[i]>num[n-i-1]){
	            num[n-i-1] = num[i];
	            change = 0;
	        }
	    }
	    vector<int>ans(n);
	    for(int i=0;i<n;i++){
	        ans[i] = num[i];
	    }
	    int idx = n/2;
	    bool carry = change;
	    while(carry and idx<n){
	        if(ans[idx] == 9){
	            ans[idx] = 0;
	            ans[n-idx-1] = 0;
	        }
	        else{
	            ans[idx]++;
	            ans[n-idx-1] = ans[idx];
	            carry = 0;
	        }
	        idx++;
	    }
	    if(carry){
	        ans[0] = 1;
	        ans.push_back(1);
	    }
	    return ans;
	}

};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends