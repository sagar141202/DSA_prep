class Solution {
public:
    bool canPlaceCows(vector<int>& nums, int k, int dist) {
        int count = 1;  
        int lastPos = nums[0]; 
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] - lastPos >= dist){
                count++;
                lastPos = nums[i];
            }
            if(count == k) return true;
        }
        return false;
    }

    int aggressiveCows(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int low = 0;
        int high = nums.back() - nums.front();
        int ans = 0;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(canPlaceCows(nums, k, mid)) {
                ans = mid;
                low = mid + 1;   // Try to maximize the distance
            } else {
                high = mid - 1;  // Try smaller distance
            }
        }
        return ans;
    }
};
