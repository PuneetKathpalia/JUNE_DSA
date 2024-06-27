class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        
        int sqrt;
        for (sqrt = 1; sqrt <= x / sqrt; sqrt++) {
        }
        
        return sqrt - 1;
    }
};