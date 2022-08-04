#include <iostream>
using namespace std;
void sort012(int *arr, int n)
{
   //   Write your code here
	int low=0;
	int mid = n/2;
	int high= n-1;
	int * ans=new int[n];
    for(int i=0;i<n;i++)
	{
		ans[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		if(arr[i]==0){
			ans[low]=0;
			low++;
		}
		else if(arr[i]==1){
			ans[mid]=1;
			mid--;
		}
		else{
			ans[high]=2;
			high--;
		}
	}
	for(int i=0;i<n;i++)
	{
		arr[i]=ans[i];
	}
	free(ans);
    for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}	
	
}
void sortArr(int arr[], int n)
{
    int  a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++) {
        switch (arr[i]) {
        case 0:
            a++;
            break;
        case 1:
            b++;
            break;
        case 2:
            c++;
            break;
        }
    }
    int k = 0;
    while (a > 0) {
        arr[k++] = 0;
        a--;
    }

    while (b > 0) {
        arr[k++] = 1;
        b--;
    }
    while (c > 0) {
        arr[k++] = 2;
        c--;
    }

}
int main()
{
    int arr[] = {0,1,2,2,1};
    int size = sizeof(arr) / sizeof(int);
    sort012(arr,size);


    return 0;
}
// for (int i = 0; i < size-1; i=i+2)
// {
//     int temp =arr[i];
//     arr[i]=arr[i+1];
//     arr[i+1]=temp;
// }
// for (int i = 0; i < size; i++)
// {
//     cout<<arr[i]<<" ";
// }

// UNIQUE ELEMENT CODE IS WRONG
// for (int i = 0; i < size - 1; i++)
// {
//     for (int j = i; j < size; j++)
//     {
//         if (arr[i] > arr[j])
//         {
//             int temp = arr[i];
//             arr[i] = arr[j];
//             arr[j] = temp;
//         }
//     }
// }
// for (int i = 0; i < size; i++)
// {
//     cout << arr[i] << " ";
// }
// int count = 0;
// int prev = arr[0];
// for (int i = 1; i < size; i++)
// {
//     if (arr[i] == prev)
//     {
//         count++;
//     }
//     else
//     {
//         prev = arr[i];
//         count = 0;
//     }
//     if (count == 0)
//     {
//         cout << "the unique element is " << prev;
//         break;
//     }
//     if (i == size - 1 && count != 0)
//     {
//         cout << "the unique element is " << arr[size - 1];
//     }
// }