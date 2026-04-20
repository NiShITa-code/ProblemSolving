class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int left = 0, right = colors.size() - 1;

        while (colors[left] == colors[colors.size() - 1]){
            left++;
        }

        while(colors[right] == colors[0]) {
            right--;
        }
        int n = colors.size();

        return max(n - left - 1, right);
    }
};