#include <iostream>

using namespace std;


struct StudentRecord{

    string uniqueId;

    int credits;

    float cgpa;


};

int main()
{

    StudentRecord s[10];

    for(int i = 0 ; i < 10 ; i++)
    {

        cout << "Enter vlaues for Student " <<i+1 << " : "  ;

	cout << "Enter ID : ";

        cin >> s[i].uniqueId;

        cout <<"Enter credits : ";

        cin >> s[i].credits;

        cout << "Enter cgpa : ";

        cin  >> s[i].cgpa;


    }

    cout << "printing the student id(More than cgpa 3.75) :";

    for(int i = 0 ; i < 10 ; i++)
    {
        if(s[i].cgpa > 3.75)
        {
          cout << s[i].uniqueId << " ";
        }


    }

    cout << endl;


    cout << "printing the student id(More than credits 50) :";

     for(int i = 0 ; i < 10 ; i++)
    {
        if(s[i].credits > 50)
        {
          cout << s[i].uniqueId << " ";
        }


    }

    return 0;
}
