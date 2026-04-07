class Robot {
public:
    int w, h;
    int x = 0, y = 0;
    int d = 0; // 0=East, 1=North, 2=West, 3=South

    vector<string> dir = {"East", "North", "West", "South"};

    Robot(int width, int height) {
        w = width;
        h = height;
    }
    
    void step(int num) {
        int cycle = 2 * (w + h - 2);
        num %= cycle;
        if(num == 0) num = cycle;

        while(num--) {
            // try moving
            if(d == 0 && x + 1 < w) x++;            // East
            else if(d == 1 && y + 1 < h) y++;       // North
            else if(d == 2 && x - 1 >= 0) x--;      // West
            else if(d == 3 && y - 1 >= 0) y--;      // South
            else {
                d = (d + 1) % 4; // turn CCW
                num++; // retry this step
            }
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        return dir[d];
    }
};