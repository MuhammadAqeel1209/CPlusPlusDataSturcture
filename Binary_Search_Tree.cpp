#include<iostream>
#include<math.h>

using namespace std;

//CLASS START
class TreeNode
{
    private:
    //Varaible and pointer
       int data; 
        TreeNode *Left;
        TreeNode *Right;
public: 
       //CONSTRUCTOR
TreeNode(int data)
    {
        //Assign the data
        this->data = data;
        this->Left = NULL;
        this->Right = NULL;
    }
    //Insert the Node 
TreeNode *InsertNode(TreeNode* Root, int data)
    {
        if(Root == NULL) // Root Null 👈
        {
            Root = new TreeNode(data);
        }
        else if(data < Root->data) // Data small then root move to left 👈
        {
            Root->Left = InsertNode(Root->Left, data);
        }
        else
        {
            Root->Right = InsertNode(Root->Right, data);  // Data large then root move to right 👈
        }
        return Root;
    }
    //Inorder Traversal
    void InOrderTraversal()
    {  
        //Display in the form 👉 //Left Root Right
        if (this->Left != NULL)
            this->Left->InOrderTraversal();
        cout << this->data << " ";
        if(this->Right != NULL)
            this->Right->InOrderTraversal();    
    }
    //Post Order Traversal
    void PostOrderTraversal()
    {   
        //Display in the form 👉 //Left Right Root
        if(this->Left != NULL)
            this->Left->PostOrderTraversal();
        if(this->Right != NULL)
            this->Right->PostOrderTraversal();
        cout <<  this->data << " ";    
    }
    //Pre Order Traversal
    void PreOrderTraversal()
    {
        //Display in the form 👉 // Root Left Right

        cout << this->data << " ";
        if(this->Left != NULL)
            this->Left->PreOrderTraversal();
        if(this->Right != NULL)
            this->Right->PreOrderTraversal();    
    }

    //Number of leaf Nodes
    int NoOfLeafNode(TreeNode * Root)
    {
        if(Root != NULL)
        {
            if(Root->Left == NULL && Root->Right == NULL)
            {
                return 1;
            }
            else
            {
                return NoOfLeafNode(Root->Left) + NoOfLeafNode(Root->Right);
            }
        }
        else
        {
            return 0;
        }
    }

    //Height of tree
    int HeightOfTree(TreeNode * Root)
    {
        if(Root == NULL)
        {
            return 0;
        }
        else
        {
            return max(HeightOfTree(Root->Left),HeightOfTree(Root->Right)) + 1;
        }
    }

    //Size of tree
    int SizeOfTree(TreeNode * Root)
    {
        if(Root == NULL)
        {
            return 0;
        }
        else
        {
            return SizeOfTree(Root->Left) + SizeOfTree(Root->Right) + 1;
        }
    }

    //Print In form of Tree
    void PrintCurrentLevel(TreeNode * Root,int Level)
    {
        if(Root == NULL)
            return;
        else if (Level == 1)
                cout << Root->data << "\t" ;  
        else if(Level > 1)
                PrintCurrentLevel(Root->Left,Level - 1); 
                PrintCurrentLevel(Root->Right,Level - 1);
    }
    //Delete the Node
    TreeNode *DeleteTheData(TreeNode *Root,int value)
    {
        if(Root == NULL)
            return  Root;
        else if(value < Root->data) //value small the root delete the left value
            Root->Left = DeleteTheData(Root->Left, value);
        else if(value > Root->data)  //value greater the root delete the right value
            Root->Right = DeleteTheData(Root->Right, value);
        else //last case when delete element has one child
            if(Root->Left == NULL) //Left Child not avaiable return the right and link it
                return Root->Right;
            else if(Root->Right == NULL) //Right Child not avaiable return the Left and link it
                return Root->Left;
            else // Both Child exist then we find small value then we link it 
                Root->data = MinimumValue(Root->Right);
                Root->Right = DeleteTheData(Root->Right,Root->data);

        return Root;                       
    }


    //Minimum Find
    int MinimumValue(TreeNode * Root)
    {
        //-->Iteration Method  👇👇👇
    //    TreeNode * Current = Root;
    //    while (Current->Left != NULL)
    //    {
    //         Current = Current->Left;
    //    }
    //    return Current->data;

        //--> Recusrion Method 👇👇👇
        if(Root == NULL)
            return -1;
        else if(Root->Left == NULL) //For Minimum mov to left
                return Root->data;
        
        return MinimumValue(Root->Left);        
    }

    //Maximum Find
    int MaximumValue(TreeNode * Root)
    {
        //-->Iteration Method  👇👇👇
       TreeNode * Current = Root;
       while (Current->Right != NULL)
       {
            Current = Current->Right;
       }
       return Current->data;

        //--> Recusrion Method 👇👇👇
        // if(Root == NULL)
        //     return -1;
        // else if(Root->Left == NULL) //For Maximum mov to right
        //         return Root->data;
        
        // return MinimumValue(Root->Left);        
    }

    //Search The Element
    bool SearchTheElement(TreeNode * Root,int data)
    {
        if(Root == NULL)
            return false;
        else if(Root->data == data)
            return true;    
        else if(Root->data > data) // data small move to left
            return  SearchTheElement(Root->Left,data);
        else if(Root->data < data) //data large move right
            return SearchTheElement(Root->Right,data);
        else
            return false;

    }


};
int main()
{   
    //TreeNode *Root = new TreeNode(5); // Root Node
    // Root->InsertNode(Root,3); // Move to left Node Beacuse data value is small then Root Node
    // Root->InsertNode(Root,7); // Move to Right Node Beacuse data value is greater then Root Node
    cout << "\n\nFirstly You Enter the data in Tree Data Structure" << endl << endl;
    int size = 0;
    cout << "Enter the size for tree node:\t";
    cin >> size;
    int node[size];
    for(int i = 0; i < size ;i++)
    {
        cout << "Enter data [ " << i + 1 << " ]:\t";
        cin >> node[i];
    }
    TreeNode *Root = new TreeNode(node[0]);
    for(int i = 1; i < size ;i++)
    {
        Root->InsertNode(Root,node[i]);
    }

        cout << "Element are Inserted in the Tree Data Structure" << endl << endl;
    int choice ;
    while(choice != -1)
    {
        cout << "Enter the choice\n1) For InOrder Traversal\n2) For PostOrder Traversal\n3) For PreOrderTraversal";
        cout << "\n4) To Check The Root node\n5) To Check The Amount Of Leaf Nodes\n6) To Check The Height of Tree";
        cout << "\n7) To Check The Size Of Tree\n8) To Delete The Value\n9) Minimum value\n10) Maximmum value";
        cout << "\n11) Search The Element\n12) Print the tree\n13) Clear The System\n-1) For Exit" << endl << endl;
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "\n\nInorder Traversal ";
                Root->InOrderTraversal(); //Left Root Right
                cout << endl << endl;
                system("Pause");
                break;

            case 2:    
                cout << "\n\nPostorder Traversal " ;
                Root->PostOrderTraversal(); //Left Right Root
                cout << endl << endl;
                system("Pause");
                break;

            case 3:
                cout << "\n\nPreOrder Traversal ";
                Root->PreOrderTraversal(); // Root Left Right
                cout << endl << endl;
                system("Pause");
                break;

            case 4:    
                cout << "\n\nRoot Node is:\t\t" << node[0] << endl;
                system("Pause");
                break;

            case 5:    
                cout << "Leaf Nodes are:\t\t" << Root->NoOfLeafNode(Root) << endl;
                system("Pause");
                break;

            case 6:        
                cout << "Height of tree is:\t" << Root->HeightOfTree(Root) << endl;
                system("Pause");
                break;

            case 7:    
                cout << "Size of tree is:\t" << Root->SizeOfTree(Root) << endl;
                system("Pause");
                break;

            case 8:
                int deleteVal;
                cout << "Enter the Value for Delete:\t";
                cin >> deleteVal;
                if(Root->SearchTheElement(Root,deleteVal))
                    Root->DeleteTheData(Root,deleteVal);
                else
                    cout << "Not Found the data" << endl;    

                cout << deleteVal << " Deleted " << endl;
                cout << "\nAfter Deletion\t";
                for (int i = 0; i <= Root->HeightOfTree(Root); i++)
                {
                    Root->PrintCurrentLevel(Root,i);
                    cout << endl;
                }
                system("Pause");
                break;

            case 9:
                cout << "Minimum Value is\t" << Root->MinimumValue(Root) << endl;
                system("Pause");
                break;

            case 10:
                cout << "Maximum Value is\t" << Root->MaximumValue(Root) << endl;
                system("Pause");
                break;

            case 11:
                int searchVal;
                cout << "Enter the Value for Search:\t";
                cin >> searchVal;
                if(Root->SearchTheElement(Root,searchVal) == true)
                        cout << searchVal << " Element Are Found" << endl;
                    else
                        cout << searchVal << " Element Are Not Found" << endl;
                system("Pause");        
                break;        

            case 12:
                cout << "Print The Exactly Tree\t";
                for (int i = 0; i <= Root->HeightOfTree(Root); i++)
                {
                    Root->PrintCurrentLevel(Root,i);
                    cout << endl;
                }
                system("Pause");
                break;

            case 13:
                system("cls");
                break;

            case -1:
                cout << "Exit The Loop\nThanks You" << endl << endl;
                break;
            default:
                cout << "Invalid Input!!" << endl;
                break;    
        }
    }
}