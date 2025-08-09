#include <iostream>

using namespace std;

void countSort(int* arr,int Size)
{

    int Count[]{0,0,0,0,0,0,0,0,0,0};

    for(int i = 0 ; i< Size; i++)
    {
        Count[arr[i]]++;


    }





    for(int i = 0 ; i < 9 ;i++)
    {
        Count[i+1] = Count[i] + Count[i+1];
    }





     int Sarr[Size];


    for (int i = 0; i < Size ; i++) {
        Count[arr[i]]--;
        Sarr[Count[arr[i]]] = arr[i];

    }

    cout << "Sorted array is " << endl;

    for(int i =0; i < Size ; i++)
    {

        cout << Sarr[i] << " ";

    }




}

int main()
{
    int Size;

    cout << "Enter the Size : ";


    cin >> Size ;

    int arr[Size];

    cout << "ENter the Input (input can't be greater than No 9 )";

    for(int i =0 ; i < Size ; i++)
    {

        cin >> arr[i];

    }

    countSort(arr,Size);





    return 0;
}
