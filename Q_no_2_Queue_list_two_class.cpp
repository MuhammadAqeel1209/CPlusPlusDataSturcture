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
class QueueList
{
    //PRIVATE PART
private:
    
    //Pointers
    Node * Front;
    Node * Rear;
public:
    //DEFAULT CONSTRUCTOR
    QueueList();

    // CHECK THE EMPTY OF QUEUE
    //EMPTY FUNCTION
    bool IsEmpty();
    
    //GET FRONT FUNCTION
    int GetFront();

    //ENTER VALUE IN QUEUE
    //ENQUEUE FUNCTION
    void Enqueue(int data);

    //REMOVE VALUE FROM QUEUE
    //DEQUEUE FUNCTION
    void Dequeue();
    
    //DISPLAY FUNCTION
    void DisplayQueue();

};//END CLASS

//DEFINATION OF CONSTRUCTOR
QueueList::QueueList()
{
    Front = NULL;
    Rear = NULL;
}



//DEFINATION OF EMPTY FUNCTION
bool QueueList::IsEmpty()
{
    if(Rear == NULL || Front == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//DEFINATION OF ENQUEUE FUNCTION
void QueueList::Enqueue(int data)
{
    Node *newNode = new Node();
    newNode->SetData(data);
    newNode->SetNext(NULL);
    if(IsEmpty() == true)
    {
        Rear = newNode;
        Front = newNode;
    }
    else
    {
        Rear->SetNext(newNode);
        Rear = newNode;
    }
}

//DEFINATION OF DEQUEUE FUNCTION
void QueueList::Dequeue()
{
    if(IsEmpty() == true)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        Node *temp = Front;
        Front = Front->GetNext();
        delete temp;
        cout << "Value Pop" << endl;
        cout << "Element are left\t";
        DisplayQueue();
    }
}

//DEFINATION OF Front VALUE FUNCTION
int QueueList::GetFront()
{
    if(IsEmpty() == true)
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    
    return Front->GetData();
}

//DEFINATION OF DISPLAY FUNCTION
void QueueList::DisplayQueue()
{
    Node * temp = Front;
    if(IsEmpty() == true)
    {
        cout << "Queue is empty" << endl;
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
    QueueList list;
    //VARAIBLE
    int value;
    int choice;
    list.Enqueue(1);
    list.Enqueue(2);
    list.Enqueue(3);
     
     //INFINITY LOOP
     //CHECK THE CONDITION
    while (choice != -1)
    {
        //TAKING CHOICE FROM USER
       cout << "Enter the choice\n1) For Enqueue Element\n2) For Deqeue Element\n3) Display the Queue\n4) Top Value\n-1) For exit Function\t";
       cin >> choice;

        //SWITCH CASE
        switch (choice)
        {
            //FIRST CASE
        case 1:
            
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
                    list.Enqueue(data);
                }
                    cout << "\nLimt of list Over\nAll The Element are\t";
                    list.DisplayQueue();
                    cout << "\nAll the item of list display" << endl << endl;
                    break;
            
        //SECOND CASE
        case 2:
        cout << endl;
        //CALLING DEQUEUE FUNCTION
            list.Dequeue();
            cout << endl << endl;
           break;

        //THIRD CASE     
        case 3:
        cout << endl;
        //CALLING THE DISPLAY THE FUNCTION
            cout << "List elements are:\t";
            list.DisplayQueue();
            cout << endl << endl;
            break;   

        //FOURTH CASE
        case 4:
            cout << "Top Value\t";
            cout << list.GetFront() << endl << endl;    
            break;
        //LAST CASE
        case -1:
        cout << endl;
        //EXIT FROM FUNCTION
            cout << "Exit From function\nThank You" << endl;
            cout << endl;
            break;

        //DEFAULT CASE    
        default:
            cout << "IInvalid Input" << endl <<endl;
            break;
        }
    }
 
}