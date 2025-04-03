class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    std::deque<int> deq;
    std::vector<int> result;
    for (int i = 0; i < nums.size(); ++i) {
        // Remove indices that are out of the current window
        if (!deq.empty() && deq.front() == i - k) {
            deq.pop_front();
        }
        // Remove elements in deque that are less than the current element
        while (!deq.empty() && nums[deq.back()] < nums[i]) {
            deq.pop_back();
        }
        // Add current element to the deque
        deq.push_back(i);
        
        // The front of the deque is the largest element of the window
        if (i >= k - 1) {
            result.push_back(nums[deq.front()]);
        }
    }
    return result;

    }
};