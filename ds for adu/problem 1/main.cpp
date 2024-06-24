#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "=================================";

    cout << "\n       WELCOME TO LOGIN SYSTEM";

    cout << "\n=================================";


    cout << "\n 1.Create youur account. ";

    cout << "\n 2.Login.";

    cout << "\n 3.Delete Account.";

    cout << "\n 4.Exit.";

    int attempt = 0;


    string username[100] = {"sajid","sakib","Adrita"};

    string password[100] = {"XZ904", "HIiam" , "Froggo"};

    int Count = 3;



    while(attempt <= 3)
    {

        cout << "\nSelect an option : ";

        int option ;

        cin >> option;

        if(option  == 1 )
        {
            cout << "Enter user Name : ";

            string input ;

            getline(cin,input);

            username[Count] = input;

            cin.ignore();

            cout << "Set your Password: " ;

            getline(cin,input) ;

            password[Count] = input;


            Count++;
        }

        else if(option == 2)
        {
                int i;
                bool flag;

            cout << "Enter the UserName : ";



            string input;

            cin.ignore();

            getline(cin,input);


            for(i = 0 ; i < Count ; i++)
            {


                if(input == username[i])
                {
                    while(attempt <= 3)
                    {
                        cout << "Enter your Password: " ;

                    getline(cin,input);

                    if(input == password[i] )
                    {
                        cout << "Login Successfully " << endl;
                        flag = true;
                        break;
                    }

                    else
                    {
                        cout << "Wrong Password" << endl;
                        attempt++;
                    }
                    }




                }



            }


            if(flag == false)
            {
                cout << "Username Not found "<< endl;
            }



        }

        else if(option == 3)
        {
            cout << "Enter the Account name you wan to delete : ";

            cin.ignore();

            string input;

            getline(cin,input);

            for (int i = 0 ; i < Count ; i++)
            {
                if(input == username[i])
                {
                    string box = username[i];

                    username[i] = username[Count-1];

                    username[Count-1] = box;

                    Count--;

                    cout << "Account Deleted" << endl;

                    break;
                }
            }


        }


        else if(option == 4)
        {
            break;
        }

        else

        {
            cout << "\n Please Select the proper option" << endl ;
        }



    }



    return 0;
}
