#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    void maxSubArrayWithIndices(vector<int>& nums) {
        int currentSum = nums[0];
        int maxSum = nums[0];

        int start = 0;       // start index of current subarray
        int end = 0;         // end index of max subarray
        int tempStart = 0;   // temporary start index when starting new subarray

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > currentSum + nums[i]) {
                // Start new subarray
                currentSum = nums[i];
                tempStart = i;
            } else {
                // Extend current subarray
                currentSum += nums[i];
            }

            // Update max sum and indices
            if (currentSum > maxSum) {
                maxSum = currentSum;
                start = tempStart;
                end = i;
            }
        }

        // Print results
        cout << "Maximum Sum: " << maxSum << endl;
        cout << "Subarray: ";
        for (int i = start; i <= end; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution().maxSubArrayWithIndices(nums);
    return 0;
}
