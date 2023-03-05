class Solution {
public:
    int passThePillow(int n, int time) {
        time %= ((n - 1) * 2);
        if (n - 1 < time) {
            time = (2 * n) - time - 1;
        }
        else {
            time++;
        }
        return time;
    }
};