#include <iostream>

using namespace std;

class Stack{
public:

    int stacK[7];

    int top = 0;

    int maxSize = 7;


    bool isFull()
    {

        if(top == 6)
        {
            return true;
        }

        else{
            return false;
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


    void push(int a)
    {
        if(isFull() == true)
        {
            cout << "cant add anymore elements bcz the stacck is full ";
        }

        else{
                stacK[top] = a;
                top++;


    }
    }

    void pop()
    {
        if(isEmpty() == true)
        {

            cout << "the stack is empty cant remove any elements" << endl;
        }

        else
        {

            stacK[top] = 0;
            top--;
        }

    }


    void show()
    {

        for(int i = 0 ; i < 7 ; i++)
        {

            cout << stacK[i] << " ";
        }
        cout << endl;
    }


    void topElement()
    {

        cout << stacK[top] << endl;
    }

};


int main()
{



    Stack s;


    cout << s.isEmpty();

    cout << "enter the elements :" ;

    int a ;

    for(int i = 0 ; i<7 ; i++)
    {


        cin>>a;

        s.push(a);


    }


    s.pop();

    s.show();

    cout << endl;
    s.topElement();
    s.pop();
    s.topElement();
    s.show();
    s.push(88);
    s.show();
    s.pop();
    s.show();
    s.pop();
    s.show();
    s.pop();
    s.show();
    s.pop();
    s.show();
    s.pop();
    s.show();
    s.pop();
    s.show();
    s.pop();
        s.show();
    s.pop();
        s.show();














    return 0;
}
