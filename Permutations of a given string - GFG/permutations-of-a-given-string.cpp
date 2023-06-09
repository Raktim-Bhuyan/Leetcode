//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
		vector<string>find_permutation(string s)
		{
		    // Code here there
		    set<string>ans;
		    int n = s.size();
		    int fact[n+1];
		    fact[0] = 1;
		    for(int i=1;i<=n;i++){
		        fact[i] = i* fact[i-1];
		    }
		    for(int i=1;i<=fact[n];i++){
		        ans.insert(s);
		        next_permutation(s.begin(),s.end());
		    }
		    vector<string>res ;
		    for(auto it:ans){
		        res.push_back(it);
		    }
		    return res;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends