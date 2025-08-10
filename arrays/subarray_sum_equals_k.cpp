#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) { // <-- match expected name
        unordered_map<long long, int> prefixIndex; // prefix sum -> first index
        long long sum = 0;
        int maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            // If subarray starts at index 0
            if (sum == k) {
                maxLen = i + 1;
            }

            // If sum - k seen before, we have a valid subarray
            if (prefixIndex.find(sum - k) != prefixIndex.end()) {
                maxLen = max(maxLen, i - prefixIndex[sum - k]);
            }

            // Store first occurrence of sum
            if (prefixIndex.find(sum) == prefixIndex.end()) {
                prefixIndex[sum] = i;
            }
        }
        return maxLen;
    }
};
