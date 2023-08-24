//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int>maxHeap; //left side numbers
    priority_queue<int,vector<int>,greater<int>>minHeap; //right side numbers
    
    void insertHeap(int &x)
    {
        if(maxHeap.size() ==0 or maxHeap.top()>=x ){
            maxHeap.push(x);
        }
        else{
            minHeap.push(x);
        }
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(maxHeap.size()>minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(maxHeap.size()<minHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(maxHeap.size() == minHeap.size()){
            //return maxHeap.top()/2.0 + minHeap.top()/2.0;
            return (maxHeap.top() + minHeap.top())/2.0;
        }
        else{
            return maxHeap.top();
        }
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends