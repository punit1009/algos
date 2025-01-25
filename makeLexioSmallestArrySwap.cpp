class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        // Create pairs of (value, index)
        vector<pair<long long, int>> pairs(n);
        for(int i = 0; i < n; i++) {
            pairs[i] = {nums[i], i};
        }
        
        // Sort pairs by value
        sort(pairs.begin(), pairs.end());
        
        // Find connected components
        vector<vector<int>> components;
        vector<int> current;
        
        for(int i = 0; i < n; i++) {
            if(current.empty() || pairs[i].first - pairs[i-1].first <= limit) {
                current.push_back(i);
            } else {
                components.push_back(current);
                current = {i};
            }
        }
        if(!current.empty()) {
            components.push_back(current);
        }
        
        // Process each component
        for(auto& comp : components) {
            vector<int> values, positions;
            for(int i : comp) {
                values.push_back(pairs[i].first);
                positions.push_back(pairs[i].second);
            }
            sort(positions.begin(), positions.end());
            
            // Put values back in sorted positions
            for(int i = 0; i < values.size(); i++) {
                nums[positions[i]] = values[i];
            }
        }
        
        return nums;
    }
};