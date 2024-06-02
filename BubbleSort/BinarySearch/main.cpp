#include <iostream>

using namespace std;

int main()
{

    int n ;

    cout << "Enter the elemnets number you want to insert : " ;

    cin >> n;

    cout << "Enter the elements :" ;

    int arr[n];

    for(int i  = 0 ; i < n ; i++)
    {
        cin >> arr[i];

    }

    int pass ;

    int N = n;

    int k;



    for(pass = 0 ; pass < n-1 ; pass++)
    {
        for(int i = 0 ; i < N-1; i++  )
        {


            if(arr[i] > arr[i+1])
            {
                k = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = k;
            }


        }

        --N;
    }

    cout << "Sorted array is : " << endl;

    for(int i = 0 ; i < n ; i ++  )
    {

        cout << arr[i] << " ";

    }


    cout << endl;


    int value ;

    cout << "Enter the number you want to search :" ;

    cin >> value ;

    int first = 0 ;

    int last = n-1;

    int middle = 0 ;


 while(true)
 {
     middle = (first+last)/2;


    if(first > last )
    {
        cout << "Not found" << endl;
        break;
    }
     else if(arr[middle] == value )
     {
         cout << "Found at index :" <<middle<< endl;
         break;
     }

     else if(arr[middle] < value )
     {
         first = middle+1;
     }

     else if(arr[middle] > value )
     {
         last = middle -1;
     }



 }


    return 0;
}
