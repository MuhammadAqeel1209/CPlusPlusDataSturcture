#include<iostream>

using namespace std;

//CLASS
class Stack
{
    //PRIVATE PART
private:
        //VARAIBLE POINTERS
        int data;
        Stack *Next;
        Stack *Top;

public:
    //CONSTRUCTOR
    Stack();

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

Stack::Stack()
{
    Next = NULL;
    Top = NULL;
}

//DEFINATION OF ISEMPTY
bool Stack::IsEmpty()
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

//DEFINATION OF PUSH
void Stack::Push(int data)
{
    Stack *newNode = new Stack();
    newNode->data = data;
    newNode->Next = Top;
    Top = newNode;
}
//DEFINATION OF POP
void Stack::Pop()
{
    if(IsEmpty() == true)
    {
        cout << "Stack is empty" << endl;
        return;
    }
    else
    {
        Stack *delPtr;
        delPtr = Top;
        Top = Top->Next;
        delete delPtr;
        cout << "Value Pop " << endl;
        cout << "Element are left\t";
        Display();
    }
}
//DEFINATION OF TOP VALUE
int Stack::TopValue()
{
    if(IsEmpty() == true)
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return Top->data;
}

//DEFINATION OF DISPLAY 
void Stack::Display()
{
    Stack *temp = Top;
    if(IsEmpty() == true)
    {
        cout << "Stack is empty" << endl;
        return;
    }
    else
    {
        while (temp != NULL)
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
    Stack list;
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