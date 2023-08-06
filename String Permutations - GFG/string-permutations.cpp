//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    vector<string>ans;
    int n ;
    void solve(int idx,string s){
        if(idx == n){
            ans.push_back(s);
            return;
        }
        for(int i=idx;i<n;i++){
            swap(s[idx],s[i]);
            solve(idx +1,s);
            swap(s[idx],s[i]);
        }
    }
    vector<string> permutation(string s)
    {
        //Your code here
        n = s.size();
        solve(0,s);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends