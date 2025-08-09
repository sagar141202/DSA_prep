for(int i = 0; i < n - 1; i++) 
{
    int smallestIndex = i;
    for(int j = i + 1; j < n; j++)
    {
        if(arr[j] > arr[smallestIndex])
        {
            smallestIndex = j;
        }
    }
    swap(arr[i], arr[smallestIndex]);
}