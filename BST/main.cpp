#include <iostream>

using namespace std;


struct Tree
{
    int data = 0;

    Tree *right = nullptr;

    Tree *left = nullptr;
};





Tree* Searching(int value,Tree *root)
{

    if(root->data == value)
    {
       return root;

    }

    else if(value < root->data)
    {
        root = root->left;
        if(root != nullptr)
        {
            Searching(value,root);
        }

        else
        {

            cout << "Value not Found " << endl;
        }

    }
    else if(value > root-> data )
    {
        root = root->right;
        if(root != nullptr)
        {
            Searching(value,root);
        }

        else
        {
            cout << "Value not found" << endl;

        }


    }



}

void insertion(int number , Tree *root)
{


    if(root->data == 0 )
    {


        root->data = number;

        cout << root << endl;


    }

     else if(number < root->data)
     {
          if(root->left == nullptr)
          {
              root->left = new Tree;
          }


          root = root->left;

          insertion(number,root);





     }

     else if(number > root->data)
     {
         if(root->right == nullptr)
         {
             root->right = new Tree;
         }



        root = root->right;

        insertion(number,root);


     }

}

void inorder(Tree *root)
{

    if(root->left != nullptr)
    {
         inorder(root->left);
    }


    cout << root ->data << " ";


    if(root->right != nullptr)
    {
         inorder(root->right);
    }







}



void preorder(Tree *root)
{
    cout << root->data << " ";

    if(root->left != nullptr)
    {
        preorder(root->left);
    }

    if(root->right != nullptr)
    {
        preorder(root->right);
    }

}


void postorder(Tree *root)
{


    if(root->left != nullptr)
    {
        postorder(root->left);
    }

    if(root->right != nullptr)
    {
        postorder(root->right);
    }

    cout << root->data << " ";
}

void traversal(Tree *root , int option)
{

    if(option == 1)
    {

        inorder(root);

    }

    else if(option == 2)
    {
        preorder(root);
    }
    else if(option == 3)
    {
        postorder(root);
    }


}


Tree* findlow(Tree *root)
{
    root = root->right;


    while(root->left != nullptr)
   {

        root = root->left;

   }


   return root;
}


void Delete(int number ,Tree *root)
{
    Tree* node = Searching(number,root);




    if(node->left== nullptr && node->right == nullptr)
    {
        while(true)
        {
            if(root->right == node)
            {
                root->right = nullptr;
                delete node;
                break;
            }
            else if(root->left == node)
            {
                root->left = nullptr;
                delete node;
                break;
            }

            else if(number < root->data)
            {
                root = root->left;
            }

            else if(number > root->data)
            {
                root = root-> right;
            }
        }


    }
    else if (node->left == nullptr || node->right == nullptr)
    {

        if(node->left != nullptr)
        {
           while(true)
        {
            if(root->right == node)
            {
                root->right = (root->right)->left;

                delete node;

                break;
            }

            else if(root->left == node)
            {
                root->left = (root->left)->left;

                delete node;

                break;
            }

            else if(number > root->data)
            {
                root = root->right;
            }
            else if(number < root->data)
            {

                root = root->left;

            }
        }
        }

        else if(node->right != nullptr)
        {
                while(true)
        {
            if(root->right == node)
            {
                root->right = (root->right)->right;

                delete node;

                break;
            }

            else if(root->left == node)
            {
                root->left = (root->left)->right;

                delete node;

                break;
            }

            else if(number > root->data)
            {
                root = root->right;
            }
            else if(number < root->data)
            {

                root = root->left;

            }
        }
        }

    }
    else if(node->left != nullptr && node->right != nullptr)
    {

        Tree  *lowest = findlow(node);

        int value = lowest->data;


        Delete(lowest->data,root);


        node->data = value;



    }

}

int main()
{

    cout << "Enter the First Node Of Binary tree " << endl;

    int value;

    cin >> value;

    Tree node;

    node.data = value;

    Tree *root = &node;

    cout << &node << endl;



    while(true)
    {
        cout << "1.Insert in tree" << endl;
        cout << "2.Search in tree" << endl;
        cout << "3.Delete in tree" << endl;
        cout << "4.Traversal in tree" << endl;
        cout << "5.Exit" << endl;

        int option;

        cin >> option;

        if(option == 1)
        {
            cout << "Insert the value : " ;

            int number;
            cin >> number;
            insertion(number,root);



        }


        else if(option == 2)
        {
            cout << "Enter the number you want to search: " ;

            int number;

            cin >> number;

            cout <<"The value is :-" << (Searching(number,root))->data  << endl;
        }

        else if(option == 3)
        {

            cout << "Enter the value you want to delete : ";

            int number ;

            cin >> number;

            Delete(number,root);
        }

        else if(option == 4)
        {
            cout << "1.Inorder " << endl;
            cout << "2.preorder" << endl;
            cout << "3.postorder" << endl;

            int op;

            cin >> op;

            if(op == 1)
            {
                traversal(root,op);
            }

            else if(op == 2)
            {
                traversal(root,op);
            }

            else if(op == 3)
            {
                traversal(root,op);

            }



        }


        else if(option == 5)
        {
            break;
        }



    }












    return 0;
}
