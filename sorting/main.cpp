#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter the elemnets of array : " ;

    cin >> n;

    int arr[n] , k;

    cout << "Enter the input of this array : " << endl;


    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i];
    }



    cout << "for bubble sort " << endl;

    int l = n;

    for(int pass = 1 ; pass < n-1 ; pass++ )
    {
        for(int i = 0 ; i < l ; i++)
    {
        if(arr[i]>arr[i+1]){

                k = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = k;
        }

        else {

        }

    }

    --l;

    }



    for(int i = 0 ;  i < n ; i++ )
    {
        cout << arr[i]  << " " ;
    }


    return 0;
}
