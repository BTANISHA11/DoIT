class Solution {
public:
    int trap(vector<int>& height) {
       if (height.empty()) return 0;
        int n = height.size();
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int waterTrapped = 0;
        
        // Two-pointer traversal
        while (left < right) {
            if (height[left] < height[right]) {
                // Process the left side
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    waterTrapped += leftMax - height[left];
                }
                ++left;
            } else {
                // Process the right side
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    waterTrapped += rightMax - height[right];
                }
                --right;
            }
        }
        
        return waterTrapped;
    }
};