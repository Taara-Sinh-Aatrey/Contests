class Solution {
public:
    int mySqrt(int x) {
        
        int low = 0, high = x;
        
        while (low <= high) {
            
            int mid = low + (high - low) / 2;
            
            // mid * mid <= x
            if (mid == 0 || mid <= x / mid) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
            
        }
        return high;
    }
};