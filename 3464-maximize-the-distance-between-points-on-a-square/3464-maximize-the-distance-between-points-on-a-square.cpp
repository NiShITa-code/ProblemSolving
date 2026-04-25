class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        using ll = long long;

        int n = points.size();
        ll perimeter = 4LL * side;

        vector<ll> position;

        for (auto &p : points) {
            ll x = p[0];
            ll y = p[1];

            // Convert each boundary point to its position while walking
            // clockwise around the square starting from (0, 0).
            if (y == 0) {
                // Bottom edge: (0,0) -> (side,0)
                position.push_back(x);
            } 
            else if (x == side) {
                // Right edge: (side,0) -> (side,side)
                position.push_back(side + y);
            } 
            else if (y == side) {
                // Top edge: (side,side) -> (0,side)
                position.push_back(3LL * side - x);
            } 
            else {
                // Left edge: (0,side) -> (0,0)
                position.push_back(4LL * side - y);
            }
        }

        sort(position.begin(), position.end());

        auto canChoose = [&](ll minimumGap) -> bool {
            vector<int> nextValid(n, n);

            /*
                nextValid[i] = first index j > i such that

                    position[j] - position[i] >= minimumGap

                So from point i, nextValid[i] tells us the next point
                we can choose while keeping distance at least minimumGap.
            */
            int right = 0;

            for (int i = 0; i < n; i++) {
                right = max(right, i + 1);

                while (right < n &&
                       position[right] - position[i] < minimumGap) {
                    right++;
                }

                nextValid[i] = right;
            }

            /*
                Try every point as the first selected point.

                From start, greedily jump to the next valid point.
                If we can select k points and the last point also keeps
                distance minimumGap from the first point circularly,
                then minimumGap is possible.
            */
            for (int start = 0; start < n; start++) {
                int current = start;
                int selected = 1;

                while (selected < k && current < n) {
                    current = nextValid[current];
                    selected++;
                }

                if (current == n) {
                    continue;
                }

                ll forwardDistance = position[current] - position[start];
                ll circularGapBack = perimeter - forwardDistance;

                if (circularGapBack >= minimumGap) {
                    return true;
                }
            }

            return false;
        };

        /*
            The answer cannot be more than perimeter / k,
            because k circular gaps must each be at least answer.

            k * answer <= perimeter
        */
        ll low = 1;
        ll high = perimeter / k;

        while (low < high) {
            ll mid = low + (high - low + 1) / 2;

            if (canChoose(mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};