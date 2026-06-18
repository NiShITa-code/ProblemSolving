class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle = double(30 * hour) -double(5.5 * minutes);
        return min(abs(angle), abs(360 - abs(angle)));
    }
};