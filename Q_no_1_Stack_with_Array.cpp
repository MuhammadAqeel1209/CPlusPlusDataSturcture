#include<iostream>

using namespace std;

//SIZE VARAIABLE
const int SIZE = 10;

//CLASS START
class Stack
{
    //PRIVATE PART
private:
    //VARAIBLES
    //ARRAYS
    int stackdata[SIZE];
    //VARAIBLE
    int top;

   // PUBLIC PART
public:
    //DEFAULT CONSTRUCTOR
    Stack();

    // CHECK THE EMPTY OF STACK
    //EMPTY FUNCTION
    bool IsEmpty();

    //CHECK THE FULL OF STACK
    //FULL FUNCTION
    bool IsFull();

    //CHECK THE SIXE OF STACK
    //SIZE FUNCTION
    int Size();

    //ENTER VALUE IN STACK
    //PUCH FUNCTION
    void Push(int data);

    //REMOVE VALUE FROM STACK
    //POP FUNCTION
    void Pop();
    
    //DISPLAY FUNCTION
    void Display();
    
};//END CLASS

//DEFINATION OF CONSTRUCTOR
Stack::Stack()
{
    top = 0;
}

// DEFINATION OF FULL FUNCTION
bool Stack::IsFull()
{
    //FOR FULL CHECK THE TOP MEMEBER OF STACK = SIZE OF STACK
    if(top == SIZE)
    {
        //RETURN TRUE
        return true;
    }
    else
    {
        //RETURN FALSE
        return false;
    }
}

//DEFINATION OF EMPTY FUNCTION
bool Stack::IsEmpty()
{
    //FOR EMPTY CHECK THE TOP VALUE = 0
    if(top == 0)
    {
        //RETURN TRUE
        return true;
    }
    else
    {
        //RETURN FALSE
        return false;
    }
}

//DEFINATION OF SIZE FUNCTION
int Stack::Size()
{
    //RETURN SIZE
    return top;
}

//DEFINATION OF PUCH FUNCTION
void Stack::Push(int data)
{
    //CHECK THE CONDITION THAT STACK IS FULL
    if(IsFull() == true)
    {
        cout << "STACK IS FULL\nTHANK YOU" << endl;
    }
    else
    {
        //OTHERWISE ADD NEW NUMBER
        stackdata[top++] = data;
    }
}

//DEFIANTION OF POP FUNCTION
void Stack::Pop()
{
    //CHECK THE CONDITION THAT STACK IS EMPTY
    if(IsEmpty() == true)
    {
        cout << " STACK IS EMPTY"<< endl;
    }
    else
    {
        //OTHERWISE WE REMOVE THE VALUE
        top--;
        //MESSAGE DISPLAY
        cout << "YOUR VALUE ALSO POP" << endl;
        cout << "Element are left\t";
        Display();
    }
}

//DEFINATION OF DISPAY FUNCTION
void Stack::Display()
{
    //FIRST CHECK THE TOP == 0
    if(IsEmpty() == true)
    {
        //MESSAGE DISPLAY
        cout << "NO VALUE IN THE STACK" << endl;
    }
    else
    {
        //OTHERWISE DISPLAY THE DATA FROM STACK
        for(int i =  Size() - 1; i >= 0; i-- )
        {
            cout << stackdata[i] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    
    //OBJECT MAKING
    Stack stk;
    //VARAIBLE
    int value;
    int choice;
     
     //INFINITY LOOP
     //CHECK THE CONDITION
    while (choice != -1)
    {
        //TAKING CHOICE FROM USER
       cout << "Enter the choice\n1) For Push Element\n2) For Pop Element\n3) For Check The Size Of Stack\n4) Display the Stack\n-1) For exit Function\t";
        cin >> choice;

        //SWITCH CASE
        switch (choice)
        {
            //FIRST CASE
        case 1:
        //FIRST CHECK STACK IS FULL
        if(stk.IsFull())
        {
            break;
        }
        else
        {
                    //MESSAGE DISPLAY
            cout << "\nSIZE OF STACK IS:\t" << SIZE  << endl;
            cout << "PLZ ENTER THE VALUE UNTIL STACK IS NOT FULL" << endl; 
            //OTHERWISE INPUT THE DATA IN STACK
            for( int i = 0; i < SIZE; i++)
            {
            cout << "Enter the element for Push on index [ " << i << " ]:\t";
            cin >> value;
            //CALLING PUSH FUNCTION
            stk.Push(value);   
            }
            cout << "\nSTACK IS FULL\nTHANK YOU" << endl;
            cout << endl << endl;
                break;
         }
          
        //SECOND CASE
        case 2:
        cout << endl;
        //CALLING POP FUNCTION
            stk.Pop();
            cout << endl << endl;
            break;

        //THIRD CASE
        case 3:
        //CALLING SIZE FUNCTION TO SIZE CHECK
          cout << "Size\t" << stk.Size() << endl << endl;
            break;

        //FOURTH CASE     
        case 4:
        cout << endl;
        //CALLING THE DISPLAY THE FUNCTION
            stk.Display();
            cout << endl << endl;
            break;   

        //FIFTH CASE
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