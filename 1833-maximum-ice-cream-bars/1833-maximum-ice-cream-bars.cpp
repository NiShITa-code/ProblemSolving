class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxCost = *max_element(costs.begin(), costs.end());
        vector<int> count(maxCost + 1, 0);

        for (int c : costs) {
            count[c]++;
        }

        int ans = 0;

        for (int cost = 1; cost <= maxCost; cost++) {
            if (count[cost] == 0) continue;

            int canBuy = min(count[cost], coins / cost);

            ans += canBuy;
            coins -= canBuy * cost;

            if (coins < cost) continue;
        }

        return ans;
    }
};
    