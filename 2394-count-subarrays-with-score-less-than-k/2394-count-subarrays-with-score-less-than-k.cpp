class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long cnt=0;
        long long total=0;
        for(int i=0,j=0;j<nums.size();j++){
            total+=nums[j];
            while(i<=j && total*(j-i+1)>=k){
                total-=nums[i];
                i++;
            }
            cnt+=j-i+1;
            
        }
        return cnt;

    }
};