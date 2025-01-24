class Solution {
public:
    vector<int> findBitonicSubarray(vector<int> const &nums) {
        if (nums.empty()) {
            return {};
        }
        
        int min = nums[0];
        int max = nums[0];
        int count1 = 1;  // Start with 1 since single element is valid
        int len = nums.size();
        
        // Variables to track the longest sequence
        int maxLen = 1;
        int start = 0;
        int bestStart = 0, bestEnd = 0;
        bool isIncreasing = true;
        
        for (int i = 1; i < len; i++) {
            if (isIncreasing) {
                if (nums[i] > nums[i-1]) {
                    // Still increasing
                    count1++;
                }
                else if (nums[i] < nums[i-1]) {
                    // Start decreasing
                    isIncreasing = false;
                    count1++;
                }
                else { // Equal elements case
                    // Save current sequence if it's the longest
                    if (count1 > maxLen) {
                        maxLen = count1;
                        bestStart = start;
                        bestEnd = i - 1;
                    }
                    // Start new sequence from current position
                    start = i;
                    count1 = 1;
                }
            } 
            else { // In decreasing phase
                if (nums[i] < nums[i-1]) {
                    // Continue decreasing
                    count1++;
                }
                else if (nums[i] > nums[i-1]) {
                    // Save current sequence if it's the longest
                    if (count1 > maxLen) {
                        maxLen = count1;
                        bestStart = start;
                        bestEnd = i - 1;
                    }
                    // Start new sequence from previous position
                    start = i - 1;
                    count1 = 2;
                    isIncreasing = true;
                }
                else { // Equal elements case
                    // Save current sequence if it's the longest
                    if (count1 > maxLen) {
                        maxLen = count1;
                        bestStart = start;
                        bestEnd = i - 1;
                    }
                    // Start new sequence
                    start = i;
                    count1 = 1;
                    isIncreasing = true;
                }
            }
        }
        
        // Check final sequence
        if (count1 > maxLen) {
            maxLen = count1;
            bestStart = start;
            bestEnd = len - 1;
        }
        
        // Create result vector
        vector<int> result;
        for (int i = bestStart; i <= bestEnd; i++) {
            result.push_back(nums[i]);
        }
        
        return result;
    }
};