class Solution {
public:
    struct Robot {
        int position;
        int health;
        char direction;
        int index;
    };

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<Robot> robots;

        for (int i = 0; i < n; i++) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }

        sort(robots.begin(), robots.end(), [](const Robot& a, const Robot& b) {
            return a.position < b.position;
        });

        stack<int> rightMoving; // stores indices in 'robots' vector

        for (int i = 0; i < n; i++) {
            if (robots[i].direction == 'R') {
                rightMoving.push(i);
            } else {
                // current robot is moving left
                while (!rightMoving.empty() && robots[i].health > 0) {
                    int j = rightMoving.top(); // nearest alive right-moving robot

                    if (robots[j].health < robots[i].health) {
                        // right robot dies, left robot loses 1 health
                        rightMoving.pop();
                        robots[i].health--;
                        robots[j].health = 0;
                    } 
                    else if (robots[j].health > robots[i].health) {
                        // left robot dies, right robot loses 1 health
                        robots[j].health--;
                        robots[i].health = 0;
                    } 
                    else {
                        // both die
                        rightMoving.pop();
                        robots[j].health = 0;
                        robots[i].health = 0;
                    }
                }
            }
        }

        vector<pair<int, int>> survivors; // {original index, health}

        for (auto& robot : robots) {
            if (robot.health > 0) {
                survivors.push_back({robot.index, robot.health});
            }
        }

        sort(survivors.begin(), survivors.end());

        vector<int> answer;
        for (auto& [idx, hp] : survivors) {
            answer.push_back(hp);
        }

        return answer;
    }
};