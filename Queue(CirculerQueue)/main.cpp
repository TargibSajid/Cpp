#include <iostream>

using namespace std;


class CirculerQueue
{
private:

    int *Queue;

    int Size;

    int Front = -1;

    int Rear = -1;


public:


    CirculerQueue(int Size)
    {

        Queue = new int(Size);

        this->Size = Size;


    }


    void Enqueue(int value)
    {
        if(isFull() == true)
        {
            cout << "the Queue is full cant add any other elements" << endl;
        }

        else
        {
            if(isEmpty() == true)
            {

                Rear = (Rear+1)%Size;

                Queue[Rear] = value;

                Front  = (Front+1)%Size;

            }

            else {

                Rear = (Rear+1)%Size;

                Queue[Rear] = value;



            }

        }
    }

    int Dequeue()
    {
        if(isEmpty()== true)
        {
            cout << "Can't get Anymore Elements bcz the Queue is empty" << endl;

            return 0;

        }

        else
        {
                if(Front == Rear)
                {

                    int a = Queue[Front];

                    Front = -1;
                    Rear = -1;



                    return a;
                }

                else
                {


                       int a = Queue[Front];

                       Front = (Front+1)%Size;

                       return a;




                }






        }
    }

    void ShowElements()
    {
        if(isEmpty() == true)
        {
            cout << "Queue is Empty no elements to show " << endl;

        }

        else
        {
            int cursor = Front;

            cout << Queue[cursor] << " ";

                while(cursor != Rear)
                {

                    cursor = (cursor+1)%Size;

                    cout << Queue[cursor] << " ";




                }
                cout << endl;

        }



    }

    bool isFull()
    {
        if(Rear == Front-1)
        {
            return true;
        }

        else if(Front == 0 & Rear == Size-1)
        {
            return true;
        }

        else
        {

            return false;

        }
    }

    bool isEmpty()
    {
        if(Front == -1 && Rear == -1)
        {
            return true;
        }

        else {

            return false;
        }

    }

    void FrontElement()
    {

        cout << "Front element is : " << Queue[Front] << endl;


    }





};



int main()
{
  cout << "Enter the Size of the Dynamic Queue : ";

  int Size;

  cin >> Size;

  CirculerQueue Queue(Size);

    while(true)
    {




        cout << "\n=================\n" << endl;
        cout << "1.Add Element" << endl;
        cout << "\n2.Out Element" << endl;
        cout <<"\n3.Show Elements" << endl;
        cout << "\n4.full?" << endl;
        cout << "\n5.Empty?? " << endl;
        cout << "\n6.Front Element" << endl;
        cout << "\n=================\n" << endl;


        cout << "Enter an Option : " ;

        int op;

        cin >> op;

        if(op == 1)
        {
            cout << "Enter the element : " << endl;

            int a;

            cin>>a;

            Queue.Enqueue(a);
        }

        else if(op == 2)
        {

            cout << "Get Element " << Queue.Dequeue() << endl;

        }

        else if(op == 3)
        {

            Queue.ShowElements();

        }

        else if(op == 4)
        {
            if(Queue.isFull() == true)
            {
                cout << "the Queue is full" << endl;
            }

            else {

                cout << "Queue not fulled yet !" << endl;
            }
        }

        else if(op == 5)
        {

            if(Queue.isEmpty() == true)
            {
                cout << "The Queue is empty !" << endl;
            }

            else
            {
                cout << "The Queue is not Empty yet " << endl;
            }

        }

        else if(op == 6)
        {

            Queue.FrontElement();


        }


    }


    return 0;
}
