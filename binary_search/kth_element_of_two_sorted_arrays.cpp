class Solution {
public:
    int kthElement(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        // Always binary search on the smaller array
        if(n1 > n2) 
            return kthElement(nums2, nums1, k);

        int low = max(0, k - n2);
        int high = min(k, n1);

        while(low <= high)
        {
            int cut1 = (low + high) / 2;
            int cut2 = k - cut1;

            int left1  = (cut1 == 0)  ? INT_MIN : nums1[cut1 - 1];
            int left2  = (cut2 == 0)  ? INT_MIN : nums2[cut2 - 1];

            int right1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
            int right2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

            if(left1 <= right2 && left2 <= right1)
            {
                // At a valid partition, the kth element is the max of left1 and left2
                return max(left1, left2);
            }
            else if(left1 > right2)
            {
                // we took too many elements from nums1
                high = cut1 - 1;
            }
            else
            {
                // we need to take more elements from nums1
                low = cut1 + 1;
            }
        }

        return -1; // not found (should never reach here)
    }
};
