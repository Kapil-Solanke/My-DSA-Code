#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int merge(int arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int count = 0;
    // static int count = 0;
    int *result = new int[high + 1];
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            result[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            result[k] = arr[j];
            count = count + mid-i;
            // count += mid - i;
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        result[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        result[k] = arr[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = result[i];
    }
    delete (result);
    return count;
}
int mergesort(int arr[], int low, int high)
{
    int mid;
    int count = 0;
    // static int count = 0;
    if (low < high)
    {
        mid = low + (high - low) / 2;
        count = mergesort(arr, low, mid);
        count += mergesort(arr, mid + 1, high);
        count += merge(arr, low, mid, high);
    }
    return count;
}
int main()
{
    int arr[] = {1, 20, 6, 4, 5};
    int size = sizeof(arr) / sizeof(int);
    int ans = mergesort(arr, 0, size - 1);
    cout << ans << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

/*
int arr[10] = {2, 34, 5};
    cout << arr << endl;
    cout << *arr << endl;
    cout << *arr + 1 << endl;
    cout << *(arr + 1) << endl;
    cout << arr[0] << endl;
    cout << &arr << endl;
    cout << &arr[0] << endl;
    cout << &arr[1] << endl;
    cout << &arr[0] + 1 << endl;
    cout << (arr[0] + 1) << endl;
    cout<<"Size of"<<endl;
    int *temp =arr;
    // int *address=&arr;
    int *address=&arr[0];
    cout<<temp<<endl;
    cout<<*temp<<endl;
    cout<<address<<endl;
    cout<<*address<<endl;
    cout<<sizeof(*address)<<endl;
    cout<<sizeof(*temp)<<endl;
    cout<<sizeof(&address)<<endl;
    cout<<sizeof(address)<<endl;
    cout<<sizeof(temp)<<endl;
    cout<<sizeof(&temp)<<endl;
    // cout<<sizeof(arr)<<endl;
    // cout<<sizeof(arr[0])<<endl;
    // cout<<sizeof(&arr[0])<<endl;
    // cout<<sizeof(&arr)<<endl;
    // cout<<sizeof(*arr)<<endl;
    // cout<<sizeof(*arr)<<endl;*/