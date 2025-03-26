
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        
         //dump all elements into set
        for(int num : nums){
            s.insert(num);
        }
        
        
        int ans = 0;
        for(int num : nums){
            //check if previous_element is in set
            if(s.find(num-1) == s.end()){
                int currentElement = num;
                int count = 1;
                
                //start a chain from current element
                while(s.find(currentElement+1) != s.end()){
                    currentElement++;
                    count++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};