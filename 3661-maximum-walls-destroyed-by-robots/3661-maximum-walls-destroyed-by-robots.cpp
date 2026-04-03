class Solution {
public:
    using ll = long long;
    struct Robot {
        int position;
        int range;
    };

    int countWallsInRange(const vector<int>& walls, ll left, ll right) {
        if (left > right) return 0;

        auto start = lower_bound(walls.begin(), walls.end(), left);
        auto finish = upper_bound(walls.begin(), walls.end(), right);

        return (int)(finish - start);
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();

        vector<Robot> sortedRobots;
        for (int i = 0; i < n; i++) {
            sortedRobots.push_back({robots[i], distance[i]});
        }

        sort(sortedRobots.begin(), sortedRobots.end(),
             [](const Robot& a, const Robot& b) {
                 return a.position < b.position;
             });

        sort(walls.begin(), walls.end());

        vector<int> destroyIfShootLeft(n);
        vector<int> destroyIfShootRight(n);
        vector<int> overlapWithNext(max(0, n - 1), 0);

        // Step 1: compute walls destroyed by each robot if it shoots left or right
        for (int i = 0; i < n; i++) {
            ll pos = sortedRobots[i].position;
            ll range = sortedRobots[i].range;

            ll leftStart = pos - range;
            ll rightEnd = pos + range;

            if (i > 0) {
                leftStart = max(leftStart, (ll)sortedRobots[i - 1].position + 1);
            }

            if (i + 1 < n) {
                rightEnd = min(rightEnd, (ll)sortedRobots[i + 1].position - 1);
            }

            destroyIfShootLeft[i] = countWallsInRange(walls, leftStart, pos);
            destroyIfShootRight[i] = countWallsInRange(walls, pos, rightEnd);
        }

        // Step 2: compute overlap between robot i shooting right
        // and robot i+1 shooting left
        for (int i = 0; i + 1 < n; i++) {
            ll leftRobotPos = sortedRobots[i].position;
            ll leftRobotRange = sortedRobots[i].range;

            ll rightRobotPos = sortedRobots[i + 1].position;
            ll rightRobotRange = sortedRobots[i + 1].range;

            ll rightShotStart = leftRobotPos;
            ll rightShotEnd = min(leftRobotPos + leftRobotRange, rightRobotPos - 1LL);

            ll leftShotStart = max(rightRobotPos - rightRobotRange, leftRobotPos + 1LL);
            ll leftShotEnd = rightRobotPos;

            ll overlapLeft = max(rightShotStart, leftShotStart);
            ll overlapRight = min(rightShotEnd, leftShotEnd);

            overlapWithNext[i] = countWallsInRange(walls, overlapLeft, overlapRight);
        }

        // Step 3: DP
        vector<long long> dpLeft(n), dpRight(n);

        dpLeft[0] = destroyIfShootLeft[0];
        dpRight[0] = destroyIfShootRight[0];

        for (int i = 1; i < n; i++) {
            dpLeft[i] = destroyIfShootLeft[i] +
                        max(dpLeft[i - 1],
                            dpRight[i - 1] - overlapWithNext[i - 1]);

            dpRight[i] = destroyIfShootRight[i] +
                         max(dpLeft[i - 1], dpRight[i - 1]);
        }

        return (int)max(dpLeft[n - 1], dpRight[n - 1]);
    }
};