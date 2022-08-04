#include <iostream>
#include <algorithm>
using namespace std;
void bubble_sort_1_iteration(int *arr, int n)
{
    if (n < 2)
        return;
    if (arr[0] > arr[1])
    {
        swap(arr[0], arr[1]);
    }
    bubble_sort_1_iteration(arr + 1, n - 1);
}
void bubble_sort(int *arr, int n)
{
    if (n < 2)
        // if(n==1||n==0)
        return;
    bubble_sort_1_iteration(arr, n);
    // Method 1
    //  for (int i = 0; i < n-1; i++)
    //  {
    //      if(arr[i]>arr[i+1])
    //      {
    //          swap(arr[i],arr[i+1]);
    //      }
    //  }
    // Method 2
    bubble_sort(arr, n - 1);
}
void selection_sort(int *arr, int n)
{
    if (n < 2)
        return;
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min =arr[i];
            swap(arr[i], arr[0]);
        }
    }
    selection_sort(arr + 1, n - 1);
}
void insertion_sort(int *arr,int n)
{
    if(n<2)
        return;
    insertion_sort(arr,n-1);
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            swap(arr[i],arr[i+1]);
        }
    }
}
void a(int n)
{
    if (n == 0)
        return;
    static int i = 0;
    static int j = 1;
    cout << i << " " << j << " ";
    i++;
    j++;
    a(n - 1);
}

int main()
{
    int arr[] = {0, 5, 3, 1, 2, 4};
    int size = sizeof(arr) / sizeof(int);
    // a(5);
    // bubble_sort(arr, size);
    // selection_sort(arr,size);
    insertion_sort(arr,size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}