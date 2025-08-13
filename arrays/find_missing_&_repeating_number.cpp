class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        long long n = nums.size();
        
        long long S = n * (n + 1) / 2;                  // expected sum
        long long S2 = n * (n + 1) * (2 * n + 1) / 6;    // expected sum of squares
        
        long long sum_nums = 0, sum_sq_nums = 0;
        for (long long x : nums) {
            sum_nums += x;
            sum_sq_nums += 1LL * x * x;
        }
        
        long long eq1 = sum_nums - S;                  // A - B
        long long eq2 = sum_sq_nums - S2;              // A^2 - B^2
        
        long long sumAB = eq2 / eq1;                   // A + B
        
        long long A = (eq1 + sumAB) / 2;
        long long B = A - eq1;
        
        return {(int)A, (int)B};
    }
};
