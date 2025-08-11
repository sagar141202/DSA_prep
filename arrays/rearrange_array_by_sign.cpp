class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos;
        vector<int> neg;

        for(int i = 0; i < n; i++)
        {
            if(nums[i] >= 0)
            {
                pos.push_back(nums[i]);
            }

            else
            {
                neg.push_back(nums[i]);
            }
        }
        vector<int> result;
        
        for(int i = 0; i < pos.size(); i++)
        {
            result.push_back(pos[i]);
            result.push_back(neg[i]);
        }

        return result;
        
    }
};