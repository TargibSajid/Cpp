#include <iostream>

using namespace std;

void Merge(int *ptr , int low , int high , int middle )
{

    int i = low ;

    int j = middle+1;

    int k = 0;

    int Size = (high-low)+1;

    int arr[Size];

    while( i <= middle && j <= high )
    {
        if(ptr[i] < ptr[j])
        {
            arr[k++] = ptr[i++];

        }

        else
        {
            arr[k++] = ptr[j++];

        }
    }
    while( i <= middle)
    {
        arr[k++] = ptr[i++];
    }


    while(j <= high)
    {
        arr[k++] = ptr[j++];
    }

    for(int l = low ; l <=high ; l++)
    {

        ptr[l] = arr[l-low];

    }




}
int* MergeSort(int *ptr, int low , int high)
{
int middle = (low+high)/2;;

    if(low < high)
    {

        MergeSort(ptr, low, middle);

        MergeSort(ptr , middle+1 , high);

        Merge(ptr, low , high , middle);

    }





    return ptr;


}







int main()
{
    int Size ;

    cin >> Size;

    int arr[Size];

    cout << "Enter the array values : " ;

    for(int i = 0 ;i < Size ; i++)
    {
        cin >> arr[i];

    }

    cout << "Entered array is : " ;

    for(int i = 0 ; i < Size ; i++)
    {
        cout << arr[i] << " " ;
    }

    cout << endl;

    int low = 0;

    int high = Size-1;

   int *ptr = MergeSort(arr,low,high);


    cout << "sorted array is : ";



    for(int i = 0 ; i < Size ; i++)
    {
        cout << ptr[i] << " " ;

    }















    return 0;
}
