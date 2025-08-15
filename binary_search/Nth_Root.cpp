class Solution {
public:
  long long power(int base, int exp, int limit)
  {
    long long result = 1;

    for(int i = 0; i < exp; i++)
    {
      result *= base;

      if(result > limit) return result;
    }
    return result;
  }

  int NthRoot(int N, int M) {
      int low = 1;
      int high = M;

      while(low <= high)
      {
        int mid = low + (high - low) / 2;
        long long midPow = power(mid, N, M);

        if(midPow == M) return mid;
        else if(midPow < M) low = mid + 1;
        else high = mid - 1;
      }
      return -1;
    }
};
