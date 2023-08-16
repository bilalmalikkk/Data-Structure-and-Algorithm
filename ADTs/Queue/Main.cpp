#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
    Queue<int> q(6);
    q.enqueue(40);
    cout << "Enqueue Done!" << endl;
    q.dequeue();
    cout << "Dequeue Done" << endl;
    q.enqueue(30);

    return 0;
}
