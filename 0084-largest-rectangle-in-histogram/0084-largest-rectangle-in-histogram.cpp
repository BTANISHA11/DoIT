class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
   
    stack<int> st;
    int maxArea = 0;
    int n = heights.size();

    for (int i = 0; i <= n; i++) {
        // Use a sentinel value to empty the stack at the end
        while (!st.empty() && (i == n || heights[st.top()] > heights[i])) {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1; // Calculate the width using the remaining indices in the stack
            maxArea = max(maxArea, height * width); // Update maxArea
        }
        st.push(i);
    }

    return maxArea;
}

};