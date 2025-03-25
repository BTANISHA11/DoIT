class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(),nums.end());
        for (int i = 1; i <= nums.size() + 1; ++i) {
        // Return the first integer not found in set
        if (numSet.find(i) == numSet.end()) {
            return i;
        }
    }
    return 1; // theoretically unreachable if the input is valid
}
};