//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    bool happyNum(int N) {
        if (N == 1 || N == 7) {
            return true;
        }
        // false for 2,3,4,5,6,8,9
        if (N >= 2 && N <= 9) {
            return false;
        }
        int squareSum = 0;
        while (N) {
            int x = N % 10;
            squareSum += x*x;
            N/= 10;
        }
        
        return happyNum(squareSum);
    }
    int nextHappy(int N){
        // code here
        while(true) {
            N++;
            if (happyNum(N)) {
                return N;
            }
        }
        
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends