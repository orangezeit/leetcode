/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
public:
    // 0: left, 1: down, 2: right, 3: up
    //int dirs[4] = {'l', 'd', 'r', 'u'};
    set<pair<int, int>> visited;
    int dirs[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

    void dfs(Robot& robot, string& path, int& x, int& y) {
        //cout << x << " " << y << endl;
        visited.insert({x, y});
        robot.clean();

        for (int i = 0; i < 4; ++i) {
            robot.turnLeft();
            int d = ((path.empty() ? 3 : path.back() - '0') + i + 1) % 4;
            x += dirs[d][0];
            y += dirs[d][1];
            if (!visited.count({x, y}) && robot.move()) {
                path += d + '0';
                dfs(robot, path, x, y);
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
                path.pop_back();
            }
            x -= dirs[d][0];
            y -= dirs[d][1];
        }
    }

    void cleanRoom(Robot& robot) {
        string path;
        int x(0), y(0);

        dfs(robot, path, x, y);
    }
};
