//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        // Your code goes here
        int ones = 0;
        for(int i=0;i<n;i++){
            if(a[i] == 1){
                ones++;
            }
        }
        int sum =0;
        int max_sum = 0;
        //Kadanes algorithm
        //select the subarray with the maximum no of zeroes
        for(int i=0;i<n;i++){
            if(a[i] == 0){
                sum+=1;
                max_sum = max(sum,max_sum);
            }
            else{
                sum-=1;
            }
            if(sum<0)sum =0;
        }
        return ones + max_sum;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends