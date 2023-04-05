#include<iostream>

using namespace std;

//CLASS START
class Queue
{
    //Private Part
private:
    // Varaible pointer
    int data;
    Queue * Next;
    Queue * Front;
    Queue * Rare;
public:
    //CONSTRUCTOR
    Queue();
    
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

};

//DEFINATION OF CONSTRUCTOR
Queue::Queue()
{
    Rare = NULL;
    Front = NULL;
}

//DEFINATION OF EMPTY
bool Queue::IsEmpty()
{
    if(Front == NULL || Rare == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//DEFINATION OF ENQUEUE
void Queue::Enqueue(int data)
{
    Queue * NewNode = new Queue();
    NewNode->data = data;
    NewNode->Next = NULL;
    if(IsEmpty() == true)
    {
        Front = NewNode;
        Rare = NewNode;
    }
    else
    {
        Rare->Next = NewNode;
        Rare = NewNode;
    }
}

//DEFINATION OF DEQUEUE
void Queue::Dequeue()
{
    Queue * temp = Front;
    Front = Front->Next;
    delete temp;
    temp = NULL;
    cout << "Value Pop" << endl;
    cout << "Element are left\t";
    DisplayQueue();
}
//DEFINATION OF GET FRONT
int Queue::GetFront()
{
    if(IsEmpty() == true)
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
        return Front->data;

}
//DEFINATION OF DISPLAY
void Queue::DisplayQueue()
{
    Queue * temp = Front;
    if(IsEmpty() == true)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        while(temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->Next;
        }
            cout << endl;
    }
}

int main()
{
     //OBJECT MAKING
    Queue list;
    //VARAIBLE
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
