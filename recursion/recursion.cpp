#include <iostream>
using namespace std;
bool isSorted(int arr[], int n)
{
    if (n == 0 || n == 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    bool ans =isSorted(arr+1, n-1);
    // if (arr[n - 1] < arr[n - 2])
    // {
    //     return false;
    // }
    // bool ans =isSorted(arr, n - 1);
    return ans;
}
int getsum(int arr[],int size)
{
    if(size==0)
    {
        return 0;
    }
    int sum=arr[size-1];
    sum = sum+getsum(arr,size-1);
    return sum;
}
int main()
{
    int arr[] = {0, 5, 2, 3};
    int size = sizeof(arr) / sizeof(int);
    // cout<<isSorted(arr,size);
    cout<<getsum(arr,size);
    return 0;
}