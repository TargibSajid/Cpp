#include <iostream>

using namespace std;

int main()
{
   cout << "enter the elements number you want to insert :" ;

   int n ;

   cin >> n ;

   int arr[n];

   cout << "Enter the elements : " << endl;

   for(int i = 0 ; i < n ; i++)
   {
       cin >> arr[i];
   }

 cout << "enter the value you eant to search : " ;

 int value ;

 cin >> value ;

 bool b = false;
        for(int i = 0 ; i < n ; i++)
        {

            if(value == arr[i])
            {
                cout << "Found the value at index " << i <<  endl;
                 b = true;
                }





        }

        if(b == false)
        {
            cout << "Not found" << endl;
        }



    return 0;
}
