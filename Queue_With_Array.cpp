#include<iostream>

using namespace std;

//SIZE VARAIABLE
const int SIZE = 5;

//CLASS START
class Queue
{
    //PRIVATE PART
private:
    //ARRAYS
    int queuedata[SIZE];
    //VARAIBLE
    int front;
    int rare;

   // PUBLIC PART
public:
    //DEFAULT CONSTRUCTOR
    Queue();

    // CHECK THE EMPTY OF QUEUE
    //EMPTY FUNCTION
    bool IsEmpty();

    //CHECK THE FULL OF QUEUE
    //FULL FUNCTION
    bool IsFull();

    //CHECK THE SIZE OF QUEUE
    //SIZE FUNCTION
    int Size();

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
    //GET BACK VALUE
    int GetLast();
    
};//END CLASS

//DEFINATION OF CONTRUCTOR
Queue::Queue()
{
    rare = -1;
    front = -1;
}

//DEFINATION OF SIZE FUNCTION
int Queue::Size()
{
    return(rare + 1);
}

//DEFINATION OF EMPTY FUNCTION
bool Queue::IsEmpty()
{
    //FOR EMPTY CHECK THE FRONT VALUE = -1
    if(rare == -1 || front == rare)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//DEFINATION OF FULL FUNCTION
bool Queue::IsFull()
{
    //FOR FULL CHECK THE RARE MEMBER OF QUEUE = SIZE OF QUEUE
    if(rare == SIZE - 1)
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
    if(IsFull() == true)
    {
        cout << "Queue is already Full" << endl;
    }
    else
    {
        queuedata[++rare] = data;
        
    }
}

//DEFINATION OF DEQUEUE
void Queue::Dequeue()
{
    if(IsEmpty() == true)
    {
        cout << "Queue is empty " << endl;
    }
    else
    {
        queuedata[front++];
        cout << "Value pop" << endl;
        cout << "Element are left\t";
        DisplayQueue();
    }
}

// DEFINATION OF DISPLAY QUEUE
void Queue::DisplayQueue()
{
    if(IsEmpty() == true)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue Element are: " << endl;
        for(int i = front + 1; i <= rare;i++)
        {
            cout << queuedata[i] << "\t";
        }
        cout << endl;
    }
}

//DEFINATION OF GET FRONT
int Queue::GetFront()
{
    if (IsEmpty() == true)
    {
        cout << "Queue is empty " << endl;
        return -1;
    }
    if(front == -1)
    {
        front++;
    }
    return queuedata[front];
}

//DEFINATION OF GET BACK
int Queue::GetLast()
{
     if (IsEmpty() == true)
    {
        cout << "Queue is empty " << endl;
        return -1;
    }
    return queuedata[rare];
}

int main()
{

    //OBJECT MAKING
    Queue queue;
    //VARAIBLE
    int value;
    int choice;
     
     //INFINITY LOOP
     //CHECK THE CONDITION
    while (choice != -1)
    {
        //TAKING CHOICE FROM USER
       cout << "Enter the choice\n1)For Enqueue\n2)For Dequeue\n3)Size of Queue\n4)Display the Queue\n5)Front Value\n6)Last Value\n7)Clear Screen\n-1)For exit Function\t";
       cin >> choice;

        //SWITCH CASE
        switch (choice)
        {
            //FIRST CASE
        case 1:
        //FIRST CHECK QUEUE IS FULL
            if(queue.IsFull())
            {
                cout << "\nQueue is Full\nThanks You" << endl;
                break;
            }
            else
            {
                //MESSAGE DISPLAY
                cout << "\nSize Of Queue is:\t" << SIZE  << endl;
                cout << "Enter the value for full the Queue" << endl; 
                //OTHERWISE INPUT THE DATA IN STACK
                for( int i = 0; i < SIZE; i++)
                {
                    cout << "Enter the element for enqueue on index [ " << i << " ]:\t";
                    cin >> value;
                //CALLING ENQUEUE FUNCTION
                    queue.Enqueue(value);  
                }
                    cout << "\nQueue is Full\nThanks You" << endl;
                    cout << endl << endl;
                    break;
            }
          
        //SECOND CASE
        case 2:
            cout << endl;
            //CALLING POP FUNCTION
            queue.Dequeue();
            cout << endl << endl;
            break;

        //THIRD CASE
        case 3:
        //CALLING SIZE FUNCTION TO SIZE CHECK
          cout << "Size\t" << queue.Size() << endl << endl;
            break;

        //FOURTH CASE     
        case 4:
            cout << endl;
            //CALLING THE DISPLAY THE FUNCTION
            cout << "List Elements are:\t";
            queue.DisplayQueue();
            cout << endl << endl;
            break;   

        //FIFTH CASE
        case 5:
            cout << endl;
            cout << "Front Value\t" << queue.GetFront() << endl << endl;
            break;

         // SIXTH CASE
         case 6:
            cout << endl; 
            cout << "Last Value\t" << queue.GetLast() << endl << endl;
            break;

        case 7:
            system("cls");
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
