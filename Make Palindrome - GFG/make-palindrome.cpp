//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool makePalindrome(int n,vector<string> &arr){
        // Code here
        map<string,int>mp;
        for(auto it:arr){
            mp[it]++;
        }
        int cnt =0;
        for(auto it:mp){
            string s = it.first;
            reverse(s.begin(),s.end());
            if(it.first ==s)cnt++;
        }
        if(cnt>1)return false;
        for(auto it:mp){
            string s = it.first;
            reverse(s.begin(),s.end());
            if(it.second!=mp[s])return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends