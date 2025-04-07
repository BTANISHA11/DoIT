class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       vector<int> merged;
    merged.reserve(nums1.size() + nums2.size());

    // Step 2: Using iterators to traverse both arrays
    auto it1 = nums1.begin();
    auto it2 = nums2.begin();

    // Step 3: Merging both arrays into one
    while (it1 != nums1.end() && it2 != nums2.end()) {
        if (*it1 < *it2) {
            merged.push_back(*it1);
            ++it1;
        } else {
            merged.push_back(*it2);
            ++it2;
        }
    }

    // Step 4: Append any remaining elements from nums1 or nums2
    while (it1 != nums1.end()) {
        merged.push_back(*it1);
        ++it1;
    }
    
    while (it2 != nums2.end()) {
        merged.push_back(*it2);
        ++it2;
    }

    // Step 5: Calculate the median from the merged array
    int n = merged.size();
    if (n % 2 == 1) {
        return merged[n / 2];
    } else {
        return (merged[(n - 1) / 2] + merged[n / 2]) / 2.0;
    }
};
};
