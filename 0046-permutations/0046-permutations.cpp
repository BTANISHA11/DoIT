class Solution {
public:
// void backtrack(vector<int>& nums,vector<vector<int>>& res,int start){
//     if(start==nums.size()){
//     res.push_back(nums);
//     return ;
//     }
//     for(int i=start;i<nums.size();i++){
//         swap(nums[start],nums[i]);
//         backtrack(nums,res,start+1);
//         swap(nums[start],nums[i]);
//     }

// }
    vector<vector<int>> permute(vector<int>& nums) {
        // vector<vector<int>> res;
        // backtrack(nums,res,0);
        // return res;
         vector<vector<int>> result;
        // Sort the numbers to start with the smallest lexicographical permutation
        sort(nums.begin(), nums.end());
        do {
            // Add the current permutation to the list
            result.push_back(nums);
            // Generate the next permutation
        } while(next_permutation(nums.begin(), nums.end()));
        return result;
    }
};