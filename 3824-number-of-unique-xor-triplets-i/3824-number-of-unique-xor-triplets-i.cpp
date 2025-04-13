class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int cnt=1;
        int n=nums.size();
        if(n<=2)
        return n;
        while(cnt<=n)
        cnt<<=1;
        return cnt;
    }
};