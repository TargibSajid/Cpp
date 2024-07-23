#include <iostream>

using namespace std;


 void  Partition(int *arr,int low , int high)
{

    int i = low;

    int j = high;

    int pivot = low;

    int pivot_item = arr[pivot];










    while(i <= j)
    {
        while(arr[i] <= pivot_item)
        {
            if(i!= high)
            {
                i++;
            }
            else
            {
                break;

            }


        }

        while( arr[j] >= pivot_item)
        {
            if(j != low)
            {
                j--;
            }

            else
            {
                break;
            }

        }


        if(i < j )
        {
            int k ;

            k = arr[i];

            arr[i] = arr[j];

            arr[j] = k;

        }
    }


    arr[pivot] = arr[j];

    arr[j] = pivot_item;

    pivot = j;







}

void quickSort(int *arr,int low , int high)
{





    if(low < high)
        {
            //int pivot = Partition(arr , low ,high );

            //quickSort(arr,low,pivot-1);

            //quickSort(arr, pivot+1 , high);


        }



}


int main()
{


    cout << "Enter the Size of the array you want to store" << endl;

    int Size;

    cin >> Size;


    int arr[Size];

    cout << "Enter the value of the array : " << endl;

    for(int i = 0 ; i< Size ; i++)
    {
        cin >> arr[i];
    }

    cout << "Array before sorting is : ";

    for(int i = 0 ; i < Size ; i++)
    {

        cout << arr[i] << " ";
    }

    cout << endl;

    Partition(arr,0,Size-1);

    cout << "Sorted arry is : " ;

    for(int i  = 0; i < Size ; i++ )
    {
        cout << arr[i] << " ";
    }




    return 0;
}
