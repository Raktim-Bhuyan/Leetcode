//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int n, int k) {
        // code here
        bool  ftl = true;
        //first to last
        int fs = 1,ls = n; //first start , last start
        int ans = 1;
        while(fs<=ls){
            if(ftl){
                for(int i=1;i<=k;i++){
                    ans = fs;
                    fs++;
                    if(fs>ls){
                        break;
                    }
                    //if(fs)
                }
                ftl = !ftl;
            }
            else{
                for(int i=0;i<k;i++){
                    ans = ls;
                    ls--;
                    if(fs>ls)break;
                }
                ftl = !ftl;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends