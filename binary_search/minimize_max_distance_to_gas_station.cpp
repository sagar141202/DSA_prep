class Solution {
public:
    // helper function to count how many new stations are needed
    // if we want every gap to be at most 'dist'
    int countStations(vector<int> &arr, long double dist){
        int n = arr.size();
        int cnt = 0;
        for(int i = 1; i < n; i++){
            long double gap = (long double)arr[i] - (long double)arr[i-1];
            cnt += (int)(gap / dist);
        }
        return cnt;
    }

    long double minimiseMaxDistance(vector<int> &arr, int k) {
        long double low = 0.0;
        long double high = 0.0;
        
        // find the maximum initial gap
        for(int i = 1; i < arr.size(); i++){
            high = max(high, (long double)arr[i] - (long double)arr[i-1]);
        }
        
        // binary search with precision of 1e-6
        while(high - low > (long double)1e-6){
            long double mid = (low + high) / 2.0;
            int required = countStations(arr, mid);
            
            if(required <= k){
                // feasible, so try smaller distance
                high = mid;
            }
            else{
                // not feasible, we need a bigger max distance
                low = mid;
            }
        }
        
        return high; // or (low+high)/2
    }
};
