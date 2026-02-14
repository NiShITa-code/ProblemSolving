class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
          vector<double> row;
            row.push_back(poured);
            
            for (int r = 0; r < query_row; r++) {
                vector<double> next_row(r + 2, 0.0);
                
                for (int i = 0; i < row.size(); i++) {
                    double overflow = max(0.0, row[i] - 1.0);
                    next_row[i]     += overflow / 2.0;
                    next_row[i + 1] += overflow / 2.0;
                }
                
                row = next_row;
            }
            
            return min(1.0, row[query_glass]);
        
    }
};