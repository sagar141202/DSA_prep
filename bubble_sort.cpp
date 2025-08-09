bool isSwap;
int n = arr.size();

for(int i = 0; i < n - 1; i++) {
    isSwap = false;
    for(int j = 0; j < n - i - 1; j++) {
        if(arr[j] > arr[j + 1]) {
            swap(arr[j], arr[j + 1]);
            isSwap = true;
        }
    }
    // If no two elements were swapped by inner loop, then break
    if(!isSwap) {
        break;
    }
}