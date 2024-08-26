#include <iostream>

using namespace std;

class Sajid
{
public :

        int *x ;

        int z ;


public :


        Sajid()
        {


             x = new int(10);


             z = 30;




        }


        ~Sajid()
        {

            delete x;

            cout << x << endl;

            cout << *x << endl;

        }



        void test(int y)
        {
            cout << " sajid " << *x + y << endl;

        }


};


class Student
{

private :

    int b ;

    Sajid sajid;


public :


        Student(int b , Sajid sajid )
        {
            this->b  = b  ;

            this-> sajid = sajid;

            cout << "Address " << &sajid << endl;


        }



        ~Student()
        {

            //delete  sajid.x;



        }



        void test(int y )
        {
            cout << *(sajid.x) + y << endl;

        }


};


int main()

{

    Sajid s;

    cout << &s <<  endl;

    s.test(10);

    s.test(10);

    Student student(50,s);

    student.test(10);

    s.test(10);



    return 0;
}
