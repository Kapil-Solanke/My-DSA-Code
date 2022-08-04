#include <iostream>
#include <vector>

using namespace std;
// long long merge(int arr[], int low, int mid, int high)
// {
//     int i = low;
//     int j = mid + 1;
//     int k = low;
//     long long inv = 0;
//     // vector <int>result; not working
//     // int result[50];
//     int *result = new int[high + 1];
//     while (i <= mid && j <= high)
//     {
//         if (arr[i] < arr[j])
//         {
//             result[k] = arr[i];
//             i++;
//             k++;
//         }
//         else
//         {
//             result[k] = arr[j];
//             inv +=  mid - i;
//             j++;
//             k++;
//         }
//     }
//     while (i <= mid)
//     {
//         result[k] = arr[i];
//         i++;
//         k++;
//     }
//     while (j <= high)
//     {
//         result[k] = arr[j];
//         k++;
//         j++;
//     }
//     for (int i = low; i <= high; i++)
//     {
//         arr[i] = result[i];
//     }
//     delete (result);
//     return inv;
// }
// long long mergesort(int arr[], int low, int high)
// {
//     long long inv = 0;
//     if (low < high)
//     {
//         int mid = low + (high - low) / 2;
//         // mid = (low + high) / 2;
//         inv += mergesort(arr, low, mid);
//         inv += mergesort(arr, mid + 1, high);
//         inv += merge(arr, low, mid, high);
//     }
//     return inv;
// }
long long merge(int arr[], int l, int mid, int r)
{
    long long inv = 0;
    int n1 = mid - l + 1;
    int n2 = r - mid;
    // int a[n1];
    int *a = new int[n1];
    int *b = new int[n2];
    // int b[n2];
    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }

    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + i + 1];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
            inv += n1 - i;
            k++;
            j++;
        }
    }
    while (i < n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
    delete (a);
    delete (b);
    return inv;
}
long long mergeSort(int arr[], int l, int r)
{
    long long inv = 0;
    if (l < r)
    {
        int mid = (l + r) / 2;
        inv += mergeSort(arr, l, mid);
        inv += mergeSort(arr, mid + 1, r);
        inv += merge(arr, l, mid, r);
    }
    return inv;
}
int main()
{
    int arr[] = {8, 4, 2, 1};
    int size = sizeof(arr) / sizeof(int);
    cout << mergeSort(arr, 0, size - 1);
    // for (int i = 0; i < size; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    return 0;
}