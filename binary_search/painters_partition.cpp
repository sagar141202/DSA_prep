class Solution {
public:
    bool isPossible(vector<int>& boards, int A, long long maxLen){
        long long currSum = 0;
        int painters = 1;
        
        for(int i = 0; i < boards.size(); i++){
            if (boards[i] > maxLen)
                return false;                        // one board itself is too big
            if(currSum + boards[i] <= maxLen){
                currSum += boards[i];
            }
            else {
                painters++;
                if(painters > A) return false;
                currSum = boards[i];
            }
        }
        return true;
    }

    int paint(int A, int B, vector<int>& C) {
        long long low = 0, high = 0;
        for(int x : C){
            high += x;
            low = max(low, (long long)x);
        }
        
        const int mod = 10000003;
        long long ans = high;
        
        while(low <= high){
            long long mid = (low + high) / 2;
            
            if(isPossible(C, A, mid)){
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        ans = (ans % mod * (long long)B % mod) % mod;
        return (int)ans;
    }
};
