private:
    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    unordered_set<double> os;
    vector<int> cs;
public:
    void move(int& x, int& y, int& step, int& maxDist, int& direct) {
        if (step == cs.size()) {
            return;
        }
        
        int command = cs[step];
        
        if (command == -1) {
            direct = (direct + 1) % 4;
        } else if (command == -2) {
            direct = (direct + 3) % 4;
        } else {
            for (int i = 1; i <= command; ++i) {
                if (os.find(x + d[direct][0] + (y + d[direct][1]) * 0.000001) == os.end()) {
                    x += d[direct][0];
                    y += d[direct][1];
                    maxDist = max(maxDist, x * x + y * y);
                } else {
                    break;
                }
            }
        }
        
        step++;
        move(x, y, step, maxDist, direct);
    }
    
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        cs = commands;
        for (int i = 0; i < obstacles.size(); ++i) {
            os.insert(obstacles[i][0] + obstacles[i][1] * 0.000001);
        }
        
        int x(0), y(0), step(0), maxDist(0), direct(0);
        move(x, y, step, maxDist, direct);
        
        return maxDist;
    }
