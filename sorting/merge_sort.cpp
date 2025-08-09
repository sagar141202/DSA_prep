void merge(vector<int> &arr, int start, int mid, int end)
{
    vector<int> temp;
    int i = start;
    int j = mid + 1;

    while(i <= mid && j <= end)
    {
        if(arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }

        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for(int k = 0; i < temp.size(); k++)
    {
        arr[start + k] = temp[k];
    }
}

void mergeSort(vector<int> &arr, int start, int end) 
{
    int mid = start + (end - start)/2;
    if (start >= end) {
        return;
    }
    
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    merge(arr, start, mid, end);
}