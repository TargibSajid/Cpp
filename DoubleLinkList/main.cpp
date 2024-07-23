#include <iostream>

using namespace std;


struct DoubleLinklist
{

    int number;

    DoubleLinklist *next = nullptr;

    DoubleLinklist *previous = nullptr;

};


DoubleLinklist* SearchNode(int value,DoubleLinklist *head)
{

    DoubleLinklist *curr = head;

    while(value != curr->number)
    {
        curr = curr->next;

        if(curr == nullptr)
        {
            cout << "value not found " << endl;

            break;


        }



    }

    if(curr != nullptr)
    {
        cout << "Node found successfully" << endl;

    }

    return curr;





}

DoubleLinklist* AddNode(int value,DoubleLinklist *head)
{

    DoubleLinklist *curr = head ;

    cout << "\t1.Add at the Head." << endl;
    cout << "\t2.Add at the Middle." << endl;
    cout << "\t3.Add at the End" << endl;

    cout << "\t Enter your option: ";

    int option;

    cin >> option ;


    if(option == 1)
    {


        DoubleLinklist *newNode = new DoubleLinklist();

        newNode->next  = head;

        head->previous = newNode;

        newNode->number = value;

        newNode->previous = nullptr;

        cout << "Node Added Successfully.." << endl;

        return newNode;






    }

    else if(option == 2)
    {
        cout << "\t\tEnter the node Number you want to add after : ";

        int number ;

        cin >> number;

        DoubleLinklist *node = SearchNode(number,head);

        DoubleLinklist *newNode = new DoubleLinklist();

        newNode->next = node->next;

        (node->next)->previous = newNode;

        node->next = newNode;

        newNode->previous = node;


        newNode->number = value;


        cout << "\t \n node added Succesfully...!" << endl;


        return head;






    }

    else if(option == 3)
    {

        DoubleLinklist *newNode = new DoubleLinklist();

        newNode->number = value;


        DoubleLinklist *curr = head;

        while(curr ->next != nullptr)
        {
            curr = curr->next;

        }

        curr->next = newNode;

        newNode->previous = curr;

        newNode->next = nullptr;



        cout << "Node Added Successfully...!" << endl;

        return head;




    }

    else{

        cout << "\n....... invalid option ....!\n";

        return head;


    }




    return head;



}

DoubleLinklist* DeleteNode(int value , DoubleLinklist *head)
{

    DoubleLinklist *node = SearchNode(value,head);

    cout << "Node found !!..node is " << node << " & node value is : " << node->number << endl;



    if(node->previous != nullptr && node->next != nullptr)
    {
        (node->previous)->next = node->next;

        (node->next)->previous = node->previous;

        return head;
    }

    else
    {
        if(node->previous == nullptr)
        {
            (node->next)->previous = node->previous;

            return node->next;
        }

        else if(node->next == nullptr)
        {
            (node->previous)->next = node->next;

            return head;

        }
    }



    cout << node << endl;

    delete [] node;

    cout << node << endl;



}




void showAllNodes(DoubleLinklist *head)
{
    DoubleLinklist *curr = head;

    cout << "Nodes are -  " ;


    while(curr != nullptr)
    {
        cout << curr->number << " " ;

        curr = curr-> next;

    }

    cout << endl;





}






int main()
{

    DoubleLinklist *head = new DoubleLinklist();

    head->previous = nullptr;

    while(true)
    {
        cout << "=====================\n" << endl;
        cout << "1.Add Node."<< endl;
        cout << "2.Delete Node." << endl;
        cout << "3.Show all Node" << endl;
        cout << "4.Search Node" << endl;
        cout << "\n=====================" << endl;


        cout << "\nSelect Option : ";


        int option;

        cin >> option;

        if(option == 1)
        {
            cout << "Enter the value you want to Add : ";

            int value;

            cin >> value;

            if(head->number == 0)
            {
                head->number = value;

            }

            else
            {
                head = AddNode(value,head);

            }


        }

        else if(option == 2)
        {
            cout << "Enter the value you want to Delete : ";

            int value;

            cin >> value;

            head = DeleteNode(value,head);
        }

        else if(option == 3)
        {
            showAllNodes(head);
        }

        else if(option ==  4)
        {
            cout << "Enter the value you want to search: ";

            int value;

            cin >> value;


            DoubleLinklist *node = new DoubleLinklist();

            node = SearchNode(value,head);

            cout << "Node is " <<  node->number << endl;
        }

        else
        {
            cout << "Invalid Option" << endl;
        }

    }







}


