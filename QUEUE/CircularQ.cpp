#include <iostream>
using namespace std;
#define SIZE 5
class Queue
{
private:
    int items[SIZE], front, rear;

public:
    Queue()
    {
        front = rear = -1;
    }
    bool isFull()
    {
        if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
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
            cout << "OVERFLOW \n";
        else
        {
            if (front == -1)
                front = 0;
            rear = (rear + 1) % SIZE;
            items[rear] = ele;
            cout << "Inserted Elemet " << ele << endl;
        }
    }
    int deQueue()
    {
        int ele;
        if (isEmpty())
        {
            cout << "UNDERFLOW \n";
            return -1;
        }
        else
        {
            ele = items[front];
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front = (front + 1) % SIZE;
            }
            return ele;
        }
    }
    void display()
    {
        int i;
        if (isEmpty())
            cout << "\n Undeflow \n";
        else
        {
            cout << "\n FRONT = " << front;
            cout << "\n Items = ";
            if (front <= rear)
            {
                for (i = front; i <= rear; i++)
                    cout << items[i] << " ";
            }
            else
            {
                for (i = front; i <= rear + SIZE; i++)
                    cout << items[i % SIZE];
            }

            cout << "\n REAR = " << rear;
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
    int temp = q.deQueue();
    if (temp != -1)
        cout << "\n Deleted Element = " << temp;
    q.display();
    q.enQueue(7);
    q.enQueue(8);
    q.display();
    return 0;
}