#include <iostream>
using namespace std;
class heap
{
public:
    int size;
    int arr[100];
    heap()
    {
        size = 0;
    }
    void insert(int d)
    {
        size++;
        arr[size] = d;
        int index = size;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[index] > arr[parent])
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
};
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right <= n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
void heapsort(int arr[], int size)
{
    // swap arr[1],arr[n]
    if (size < 1)
        return;
    swap(arr[1], arr[size]);
    // reduce size
    size--;
    // heapfy for root node
    heapify(arr, size, 1);
    heapsort(arr, size);
}
// void heapsort(int arr[],int n)
// {
//     int size=n;
//     while(size>1)
//     {
//         swap(arr[1], arr[size]);
//     // reduce size
//     size--;
//     // heapfy for root node
//     heapify(arr, size, 1);
//     }
// }
int main()
{
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int size=5;
    //heap creation
    for(int i=size/2;i>0;i--)
    {
        heapify(arr,size,i);
    }
    for (int i = 1; i <=size; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
    heapsort(arr,size); 
    for (int i = 1; i <=size; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
    return 0;
}