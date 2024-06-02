#include <iostream>

using namespace std;

struct Linklist
{
    int data;

    Linklist *next;



};
Linklist *Head ;

Linklist *curr;

void traversal()
{

   curr = Head;

   while(curr!= nullptr)
   {
       cout << curr -> data << endl;

       curr = curr-> next;
   }
}


void insertion(Linklist *node)
{

    cout << "Select : " << endl;

    int Select;

    cout << "1.insert at Head." << endl;
    cout << "2.Insert  at middle. " << endl;
    cout << "3.Insert at last." << endl;

    cin >> Select;


        if(Select == 1)
        {
            cout << "Enter the value : ";

            cin >> node->data;

            node->next = Head;

            Head = node;


        }





        else if(Select == 2)
        {
            int value;

        cout << "Enter the  value you want to insert before it : " ;

        cin >> value;

        curr = Head;

        while(curr!= nullptr)
        {
            if(value = curr->data)
        {
            break;
        }

            curr = curr-> next;

        }



        cout << "Enter the value want to insert : " ;

        cin >> node->data;

        node->next= curr->next;

        curr->next = node;






        }





        else if(Select == 3)
        {
            cout << "Enter the value want to insert : " ;

        cin >> node->data;


        curr = Head;

        while(curr!= nullptr)
        {
            if(curr -> next == nullptr)
        {
            break;
        }

            curr = curr-> next;

        }



        curr->next = node;

        node->next = nullptr;

         cout << node << endl;


        }







    }


    void searching(int value)
    {
        curr = Head;

   while(curr!= nullptr)
   {

       if(curr-> data  == value)
       {
           cout << "found" << endl;
           break;
       }

       curr = curr-> next;
   }
    }



    void Deletion(int value)
    {

        curr = Head;

        while (curr != nullptr)
        {
            if(curr-> next-> data  == value)
            {



                Linklist *v = curr-> next;

                curr->next = v-> next;




                break;

            }

                curr = curr->next;

        }



    }


int main()
{
    Linklist node1,node2,node3,node4,node5 ;

    Head = &node1;

    node1.data = 10;
    node2.data = 20;
    node3.data = 30;
    node4.data = 40;
    node5.data = 50;


    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = nullptr;

   cout << "Linklist Operations : - " << endl;

   traversal();

   Linklist node6;

   cout << &node6 <<endl;

   insertion(&node6);
   traversal();
   searching(50);

   cout << "Enter the data you want to remove : " ;

   int data;

   cin >> data;

   Deletion(data);

   traversal();









    return 0;
}
