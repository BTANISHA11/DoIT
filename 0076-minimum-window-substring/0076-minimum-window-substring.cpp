class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) return "";
        
        // Frequency maps for characters in t and current window
        unordered_map<char, int> tFreq, windowFreq;
        
        // Fill the t frequency map
        for (char c : t) tFreq[c]++;
        
        int start = 0, minLen = INT_MAX, count = 0;
        int left = 0;

        for (int right = 0; right < s.length(); ++right) {
            char c = s[right];
            // Increment the frequency of the current character in the window
            windowFreq[c]++;
            
            // Only increment the count if the window frequency for this character doesn't exceed the required frequency
            if (tFreq.count(c) && windowFreq[c] <= tFreq[c]) count++;
            
            // When all characters are matched, try to shrink the window
            while (count == t.length()) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                
                // Try to reduce the window size from the left
                char startChar = s[left];
                if (tFreq.count(startChar)) {
                    windowFreq[startChar]--;
                    if (windowFreq[startChar] < tFreq[startChar]) count--;
                }
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};