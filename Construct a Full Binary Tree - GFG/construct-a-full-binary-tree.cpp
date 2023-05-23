//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends
/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the 
// new binary tree formed
class Solution{
    //Similar to construct a BT from inorder and preorder :
    //Use Recursion
  public:
  int preIndex =0;
  int sz ;
    Node* constructBinaryTree(int pre[], int preMirror[], int size)
    {
        // Code here
        sz = size;
        Node* root = build(pre,preMirror,0,size-1);
        return root;
        
    }
    Node* build(int pre[],int preM[],int l,int h){
        if(preIndex>=sz)return NULL;
        
        Node* root = new Node(pre[preIndex++]);
        if(l==h)return root;
        int i;
        for( i=l;i<=h;i++){
            if(pre[preIndex]==preM[i]){
                break;
            }
        }
        root->left = build(pre,preM,i,h);
        root->right = build(pre,preM,l+1,i-1);
        return root;
        
    }
};

//{ Driver Code Starts.

void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
	    for(int i=0; i<n; i++)cin>>preOrder[i];
	    for(int i=0; i<n; i++)cin>>preOrderMirror[i];
	    Solution obj;
	    printInorder(obj.constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
    }
	return 0;
}
// } Driver Code Ends