//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int> costOfStep(n, -1);
        // we are standing at first setp
        costOfStep[0] = 0;
        for (int step = 1; step < n; step++) {
            int minCost = INT_MAX;
            for (int jump = 1; jump <= k; jump++) {
                if (step - jump >= 0) {
                int jumpCost = abs(height[step] - height[step - jump]) + costOfStep[step - jump];
                minCost = min(minCost, jumpCost);
                }
            }
            costOfStep[step] = minCost;
        }
        return costOfStep[n - 1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends