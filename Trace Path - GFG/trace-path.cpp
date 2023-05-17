//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        // code here
        int x = 0 , y = 0;
        int mx =0 , my = 0 , mnx = 0, mny =0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='L')x--;
            else if(s[i]=='R')x++;
            else if(s[i]=='D')y--;
            else if(s[i]=='U')y++;
            mx = max(mx,x);
            mnx = min(mnx,x);
            my = max(my,y);
            mny = min(mny,y);
        }
        if(mx-mnx<m and my- mny<n){
            return 1;
        }
        else{
            return 0;
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends