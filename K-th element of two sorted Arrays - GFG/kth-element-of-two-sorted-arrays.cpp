//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        // divide into two parts left and right 
        // kth element as greatest ele of left part
        // now to decide how many ele t take from arr1
        // do binary search
        // take remaining ele from arr2
        // check if the left part formed is valid or not
        // do this by comparing greatest ele in left from arr1 with smallest ele in right from arr2
        // similiary greatest ele in left from arr2 should be smaller then smallest ele in irght from arr1
        // this ensures that all element is left are smaller than in right
        // if the left part is valid return the greatest ele of left side
        // no of ele in left side should be k
        // do binary search on smaller arr
        if (n > m) {
            return kthElement(arr2, arr1, m, n, k);
        }
        int leftSize = k;
        int low = max(0,k-m), high = min(k,n);
        while (low <= high) {
            int eleFrom1 = (low + high) >> 1;
            int eleFrom2 = leftSize - eleFrom1;
            int l1 = eleFrom1 == 0 ? INT_MIN : arr1[eleFrom1 - 1];
            int l2 = eleFrom2 == 0 ? INT_MIN : arr2[eleFrom2 - 1];
            int r1 = eleFrom1 == n ? INT_MAX : arr1[eleFrom1];
            int r2 = eleFrom2 == m ? INT_MAX : arr2[eleFrom2];
            if (l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            } else if (l1 > r2) {
                high = eleFrom1 - 1;
            } else {
                low = eleFrom1 + 1;
            }
        }
        return 1;
        
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends