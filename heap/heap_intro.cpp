#include <iostream>
using namespace std;
class heap
{
public:
    int arr[100];
    int size;
    heap()
    {
        size = 0;
        arr[0];
    }
    // we insert at last then satisfy property of max or min heap

    void insert(int val)
    {
        size++;
        int index = size;
        arr[index] = val;
        // For MAX HEAP
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    // we delete root node only
    void deletion()
    {
        if (size == 0)
            cout << "heap is empty" << endl;

        // put last element in first element
        arr[1] = arr[size];

        // reduce size
        size--;
        int i = 1;
        while (i < size)
        {
            int left = 2 * 1;
            int right = 2 * i + 1;
            if (left < size && arr[i] < arr[left])
            {
                swap(arr[i], arr[left]);
                i = left;
            }
            if (right < size && arr[i] < arr[right])
            {
                swap(arr[i], arr[right]);
                i = right;
            }
            else
            {
                return;
            }
        }
    }
    void heapify(int arr[], int n, int i)
    {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;
        
        if (left <= n && arr[left] < arr[largest])
        {
            largest = left;
        }
        if (right <= n && arr[right] < arr[largest])
        {
            largest = right;
        }
        if (largest != i)
        {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
    }
};
int main()
{
    heap h;
    h.insert(50);
    // h.print();

    h.insert(55);
    h.insert(52);
    h.insert(53);
    h.insert(54);
    h.print();
    cout << endl;
    h.deletion();
    h.print();

    return 0;
}
// for 0 based indexing 
// int left = 2 * i+1;
// int right = 2 * i + 2;