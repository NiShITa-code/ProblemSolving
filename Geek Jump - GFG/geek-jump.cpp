//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        int energyPrevTwo = 0;
        int energyPrev = 0;
        for (int i = 1; i < n; i++) {
            int energyOneJump = energyPrev + abs(height[i] - height[i - 1]);
            int energyTwoJump = INT_MAX;
            if (i > 1) {
                energyTwoJump = energyPrevTwo + abs(height[i] - height[i - 2]);
            }
            int curr = min (energyOneJump, energyTwoJump);
            energyPrevTwo = energyPrev;
            energyPrev = curr;
        }
        return energyPrev;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends