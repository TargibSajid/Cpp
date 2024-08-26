#include <iostream>

using namespace std;


struct Queue
{

    int number;

    Queue *next = nullptr;

    Queue *previous = nullptr;

};

bool isEmpty(Queue *Front)
{
    if(Front == nullptr)
    {
        return true;
    }
    else
    {
        return false;

    }

}


void FrontElement(Queue *Front)
{


    cout << Front->number << endl;


}

Queue* Enqueue(int value,Queue *Rear)
{



    if(Rear == nullptr)
    {
        Queue *newNode = new Queue();

        newNode->number = value;

        return newNode;







    }

    else
    {
        Queue *newNode = new Queue();



        newNode->number = value;



        newNode->previous = Rear;



        Rear->next = newNode;



        return newNode;


    }








}

Queue* Dequeue(Queue *Front)
{

    if(isEmpty(Front) != true)
    {
        cout << Front->number << endl;





        Front = Front->next;



        delete [] Front->previous;








        return Front;





    }

    else
    {
        cout << "Queue is Empty ...Nothing to Dequeue " << endl;

        return Front;
    }




    return Front;


}




void showAllElements(Queue *Front,Queue *Rear)
{

    if(isEmpty(Front) != true)
    {

        if(Front->previous != Rear)
        {
            showAllElements(Front,Rear->previous);

            cout << Rear->number << " ";
        }

        cout << endl;







    }









}









int main()
{

    Queue *Front = nullptr;

    Queue *Rear = nullptr;



    while(true)
    {
        cout << "=====================\n" << endl;
        cout << "1.Enqueue Element."<< endl;
        cout << "2.Dequeue Element." << endl;
        cout << "3.Show all Elements in the Queue" << endl;
        cout << "4.Show Front Element of the Queue" << endl;
        cout << "5.Is Queue Empty?" << endl;

        cout << "\n=====================" << endl;


        cout << "\nSelect Option : ";


        int option;

        cin >> option;

        if(option == 1)
        {
            cout << "Enter the value you want to Enqueue in Queue: ";

            int value;

            cin >> value;

            if(Front == nullptr && Rear == nullptr)
            {
                Front = Enqueue(value,Rear);

                Rear = Front;
            }

            else
            {
                Rear = Enqueue(value,Rear);
            }



        }

        else if(option == 2)
        {
            cout << " Dequeue Element is  : ";


            Front = Dequeue(Front);




        }

        else if(option == 3)
        {
            showAllElements(Front,Rear);
        }

        else if(option ==  4)
        {
            cout << "Front Element of the Queue: " ;

            FrontElement(Front);

        }

        else if (option == 5)
        {
            if(isEmpty(Front) == true)
            {
                cout << "The Queue is empty" << endl;

            }

            else
            {
                cout << "Queue is not empty" << endl;
            }
        }


        else

        {
            cout << "Invalid Option" << endl;
        }

    }







}


