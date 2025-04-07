class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
     // Ensure nums1 is the smaller array for reduced time complexity
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }

    int x = nums1.size();
    int y = nums2.size();
    int low = 0, high = x;

    while (low <= high) {
        // Step 1: Partition nums1 and nums2
        int partitionX = (low + high) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        // Step 2: Use infinity where partition is the end
        int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minX = (partitionX == x) ? INT_MAX : nums1[partitionX];

        int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minY = (partitionY == y) ? INT_MAX : nums2[partitionY];

        // Step 3: Check if we have found the correct partitions
        if (maxX <= minY && maxY <= minX) {
            // Step 4: Calculate median based on parity of total element count
            if ((x + y) % 2 == 0) {
                return (std::max(maxX, maxY) + std::min(minX, minY)) / 2.0;
            } else {
                return std::max(maxX, maxY);
            }
        }
        // Step 5: Binary search adjustment
        else if (maxX > minY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }

    throw std::invalid_argument("Input arrays are not valid");
}
};