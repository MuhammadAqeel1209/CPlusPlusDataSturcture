#include <iostream>

using namespace std;

//NODE CLASS START 
class Node
{
    //PRIVATE PART
private:
    //VARAIBLE 
    int data;
    //NODE POINTER
    Node *Next;
    //PUBLIC PART
public:
    //CONSTRUCTOR
    Node();
    //GET DATA FROM USER
    int GetData();
    //GET ADDRESS OF NODE
    Node* GetNext();
    //SET THE DATA
    void SetData(int data);
    //SET NODE ADDRESS
    void SetNext(Node* Next);

};//END CLASS
//DEFINATION OF NODE CONSTRUCTOR
Node::Node()
{
    Next = NULL;
}

//DEFINATION OF GET DATA
int Node::GetData()
{
    return data;
}
//DEFINATION OF NODE ADDRESS
Node* Node::GetNext()
{
    return Next;
}
//DEFINATION OF SET DATA
void Node ::SetData(int data)
{
    this->data = data;
}
//DEFINATION OF SET NODE ADDRESS
void Node::SetNext(Node * Next)
{
    this->Next = Next;
}

//NEXT CLASS
class StackList
{
    //PRIVATE PART
private:
    //varaible
    int data;
    //pointer
    Node *Top;
public:
    //CONSTRUCTOR
    StackList();

    //PUSH METHOD
    void Push(int data);

    //POP METHOD
    void Pop();

    //TOP METHOD
    int TopValue();

    //CHECK THE EMPTY OR NOT
    bool IsEmpty();

    // DISPLAY THE ALL LIST
    void Display();
};

//DEFINATION OF CONSTRUCTOR
StackList::StackList()
{
    Top = NULL;
}

//DEFINATION OF EMPTY FUNCTION
bool StackList::IsEmpty()
{
    if(Top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//DEFINATION OF PUSH FUNCTION
void StackList::Push(int data)
{
    Node *newNode = new Node();
    newNode->SetData(data);
    newNode->SetNext(Top);
    Top = newNode;
}

//DEFINATION OF POP FUNCTION
void StackList::Pop()
{
    if(Top == NULL)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        Node *temp = Top;
        Top = Top->GetNext();
        delete temp;
        cout << "Value Pop" << endl;
        cout << "Element are left\t";
        Display();
    }
}

//DEFINATION OF TOP VALUE FUNCTION
int StackList::TopValue()
{
    if(IsEmpty() == true)
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    
    return Top->GetData();
}

//DEFINATION OF DISPLAY FUNCTION
void StackList::Display()
{
    Node * temp = Top;
    if(IsEmpty() == true)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        while(temp != NULL)
        {
            cout << temp->GetData() << "\t" ;
            temp = temp->GetNext();
        }
    }
}

int main()
{
    
    //OBJECT MAKING
    StackList list;
    //VARAIBLE
    int value;
    int choice;
    list.Push(1);
    list.Push(2);
    list.Push(3);
     
     //INFINITY LOOP
     //CHECK THE CONDITION
    while (choice != -1)
    {
        //TAKING CHOICE FROM USER
       cout << "Enter the choice\n1) For Push Element\n2) For Pop Element\n3) Display the Stack\n4) Top Value\n-1) For exit Function\t";
        cin >> choice;

        //SWITCH CASE
        switch (choice)
        {
            //FIRST CASE
        case 1:
        //FIRST CHECK STACK IS FULL
        if(list.IsEmpty() == true)
        {
            cout << "Stack is empty" << endl;
            break;
        }
        else
        {
            //TAKING SIZE OF LIST
            int size;
            cout << "Enter the Size Of List\t";
            cin >> size;
            cout << endl;
            //LOOP TO FILL THE LIST
            for(int i =0; i < size; i++)
            {
                int data;
                cout << "Enter the Element in list on index " << i + 1 << "\t";
                cin >> data;
                list.Push(data);
            }
                cout << "\nLimt of list Over\nAll The Element are\t";
                list.Display();
                cout << "\nALL THE ITEM OF LIST DISPLAY" << endl << endl;
                break;
         }
          
        //SECOND CASE
        case 2:
        cout << endl;
        //CALLING POP FUNCTION
            list.Pop();
            cout << endl << endl;
;            break;

        //THIRD CASE     
        case 3:
        cout << endl;
        //CALLING THE DISPLAY THE FUNCTION
            list.Display();
            cout << endl << endl;
            break;   

        //FOURTH CASE
        case 4:
            cout << "Top Value is\t" << list.TopValue() << endl << endl;    
            break;
        //LAST CASE
        case -1:
        cout << endl;
        //EXIT FROM FUNCTION
            cout << "Exit From function\nTHANK YOU" << endl;
            cout << endl;
            break;

        //DEFAULT CASE    
        default:
            cout << "INVALID INPUT!!!" << endl <<endl;
            break;
        }
    }
    
}
