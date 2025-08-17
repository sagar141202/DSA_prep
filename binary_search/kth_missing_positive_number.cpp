class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int missing = arr[mid] - (mid + 1);

        // If missing values up to mid < k, move right
        if (missing < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // After the loop, 'left' is the smallest index such that
    // #missing >= k
    // The kth missing number is:  k + left
    return k + left;
    }
};