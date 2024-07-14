#include <iostream>

using namespace std;

class DynamicStack
{
private :

        int *Dstack;

        int top = -1 ;

        int Size;



public:


    DynamicStack()
    {

    }

     DynamicStack(int Size)

    {
        int *Dstack = new int[Size];


        this->Dstack = Dstack;

        this->Size = Size;



    }


    int push(int value)
    {
        if(isFull() == true)
        {
            cout << "The stack is full...Can't push any other values ...!" <<endl;
        }

        else
        {

            Dstack[++top] = value;


        }


    }

    int pop()
    {
        if(isEmpty() == true)
        {
            cout << "Can't pop any items ..The Stack is Empty" << endl;
        }

        else
        {
            return Dstack[top--];
        }
    }

    bool isEmpty()
    {
        if(top == -1)
        {
            return true;
        }

        else
        {
            return false;
        }



    }

    bool isFull()
    {
        if(top == Size-1)
        {
            return true;
        }

        else
        {
            return false;
        }

    }

    void showStack()
    {

        cout << "ALL elements of the stack is : -" << endl;

        for(int i = top; i >=0 ; i--)
        {
            cout << Dstack[i] << endl;
        }




    }

};

int main()
{
    cout << "Enter the Size of the Stack : ";

    int  Size ;

    cin >> Size;


    DynamicStack Stack(Size);





    while(true)
    {

        cout << "\n=================\n" << endl;
        cout << "1.Push Element" << endl;
        cout << "\n2.Pop Element" << endl;
        cout <<"\n3.Show Elements" << endl;
        cout << "\n4.full?" << endl;
        cout << "\n5.Empty?? " << endl;
        cout << "\n=================\n" << endl;


        cout << "Enter an Option : " ;

        int op;

        cin >> op;

        if(op == 1)
        {
            cout << "Enter the element : " << endl;

            int a;

            cin>>a;

            Stack.push(a);
        }

        else if(op == 2)
        {

            cout << "Get Element " << Stack.pop() << endl;

        }

        else if(op == 3)
        {

            Stack.showStack();

        }

        else if(op == 4)
        {
            if(Stack.isFull() == true)
            {
                cout << "the Stack is full" << endl;
            }

            else {

                cout << "Stack not fulled yet !" << endl;
            }
        }

        else if(op == 5)
        {

            if(Stack.isEmpty() == true)
            {
                cout << "The stack is empty !" << endl;
            }

            else
            {
                cout << "The Stack is not Empty yet " << endl;
            }

        }

    }






    return 0;
}
