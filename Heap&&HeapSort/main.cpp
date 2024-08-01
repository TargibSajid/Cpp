#include <iostream>

using namespace std;

struct Heap
{
    int number;

    Heap *leftChild = nullptr;

    Heap *rightChild = nullptr;

    Heap *nextIndex = nullptr;

};


Heap *Front = nullptr;

Heap *Rear = nullptr;








Heap* findParent(Heap *root , Heap *node )
{
    if((root->leftChild)->number == node->number || (root->rightChild)->number == node->number)
    {
        return root;
    }

    else
    {
        findParent(root->nextIndex,node);
    }
}

Heap *findLast(Heap*root)
{
    if(((root->nextIndex)->nextIndex) == nullptr)
    {

        return root;

    }

    else
    {
        findLast(root->nextIndex);
    }

}

Heap* findvalue(Heap *root,int value)
{
    if(root != nullptr )
        {

    if(value != root->number)
    {

            findvalue(root->nextIndex,value);
    }

    else
    {


        return root;


    }

        }

        else
        {
            cout << "value Not found " << endl;

            return nullptr;
        }


}

bool MaxHeapify(Heap *root,bool flag )
{

    if(flag == false)
    {
       if((root->leftChild)->number >root->number || (root->rightChild)->number > root->number )
    {
        int k;


        if((root->leftChild)->number >root->number && (root->rightChild)->number > root->number)
        {
            if((root->leftChild)->number > (root->rightChild)->number )
            {

                k = root->number;

                root->number = (root->leftChild)->number;

                (root->leftChild)->number = k;

                return flag;


            }
            else
            {
                k = root->number;

            root->number = (root->rightChild)->number;

            (root->rightChild)->number = k;

            return flag;


            }
        }

        else if((root->leftChild)->number > root->number)
        {
            k = root->number;

            root->number = (root->leftChild)->number;

            (root->leftChild)->number = k;

            return flag;


        }

        else if((root->rightChild)->number > root->number)
        {
            k = root->number;

            root->number = (root->rightChild)->number;

            (root->rightChild)->number = k;

            return flag;


        }


}

    else
    {


        return true;
    }
    }

}

void Heapify(Heap *root,bool flag)
{

    if(root != nullptr)
    {
        if(root->leftChild != nullptr || root->rightChild  != nullptr )
    {

        Heapify(root->leftChild,flag);

        Heapify(root->rightChild,flag);

        flag = MaxHeapify(root,flag);


         if (flag == false)
    {
        Heapify(root,flag);
    }
    }





    }




}






Heap* insertingElement(Heap *root,int value)
{
     Heap *newNode = new Heap();

     newNode->number = value;




    if(root != nullptr)
    {


        if(Front->rightChild == nullptr)
        {
            if(Front->leftChild == nullptr)
            {
                Front->leftChild = newNode;

                Rear->nextIndex = Front->leftChild;

                Rear = Rear->nextIndex;




                return root;
            }

            else
            {
                Front->rightChild = newNode;

                Rear->nextIndex = Front->rightChild;

                Rear = Rear->nextIndex;


                Front = Front->nextIndex;



                return root;
            }
        }

        else
        {
            cout << "Passing value Twice in One Index is Not Allowed";;
        }

    }

    else
    {
        root = newNode;



        return root;
    }


    return root;

}


Heap * deleteWholeHeap(Heap *root)
{

     while(root != nullptr)
        {
            Heap *node = root;

            root = root->nextIndex;

            delete node;

            node = nullptr;

        }

         cout << "All node deleted Succesfully " << endl;


        return nullptr;

}


Heap* deleteElement(Heap *root, int value)
{



        Heap *node =  findvalue(root,value);





        if( node != nullptr)
        {

            Heap *Index = findLast(root);

            Heap *PIndex = findParent(root,Index->nextIndex);

            if(root == node)
            {
                 Heap * LastIndex = Index->nextIndex;

                 root->number = LastIndex->number;




                 delete LastIndex;

                 Index->nextIndex = nullptr;

                 if(PIndex->rightChild == LastIndex )
                 {
                     PIndex->rightChild = nullptr;
                 }

                 else if(PIndex->leftChild == LastIndex)
                 {
                     PIndex->leftChild = nullptr;
                 }


                return root;










            }

            else
            {
                Heap *LastIndex = Index->nextIndex;

                node->number = LastIndex->number;

                delete LastIndex ;

                Index->nextIndex =  nullptr;

                 if(PIndex->rightChild == LastIndex )
                 {
                     PIndex->rightChild = nullptr;
                 }

                 else if(PIndex->leftChild == LastIndex)
                 {
                     PIndex->leftChild = nullptr;
                 }







                return root;













            }


        }

        else
        {
            cout << "value not found ... Miss Match !!" << endl;

        }





}

void Traversal(Heap *root)
{


    if(root->leftChild!= nullptr)
    {
         Traversal(root->leftChild);
    }


    cout << root ->number << " ";


    if(root->rightChild != nullptr)
    {
         Traversal(root->rightChild);
    }









}

void showNodes(Heap *root)
{


   if(root != nullptr)
   {

       cout << root->number << " " ;

       if(root->nextIndex != nullptr)
   {
       showNodes(root->nextIndex);

   }

   else
   {
       cout << endl;
   }
   }

   else
   {
       cout << "Heap is empty ...No elements to show" << endl;
   }


}


void HeapSort(int *arr , int Size)
{
    Front = nullptr;

    Rear = nullptr;

    Heap *root = nullptr;

    int k = 0;

    while(k < Size)
    {
        if(root == nullptr)
                        {
                                root = insertingElement(root,arr[k++]);

                                Front = root;

                                Rear = root;
                        }

                    else
                        {

                                root= insertingElement(root,arr[k++]);

                        }
    }

    cout << "All Elements Inserted Succesfully......." << endl;


    Heapify(root,false);

    int b = Size-1;

    int l = 0;

    while(b >= 0)
    {

        Heap*Index = findLast(root);

        Heap *LastIndex = Index->nextIndex;

        l = LastIndex->number;

        LastIndex->number = root->number;

        root->number = l;

        arr[b--] = LastIndex->number;

        Index->nextIndex = nullptr;

        deleteElement(root,LastIndex->number);

        Heapify(root,false);






    }

    cout << "Heap Sorted Succesfully......" << endl;








}



int main()
{
    Heap *root = nullptr;

        while(true)
    {
        cout << "\n===================================\n" <<  endl;
        cout << "\n1.Insert value in Heap" << endl;
        cout << "\n2.Max Heapify the Heap" << endl;
        cout << "\n3.HeapSort An Array" << endl;
        cout << "\n4.Delete element from the Heap" << endl;
        cout << "\n5.Traverse the The Heap tree (inorder)" << endl;
        cout << "\n6.Show the Nodes of the Tree by index  " << endl;
        cout << "\n===================================\n" <<  endl;

        int option;

        cout << "Select an Option : " << endl;

        cin >> option;

        if(option == 1)
        {
                    cout << "Enter the Value You want to Insert : ";

                    int value;

                    cin  >> value;

                    if(root == nullptr)
                        {
                                root = insertingElement(root,value);

                                Front = root;

                                Rear = root;
                        }

                    else
                        {

                                root= insertingElement(root,value);

                        }
        }

        else if(option == 2)
        {
            Heapify(root,false);
        }

        else if(option == 3)
        {

            cout << "Enter the Size of the Array you want to Sort : ";

            int Size ;

            cin >> Size;

            int arr[Size];


            cout << "Enter the inputing Elements : " << endl;



            for(int i = 0 ; i < Size ; i++)
            {
                cin >> arr[i] ;
            }

            cout << "Your entered array is : " << endl;

            for (int i = 0 ; i < Size ; i++)
            {
                cout << arr[i] << " ";
            }

            cout << endl;


            HeapSort(arr,Size);


            cout << "Sorted array is : " << endl;

             for (int i = 0 ; i < Size ; i++)
            {
                cout << arr[i] << " ";
            }

            cout << endl;





        }

        else if(option == 4)
        {
            cout << "\t1.Delete the Whole Heap\n" << endl;

            cout << "\t2.Delete an Element\n" << endl;

            cout  << "\n Select  an Option : " ;

            int option;

            cin >> option;


            if(option == 1)
            {

                root = deleteWholeHeap(root);

            }

            else if(option == 2)
            {
                cout << "Enter the value You want to Delete : " ;

                int value;

                cin >> value;


                root = deleteElement(root,value);

                cout << "Element deleted Successfully " << endl;
            }

            else
            {
                cout << "invalid Option " << endl;
            }




        }

        else if(option == 5)
        {
            cout << "Nodes Of the Trees are : " << endl;

            Traversal(root);
        }

        else if(option == 6)
        {
            cout << "Showing the Nodes of the tree is : " << endl;

            showNodes(root);
        }

        else
        {
            cout << "invalid option you have Selected ." << endl;
        }
    }







    return 0;
}
