//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
int cnt_set(int n){
    int ans  =0;
    if(n<0)return 0;
    for(int i=0;i<32;i++){
        ans += (1 & n>>i);
    }
    return ans;
}
	int is_bleak(int n)
	{
	    // Code here.
	    for(int i=(n-30);i<=n;i++){
	        if(i + cnt_set(i) == n){
	            return 0;
	        }
	    }
	    return 1;
	    
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends