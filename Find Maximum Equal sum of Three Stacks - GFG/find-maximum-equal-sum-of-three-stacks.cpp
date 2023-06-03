//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
#define acc(s) accumulate(s.begin(),s.end(),0)
class Solution{
public:
    int maxEqualSum(int n1,int n2,int n3,vector<int> &s1,vector<int> &s2,vector<int> &s3){
        int sum1 = acc(s1);
        int sum2 = acc(s2);
        int sum3 = acc(s3);
        int i=0,j=0,k=0;
        while(i<n1 and j<n2 and k<n3){
            if(sum1 == sum2 and sum2==sum3){
                return sum1;
            }
            int maxy = max({sum1,sum2,sum3});
            if(sum1 == maxy){
                sum1-=s1[i];
                i++;
                
            }
            if(sum2 == maxy){
                sum2-=s2[j];
                j++;
            }
            if(sum3 == maxy){
                sum3-=s3[k];
                k++;
            }
            
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends