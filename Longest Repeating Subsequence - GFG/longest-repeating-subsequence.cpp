//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string s){
		    // Code here
		    int n = s.length();
		    // we do index shifting to prevent accessing -1 index
		    vector<int> prev(n + 1, 0);
		    vector<int> curr(n + 1, 0);
		    // base case when row goes out of bpund we return 0
		    for (int j = 0; j <= n; j++) {
		        prev[j] = 0;
		    }
		    
		    for (int i = 1; i <= n; i++) {
		        for (int j = 1; j <= n; j++) {
		            // index shifting
		            //i != j for longest repeating subsequence
		            if (s[i - 1] == s[j - 1] && i != j) {
		                curr[j] = prev[j - 1] + 1; 
		            } else {
		                curr[j] = max(prev[j], curr[j - 1]);
		            }
		        }
		        prev = curr;
		    }
		    return prev[n];
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends