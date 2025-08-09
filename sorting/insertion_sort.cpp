for(int i = 1; i < n; i++)
{
    int curr = arr[i];
    int j = i - 1;

    while(prev >= 0 && arr[prev] > curr)
    {
        arr[prev + 1] = arr[prev];
        prev--;
    }
    arr[prev + 1] = curr;
}