#include <iostream>

using namespace std;


string  encode(string s , int a)
{

    int Size = s.length();

    for(int i = 2 ; i < Size ; i=i+(a+1))
    {
        if(s[i] == ' ')
        {
            s[i] = ' ';
        }
        else if(s[i] != ' ')
        {
            s[i] = s[i]+2;
        }

    }

    return s;

}

int main()
{

    string s;
    int a ;


    cout << "enter the String you want to encrypt  : ";


    getline(cin,s);


    cout << "Input the sequence to change : " ;


    cin >> a ;


    cout << "converted string is : " << encode(s,a) << endl;







    return 0;
}
