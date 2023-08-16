#include <iostream>
using namespace std;

template <typename T>
class Queue
{
private:
    int front;
    int rear;
    int size;
    int noOfElements;
    T* array;

    void resize(int s)
    {
        if (s == 0)
        {
            s++;
        }
        T* temp = new T[s * 2];
        for (int i = 0; i < noOfElements; i++)
        {
            temp[i] = array[(rear + i) % size]; // Copy elements with proper indexing
        }
        delete[] array;
        array = temp;
        size = s * 2;
        front = noOfElements;
        rear = 0;
    }

public:
    Queue()
    {
        front = 0;
        rear = 0;
        size = 1; // Start with a minimum size of 1
        noOfElements = 0;
        array = new T[size];
    }

    Queue(int s) : Queue()
    {
        size = s;
        delete[] array;
        array = new T[size];
    }

    bool isFull()
    {
        return noOfElements == size; // Use comparison operator instead of assignment
    }

    bool isEmpty()
    {
        return noOfElements == 0;
    }

    void enqueue(T element)
    {
        if (isFull())
        {
            resize(size);
        }
        array[front] = element;
        front = (front + 1) % size; // Circular increment
        noOfElements++;
    }

    T dequeue()
    {
        if (isEmpty())
        {
            exit(0);
        }
        T temp = array[rear];
        rear = (rear + 1) % size; // Circular increment
        noOfElements--;
        return temp;
    }

    ~Queue()
    {
        delete[] array;
    }
};
