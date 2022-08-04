#include <iostream>
using namespace std;
int pivot(int arr[], int size)
{
    int firstsum = 0;
    for (int i = 1; i < size; i++)
    {
        firstsum += arr[i];
    }
    if (firstsum == 0)
    {
        return 0;
    }
    for (int i = 1; i <= size - 2; i++)
    {
        int prevsum = 0;
        for (int j = 0; j < i; j++)
        {
            prevsum += arr[j];
        }
        int aftersum = 0;
        for (int k = i + 1; k < size; k++)
        {
            aftersum += arr[k];
        }
        if (prevsum == aftersum)
        {
            return i;
        }
    }

    int lastsum = 0;
    for (int i = 0; i < size - 1; i++)
    {
        lastsum += arr[i];
    }

    if (lastsum == 0)
    {
        return size - 1;
    }
    else
    {
        return -1;
    }
}
// pivot element in sorted and rotated array
int getpivot(int arr[], int n)
{
    int l = 0;
    int h = n - 1;
    int mid = l + (h - l) / 2;
    while (l < h)
    {
        if (arr[mid] >= arr[0])
        {
            l = mid + 1;
        }
        else
        {
            h = mid;
        }
        mid = l + (h - l) / 2;
    }
    return l;
}
int binarySearch(int arr[], int l, int h, int x)
{
    if (h >= l)
    // if (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] < x)
        {
            return binarySearch(arr, mid + 1, h, x);
        }
        else
        {
            return binarySearch(arr, l, mid - 1, x);
        }
    }
    return -1;
}
int main()
{
    int arr[] = {2,1,3,4};
    int size = sizeof(arr) / sizeof(int);
    // int pivot=getpivot(arr,size);
    cout << pivot(arr, size)<<endl;
    cout << getpivot(arr, size);
    // cout << getpivot(arr, size)<<endl;
    // int a= binarySearch(arr,0,pivot-1,2);
    // int b= binarySearch(arr,pivot,size-1,2);
    // if(a==-1&&b==-1)
    // {
    //     // return -1;
    //     cout<<" -1";
    // }
    // else if(a!=-1)
    // {
    //     cout<<a;
    // }
    // else{
    //     cout<<b;
    // }
    return 0;
}