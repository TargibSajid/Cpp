#include <iostream>

using namespace std;


struct DoubleLinklist
{

    int number;

    DoubleLinklist *next = nullptr;

    DoubleLinklist *previous = nullptr;

};


void TopElement(DoubleLinklist *top)
{


    cout << top->number << endl;


}

DoubleLinklist* Push(int value,DoubleLinklist *top)
{


        DoubleLinklist *newNode = new DoubleLinklist();


        newNode->number = value;


        newNode->previous = top;

        if(top != nullptr)
        {
            top->next = newNode;
        }





        cout << "Element Added Successfully...!" << endl;






    return newNode;



}

DoubleLinklist* Pop(DoubleLinklist *top)
{

    cout << top->number << endl;

    delete [] top;

    return top->previous;






}




void showAllElements(DoubleLinklist *top)
{

    if(top != nullptr)
    {
        showAllElements(top->previous);

        cout << top->number << endl;
    }









}


bool isEmpty(DoubleLinklist *top)
{
    if(top == nullptr)
    {
        return true;
    }
    else
    {
        return false;

    }

}






int main()
{

    DoubleLinklist *top = nullptr;



    while(true)
    {
        cout << "=====================\n" << endl;
        cout << "1.Push Elements."<< endl;
        cout << "2.Pop Elements." << endl;
        cout << "3.Show all Elements in the Stack" << endl;
        cout << "4.Show Top Element of the Stack" << endl;
        cout << "5.Is Stack Empty?" << endl;

        cout << "\n=====================" << endl;


        cout << "\nSelect Option : ";


        int option;

        cin >> option;

        if(option == 1)
        {
            cout << "Enter the value you want to push in stack: ";

            int value;

            cin >> value;

            top = Push(value,top);


        }

        else if(option == 2)
        {
            cout << " Popped Element is  : ";



            top = Pop(top);
        }

        else if(option == 3)
        {
            showAllElements(top);
        }

        else if(option ==  4)
        {
            cout << "Top Elements of the Stack: " ;

            TopElement(top);

        }

        else if (option == 5)
        {
            if(isEmpty(top) == true)
            {
                cout << "The Stack is empty" << endl;

            }

            else
            {
                cout << "Stack is not empty" << endl;
            }
        }


        else
        {
            cout << "Invalid Option" << endl;
        }

    }







}


