class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        // Cells above main diagonal are cells where j > i
        // ie. columns that go from i+1 → n-1
        //Count = (n−1)−(i+1)+1 zeros at  end
        // count curr trailing zeros
         int n = grid.size();
        vector<int> trailing(n);
        
        // Step 1: Count trailing zeros
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0)
                    count++;
                else
                    break;
            }
            trailing[i] = count;
        }
        
        int swaps = 0;
         // Step 2: Fix rows one by one
        for (int i = 0; i < n; i++) {
            int required = n - i - 1;
            int j = i;
            
            // Find first row that satisfies requirement
            while (j < n && trailing[j] < required)
                j++;
            
            if (j == n)
                return -1;  // impossible
            
            // Bring row j to position i
            while (j > i) {
                swap(trailing[j], trailing[j - 1]);
                swaps++;
                j--;
            }
        }
        
        return swaps; 
        
    }
};