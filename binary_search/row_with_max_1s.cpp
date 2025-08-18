#include <bits/stdc++.h>
using namespace std;

/*
Returns the index of the row with maximum number of 1s.
Assumes each row in matrix is sorted in non-decreasing order (all 0s then 1s).
If no 1 is present in the whole matrix, return -1.
*/
int rowWithMax1s(vector<vector<int>>& mat) {
    int n = mat.size();
    if(n == 0) return -1;
    int m = mat[0].size();

    int maxRow = -1;
    int maxOnes = 0;

    // Iterate each row
    for(int i = 0; i < n; i++) {
        // Binary search to find first 1
        int low = 0, high = m - 1;
        int first1Pos = m;  // default if no 1 in the row

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(mat[i][mid] == 1) {
                first1Pos = mid;
                high = mid - 1;  // search left half
            }
            else {
                low = mid + 1;   // search right half
            }
        }

        // number of 1s in this row
        int onesCount = (first1Pos == m ? 0 : m - first1Pos);

        if(onesCount > maxOnes) {
            maxOnes = onesCount;
            maxRow  = i;
        }
    }
    return maxRow;
}
