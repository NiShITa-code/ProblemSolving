class Solution {
    public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<int> minDist(n, n);
        unordered_map<int, int> lastSeen;

        for (int i = 0; i < 2 * n; ++i) {
        int idx = i % n;
        int val = nums[idx];

        if (lastSeen.count(val)) {
            int last = lastSeen[val];      // position in doubled traversal
            int prevIdx = last % n;        // original array index
            int dist = i - last;           // actual distance in doubled traversal

            minDist[idx] = min(minDist[idx], dist);
            minDist[prevIdx] = min(minDist[prevIdx], dist);
        }

        lastSeen[val] = i;
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for (int q : queries) {
        ans.push_back(minDist[q] == n ? -1 : minDist[q]);
        }

        return ans;
    }
};