//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        // code here
        vector<int>freq(26);
        for (int i = 0; i < N; i++) {
            freq[tasks[i] - 'A']++;
        }
        sort(freq.begin(),freq.end(),greater<int>());//descending order
        
        int idleTime = (freq[0] - 1) * K;
        
        for (int i =1; i <freq.size(); i++) {
            idleTime -= min(freq[0] - 1, freq[i]);
        }
        
        return tasks.size() + max(0, idleTime);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends