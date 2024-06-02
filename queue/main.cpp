#include <iostream>

using namespace std;
class Queue{
public:
    int queuee[5];
    int maxSize=5;
    int Front = -1;
    int rear=-1;


    bool isEmpty()
    {
        if(Front == -1 && rear == -1)
        {
            cout << "the queue is empty" << endl;

            return true;
        }
        else{

            return false;
        }
    }

    bool isFull(){

        if(Front == 0 && rear == 4)
        {
            cout << "the Queue is full " << endl;
            return true;
        }

        else {

            return false;
        }

    }

    void enqueue(int a)
    {
        if(isFull() == true)
        {
            cout << "the queue is full cant add any value " << endl;
        }

        else
        {
         if(isEmpty() == true)
         {
             Front = 0;
             rear = 0;

             queuee[rear] = a;

             rear++;



         }

         else if(isEmpty() == false)
         {

             queuee[rear] = a;

             if(rear != 4)
             {
                 rear++;
             }


         }




        }

    }

    void dequeue()
    {
        if(isEmpty() == true)
        {

            cout << " the queue is empty cant remove any item" << endl;
        }

        else{



                queuee[Front] = 0;
                if(Front <= rear && Front < 4)
                {

                    Front++;
                }

                else if(Front== 4 && rear == 4)
                {
                    Front = -1;

                    rear = -1;
                }

    }
    }

    void ShowQueue()
    {

        for(int i = 0 ; i < 5 ; i++)
        {
            cout << queuee[i] << " " ;


        }

        cout << endl;

    }

    int FrontElement()
    {
        cout << queuee[Front] << endl;

        return queuee[Front];

    }



};

int main()
{
    Queue q;

    q.isEmpty();

    q.isFull();
    q.enqueue(55);
    q.ShowQueue();
    q.enqueue(66);
    q.ShowQueue();
    q.dequeue();
    q.ShowQueue();
    q.enqueue(77);
    q.enqueue(88);
    q.enqueue(99);
    q.ShowQueue();
    q.dequeue();
    q.ShowQueue();
    q.FrontElement();
    q.dequeue();
    q.ShowQueue();
    q.dequeue();
    q.FrontElement();
    q.dequeue();
    q.ShowQueue();
    q.enqueue(10);
    q.ShowQueue();
    q.dequeue();
    q.ShowQueue();
    q.enqueue(20);
q.ShowQueue();





    return 0;
}
