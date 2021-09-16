#include <iostream>
#define SIZE 5
using namespace std;
class Queue
{
private:
    int items[SIZE], front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    bool isFull()
    {
        if (front == 0 & rear == -1)
            return true;
        else
            return false;
    }
    bool isEmpty()
    {
        if (front == -1)
            return true;
        else
            return false;
    }
    void enQueue(int ele)
    {
        if (isFull())
            cout << "QUEUE IS FULL \n";
        else
        {
            if (front == -1)
                front = 0;
            items[++rear] = ele;
            cout << "INSERTED " << ele << endl;
        }
    }
    int deQueue()
    {
        int ele;
        if (isEmpty())
        {
            cout << "QUEUE IS EMPTY \n";
            return -1;
        }
        else
        {
            ele = items[front--];
            rear--;
            if (front >= rear)
                front = rear = -1;
            else
                front++;
            cout << "DELETED " << ele << endl;
            return ele;
        }
    }
    void display()
    {
        if (isEmpty())
            cout << "EMPTY QUEUE \n";
        else
        {
            cout << "Front Index  " << front << endl
                 << "Items ==> ";
            for (int i = front; i <= rear; i++)
                cout << items[i] << " ";
            cout << endl
                 << "Rear Index " << rear << endl;
        }
    }
};
int main()
{
    Queue q;
    q.deQueue();
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    q.enQueue(6);
    q.display();
    q.deQueue();
    q.display();
    return 0;
}