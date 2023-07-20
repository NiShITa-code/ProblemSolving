//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    unordered_map<int, int> mp;
    char nonrepeatingCharacter(string s)
    {
       //Your code here
       for (int i = 0; i < s.length(); i++) {
           if (mp.find(s[i]) == mp.end()) {
               // this came first time
               // if we have 0th index to distinguish it from 0 occourences we can do i + 1
               mp[s[i]] = i + 1;
           } else {
               mp[s[i]] = -2;
           }
       }
       int minIndex = INT_MAX;
       for (auto it: mp) {
           if (it.second > 0) {
               minIndex = min(minIndex, it.second);
           }
       }
       if (minIndex == INT_MAX) {
           return '$';
       } else {
           return s[minIndex - 1];
       }
    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends