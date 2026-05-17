class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        q.push(start);
    
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            // we got the ans
            if (arr[curr] == 0) {
                return true;
            }
            // alreday visited
            if (arr[curr] == -1) {
                continue;
            }
            if (curr - arr[curr] >= 0 && arr[curr - arr[curr]] != -1) {
                q.push(curr - arr[curr]);
            }
            if (curr + arr[curr] < n && arr[curr + arr[curr]] != -1) {
                q.push(curr + arr[curr]);
            }
            // mark visited
            arr[curr] = -1;

        }
        return false;
    }
};