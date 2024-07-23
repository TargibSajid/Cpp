#include <iostream>

using namespace std;

int main()
{
    int n ;

    cout << "Number of elements you want to  insert : ";

    cin >> n ;

    int arr[n];

    for(int i =  0 ; i < n ; i++)
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
    return 0;
}
