#include <iostream>
using namespace std;
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
int peak(int arr[], int size)
{
    int l = 0;
    int h = size - 1;
    int mid = l + (h - l) / 2;
    while (mid >= 1 && mid <= size - 2)
    {
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        else if (arr[mid - 1] > arr[mid])
        {
            mid--;
            // peak(arr, size);
        }
        else if (arr[mid] < arr[mid + 1])
        {
            mid++;
            // peak(arr, size);
        }
    }
    return -1;
}

int main()
{
    int arr[] = {9, 12, 15, 18, 2, 4};
    int n = sizeof(arr) / sizeof(int);
    // int size = sizeof(arr) / sizeof(int);
    int x = 5;
    // cout << size << endl;
    // // cout << binarySearch(arr, 0, size - 1, x) << endl;
    // cout<<peak(arr,size);
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    int pivot = s;
    cout << pivot;
    int a = -1;
    int b = -1;
    int l = 0;
    int h = pivot - 1;
    int k = 0;
    while (h >= l)
    // if (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (arr[mid] == k)
        {
            a = mid;
            break;
        }
        else if (arr[mid] < k)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    cout<<a;

    return 0;
}
