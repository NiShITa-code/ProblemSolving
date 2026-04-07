class Robot {
private:
    int w, h;
    int x, y;
    int dir; // 0=East, 1=North, 2=West, 3=South
    int perimeter;

    vector<string> dirNames = {"East", "North", "West", "South"};

public:
    Robot(int width, int height) {
        w = width;
        h = height;
        x = 0;
        y = 0;
        dir = 0; // East
        perimeter = 2 * (w + h) - 4;
    }

    void step(int num) {
        num %= perimeter;

        // If num is exactly a multiple of perimeter,
        // we still need to complete one full cycle to update direction correctly.
        if (num == 0) num = perimeter;

        while (num > 0) {
            int canMove = 0;

            if (dir == 0) { // East
                canMove = (w - 1) - x;
            } else if (dir == 1) { // North
                canMove = (h - 1) - y;
            } else if (dir == 2) { // West
                canMove = x;
            } else { // South
                canMove = y;
            }

            if (canMove == 0) {
                // Turn counterclockwise
                dir = (dir + 1) % 4;
                continue;
            }

            int move = min(num, canMove);

            if (dir == 0) x += move;      // East
            else if (dir == 1) y += move; // North
            else if (dir == 2) x -= move; // West
            else y -= move;               // South

            num -= move;
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        return dirNames[dir];
    }
};