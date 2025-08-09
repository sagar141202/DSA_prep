#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> countFrequencies(vector<int>& nums) {
        unordered_map<int, int> freq;
        
        // Count frequency of each element
        for (int num : nums) {
            freq[num]++;
        }
        
        // Convert map to vector of pairs: [element, frequency]
        vector<vector<int>> result;
        for (auto& pair : freq) {
            result.push_back({pair.first, pair.second});
        }
        
        return result;
    }
};