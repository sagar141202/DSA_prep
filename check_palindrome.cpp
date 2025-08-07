class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
        {
            return false;
        }

        if(x < 10)
        {
            return true;
        }

        if(x % 10 == 0)
        {
            return false;
        }

        int reversed = 0;
        int original = x;

        while(x != 0)
        {
            int digit = x % 10;
            x /= 10;
            if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && digit > 7)) {
                return false;
            }
            reversed = reversed * 10 + digit;
        }
        
        return reversed == original;
    }
};