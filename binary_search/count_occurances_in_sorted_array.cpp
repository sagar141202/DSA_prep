class Solution {
public:
    int firstOccurrence(const vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                ans = mid;
                high = mid - 1; // search left side
            }
            else if (arr[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }

    int lastOccurrence(const vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                ans = mid;
                low = mid + 1; // search right side
            }
            else if (arr[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }

    int countOccurrences(const vector<int>& arr, int target) {
        int first = firstOccurrence(arr, target);
        if (first == -1) return 0; // target not found
        int last = lastOccurrence(arr, target);
        return last - first + 1;
    }
};
