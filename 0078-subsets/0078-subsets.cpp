class Solution {
public:
void backtrack(int start, vector<int>& nums, vector<int>& current, vector<vector<int>>& subsets) {
    // Add the current subset to the list of subsets.
    subsets.push_back(current);

    for (int i = start; i < nums.size(); ++i) {
        // Include nums[i] in the current subset.
        current.push_back(nums[i]);
        // Move on to the next element.
        backtrack(i + 1, nums, current, subsets);
        // Exclude nums[i] from the current subset and backtrack.
        current.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> subsets;
    vector<int> current;
    backtrack(0, nums, current, subsets);
    return subsets;

    }
};