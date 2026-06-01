class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        if (n == 1) {
            return cost[0];
        }

        int finalCost = 0;
        sort(cost.begin(), cost.end(), greater<int>());
        for (int i = 0; i < n; i++) {
            if (i % 3 != 2) {
                finalCost += cost[i];
            }
        }
        return finalCost;

    }
};