class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        using ll = long long;

        ll s = side;
        ll perimeter = 4 * s;

        vector<ll> pos;

        for (auto &p : points) {
            ll x = p[0], y = p[1];

            // Clockwise perimeter coordinate starting from (0, 0)
            if (y == 0) {
                // bottom edge: (0,0) -> (side,0)
                pos.push_back(x);
            } else if (x == s) {
                // right edge: (side,0) -> (side,side)
                pos.push_back(s + y);
            } else if (y == s) {
                // top edge: (side,side) -> (0,side)
                pos.push_back(3 * s - x);
            } else {
                // left edge: (0,side) -> (0,0)
                pos.push_back(4 * s - y);
            }
        }

        sort(pos.begin(), pos.end());

        int n = pos.size();

        vector<ll> doubled = pos;
        for (ll x : pos) {
            doubled.push_back(x + perimeter);
        }

        auto can = [&](ll d) -> bool {
            for (int start = 0; start < n; start++) {
                int idx = start;
                bool ok = true;

                for (int chosen = 1; chosen < k; chosen++) {
                    auto it = lower_bound(
                        doubled.begin() + idx + 1,
                        doubled.begin() + start + n,
                        doubled[idx] + d
                    );

                    if (it == doubled.begin() + start + n) {
                        ok = false;
                        break;
                    }

                    idx = it - doubled.begin();
                }

                if (ok && doubled[start] + perimeter - doubled[idx] >= d) {
                    return true;
                }
            }

            return false;
        };

        ll lo = 0, hi = side;

        while (lo < hi) {
            ll mid = (lo + hi + 1) / 2;

            if (can(mid)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }

        return (int)lo;
    }
};