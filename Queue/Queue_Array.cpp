#include <iostream>
using namespace std;

class QueueArray
{
private:
    int firstIndex;
    int rearIndex;
    int Capacity;
    int *arr;

public:
    QueueArray(int value)
    {
        Capacity = value;
        arr = new int[Capacity];
        firstIndex = -1;
        rearIndex = -1;
    }

    void Enqueue(int value)
    {
        if (rearIndex == Capacity - 1)
        {
            cout << "Queue is Full" << endl;
            return;
        }
        if (firstIndex == -1)
        {
            firstIndex++;
        }
        rearIndex++;
        arr[rearIndex] = value;
    }

    void Dequeue()
    {
        if (firstIndex == -1)
        {
            cout << "Queue is Empty";
            return;
        }
        firstIndex++;
        if (firstIndex > rearIndex)
        {
            firstIndex = -1;
            rearIndex = -1;
        }
    }
    void peek()
    {
        if (firstIndex == -1)
        {
            cout << "Queue is Empty";
            return;
        }
        cout << "Front Element is : " << arr[firstIndex];
    }
    bool isEmpty()
    {
        if (firstIndex == -1)
        {
            return true;
        }
        return false;
    }
    bool isFull()
    {
        if (rearIndex == Capacity - 1)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    QueueArray q(5); // create a queue of capacity 5

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);

    q.peek(); // should print 10
    cout << endl;

    q.Dequeue(); // removes 10
    q.peek();    // should print 20
    cout << endl;

    q.Dequeue(); // removes 20
    q.Dequeue(); // removes 30

    if (q.isEmpty())
        cout << "Queue is empty" << endl;

    q.Enqueue(40);
    q.Enqueue(50);

    q.peek(); // should print 40
    cout << endl;

    if (q.isFull())
        cout << "Queue is full" << endl;
    else
        cout << "Queue is not full" << endl;

    return 0;
}