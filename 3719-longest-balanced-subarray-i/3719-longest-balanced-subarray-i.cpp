class Solution {
public:
    int longestBalanced(vector<int>& a) {
        int n=a.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            vector<bool>seen(100005,false);
            int even=0;
            int odd=0;
            for(int j=i;j<n;j++){
                if(seen[a[j]]==false){
                    seen[a[j]]=true;
                    if(a[j]%2==0) even++;
                    else odd++;
                }
                if(even==odd) maxi=max(maxi,j-i+1);
            }
        }
        return maxi;
    }
};