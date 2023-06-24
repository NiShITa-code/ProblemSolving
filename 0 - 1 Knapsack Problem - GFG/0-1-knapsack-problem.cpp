//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       // every item has two option pick or not pick
       // we have to make a weight w 
       // we have index of item
       // this maxVal stores maxval obtained at index i with weight w
       // we want to find maxVal[n][W];
       vector<vector<int>> maxVal(n, vector<int>(W + 1, 0));
       // if we have only 0 Th element 
       // steel if its weight grater then capacit and add its value
       for (int w = wt[0]; w <= W; w++) {
           if (wt[0] <= W) {
               maxVal[0][w] = val[0];
           }
       }
       for (int i = 1; i < n; i++) {
           //if i want to take this item its weigth should be less than capacity W
           // if we dont steel thsi item max value till now is same as max val tll i - 1
        for (int w = 0; w <= W; w++) {
           int dontSteel = maxVal[i - 1][w];
           int steel = INT_MIN;
           if (wt[i] <= w) {
               steel = maxVal[i - 1][w - wt[i]] + val[i];
           }
           maxVal[i][w] = max(steel, dontSteel);
        }   
       }
       return maxVal[n - 1][W];
       
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends