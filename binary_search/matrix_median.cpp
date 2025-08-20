class Solution{
public:
    int findMedian(vector<vector<int>>&matrix) {
    int n = matrix.size();
        int m = matrix[0].size();

        int minVal = INT_MAX, maxVal = INT_MIN;

        // Find global min and max
        for (int i = 0; i < n; i++) {
            minVal = min(minVal, matrix[i][0]);     // first element of row
            maxVal = max(maxVal, matrix[i][m - 1]); // last element of row
        }

        int desired = (n * m + 1) / 2; // index of median (1-based)

        while (minVal < maxVal) {
            int mid = minVal + (maxVal - minVal) / 2;

            // Count numbers <= mid
            int count = 0;
            for (int i = 0; i < n; i++) {
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }

            if (count < desired) 
                minVal = mid + 1; // move right
            else 
                maxVal = mid;     // move left
        }

        return minVal;
    }
};