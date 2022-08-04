#include <iostream>
using namespace std;
#include <iostream>
using namespace std;
class cir_que
{
private:
    int f;
    int b;
    int size;
    int *arr;

public:
    cir_que(int n)
    {
        this->size = n;
        arr = new int[size];
        f = b = 0;
    }
    int isempty()
    {
        if (b == f)
        {
            return 1;
        }
        else
        {

            return 0;
        }
    }

    int isfull()
    {
        if (((b + 1) % size) == (f))
        {
            return 1;
        }
        else
        {

            return 0;
        }
    }
    void enque(int val)
    {
        if (isfull())
        {
            cout << "queue is full";
        }
        else
        {

            b = (b + 1) % size;
            arr[b] = val;
            cout << "enqued element is " << arr[b] << endl;
        }
    }
    int deque()
    {
        int a = -1;
        if (isempty())
        {
            cout << "queue is empty" << endl;
            return a;
        }
        else
        {
            f = (f + 1) % size;
            a = arr[f];
            return a;
        }
    }
};
// int isfull(cir_que *q)
// {
//     return ( (q->b + 1) % q->size == q->f);
// }
// int isempty(cir_que *q)
// {
//     return( q->f == q->b);
// }

int main()
{
    cir_que *q = new cir_que(4);
    cout<<q->isempty();
    return 0;
}