class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        // A map from group size to the list of indices that
        unordered_map<int, vector<int>> sizeToGroup;
        for (int i = 0; i < groupSizes.size(); i++) {
            sizeToGroup[groupSizes[i]].push_back(i);
            
            // When the list size equals the group size, empty it and store it in the answer.
            if (sizeToGroup[groupSizes[i]].size() == groupSizes[i]) {
                ans.push_back(sizeToGroup[groupSizes[i]]);
                sizeToGroup[groupSizes[i]].clear();
            }
        }
        
        return ans;
    }
};