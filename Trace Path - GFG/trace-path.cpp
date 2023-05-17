//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        // code here
        int x = 0, y = 0;
        int minX = 0, maxX = 0, minY = 0, maxY = 0;
        for (auto i : s) {
            switch(i) {
                case 'L' : y--; break;
                case 'R' : y++; break;
                case 'U' : x++; break;
                case 'D' : x--; break;
            }
        
            minX = min(x, minX);
            maxX = max(x, maxX);
            minY = min(y, minY);
            maxY = max(y, maxY);
            
        }
        return (maxX - minX < n) && (maxY-minY < m);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends