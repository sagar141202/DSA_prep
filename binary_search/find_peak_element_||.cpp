class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int left = 0;
        int right = m - 1;

        while(left <= right)
        {
            int mid = left + (right - left) / 2;

            int maxRow = 0;
            for(int r = 1; r < n; r++)
            {
                if(mat[r][mid] > mat[maxRow][mid])
                {
                    maxRow = r;
                }
            }

            int curr = mat[maxRow][mid];
            int leftVal = (mid - 1 >= 0) ? mat[maxRow][mid - 1] : -1;
            int rightVal = (mid + 1 < m) ? mat[maxRow][mid + 1] : -1;

            if(curr > leftVal && curr > rightVal)
            {
                return {maxRow, mid};
            }

            else if(leftVal > curr)
            {
                right = mid - 1;
            }

            else
            {
                left = mid + 1;
            }
        }
        return {-1, -1};
    }
};