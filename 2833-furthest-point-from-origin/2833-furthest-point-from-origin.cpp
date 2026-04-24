class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int distFromOriginLeft = 0;
        int distFromOriginRight = 0;
        int maxDistFromOrigin = 0;
        for (char c: moves) {
            if (c == 'L') {
                distFromOriginLeft--;
                distFromOriginRight--;
            }
            if (c == 'R') {
                distFromOriginLeft++;
                distFromOriginRight++;
            }            
            if (c == '_') {
                distFromOriginLeft--;
                distFromOriginRight++;
            }
        }    
        return max(abs(distFromOriginLeft), abs(distFromOriginRight));
    }
};