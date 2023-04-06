#include<iostream>

using namespace std;

class DoubleList
{
    //Private part
private:
    //VARAIBLES AND POINTERS
    int data;
    DoubleList * Next;
    DoubleList * Prev;
    DoubleList * First;
    DoubleList * Last;

public:
    //CONSTRUCTOR
    DoubleList();
// INSERT AT END OF LIST
    void InsertAtEndOfList(int data);
    // INSERT AT START OF LIST
    void InsertAtStart(int data);
    // PRINT FUNCTION
    void Print();
    //SEARCH THE ELEMENT
    bool SearchTheElement(int data);
    // SORT LIST
    void SortingList();
    //DELETE FIRST ELEMENT
    void DeleteAtFirst();
    //DELETE LAST ELEMENT
    void DeleteAtLast();
    //DELETE ANY ELEMENT
    void Deleted(int data);
    // MINIMUM FUNCTION
    int MinimumValue();
    //MAXIMUM VALUE
    int MaximumValue();
    //REVERSE THE LIST
    void ReverseList();
};

//DEFINATION OF CONSTRUCTOR
DoubleList::DoubleList()
{
    First = NULL;
    Last = NULL;
    Next = NULL;
    Prev = NULL;
}
//DEFINATION OF INSERT AT END
void DoubleList::InsertAtEndOfList(int data)
{
    //OBJECT 
    DoubleList * newNode = new DoubleList();
    newNode->data = data; // assign the value
    //Checking condition
    if(First == NULL)
    {
        First = Last = newNode;
    }
    else
    {
        newNode->Prev = Last;
        Last->Next = newNode;
        Last = newNode;
    }
}
//DEFINATION OF DATAVAT START
void DoubleList::InsertAtStart(int data)
{
    DoubleList *NewData = new DoubleList();
    NewData->data = data;
    NewData->Next = First;
    First->Prev = NewData;
    First = NewData;

}

//DEFINATION OF PRINT
void DoubleList::Print()
{
    DoubleList * temp = First;
    if (temp == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        cout << "Element of list are\t";
        while(temp->Next != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->Next;
        }
        cout << temp->data;
        cout << endl;
    }
}
//DEFINATION OF DELETE 
void DoubleList::Deleted(int data)
{
    DoubleList * temp = First;
    DoubleList * save;
    while(temp->Next != NULL)
    {
        if(temp->data == data)
        break;
        {
            save = temp;
        }
        temp = temp->Next;
    }
    save->Next = temp->Next;
    temp->Next->Prev = save;
    delete temp;
    temp = NULL;
    cout << data << " Deleted" << endl;
    Print();
}
//DEFINATION OF DELETE AT FIRST
void DoubleList::DeleteAtFirst()
{
    DoubleList *temp = First;
    First = First->Next;
    int value = temp->data;
    delete temp;
    temp = NULL;
    First->Prev = NULL;

    cout << value << " Deleted" << endl;
    Print();
}
//DEFINATION OF DELETE AT LAST
void DoubleList::DeleteAtLast()
{
    DoubleList *temp = First;
    DoubleList *save;
    int val;

    while(temp->Next != NULL)
    {
        temp = temp->Next;
        val = temp->data;
    }
    save = temp->Prev;
    save->Next = NULL;
    delete temp;
    temp = NULL;
    cout << val << " Deleted" << endl;
    Print();
}
//DEFINATION OF MINIMUM
int DoubleList::MinimumValue()
{
    int min = 0;
    DoubleList * temp = First;
    min = temp->data;
    
    while(temp != NULL)
    {
        if(temp->data < min)
        {
            min = temp->data;
        }
        temp = temp-> Next;
    }
    return min;
}
//DEFINATION OF MAXIMUM
int DoubleList::MaximumValue()
{
    int max = 0;
    DoubleList * temp = First;
    max = temp->data;
    
    while(temp!= NULL)
    {
        if(temp->data > max)
        {
            max = temp->data;
        }
        temp = temp-> Next;
    }
    return max;
}
//DEFINATION OF SORTING
void DoubleList::SortingList()
{
    DoubleList * temp = First;
    DoubleList * current;
    int num ;
    if (current == NULL)
    {
        cout << "List is Empty" << endl;
    }
    else
    {
        while(temp != NULL)
        {
            current = temp->Next;
            while(current != NULL)
            {
                if(temp->data > current->data)
                {
                    num = temp->data;
                    temp->data = current->data;
                    current->data = num;
                }
                current = current->Next;
            }
            temp = temp->Next;
        }
    }
    cout << "Sorted List->\t";
        Print();
}
//DEFINATION OF SEARCHING
bool DoubleList::SearchTheElement(int data)
{
    DoubleList * temp = First;

    while (temp != NULL)
    {
        if (temp->data == data)
        {
            return true;
        }
        temp = temp->Next;
    }
    return false;
}
//DEFINATION OF REVERSE LIST
void DoubleList::ReverseList()
{
    DoubleList *ptrOne = First;
    DoubleList * ptrTwo = First->Next;
    ptrOne->Next = NULL;
    ptrOne->Prev = ptrTwo;

    while (ptrTwo != NULL)
    {
        ptrTwo->Prev = ptrTwo->Next;
        ptrTwo->Next = ptrOne;
        ptrOne = ptrTwo;
        ptrTwo = ptrTwo->Prev;
    }
    First = ptrOne;
    cout << "Reverse list-->\t";
    Print();
    
}

int main()
{
    DoubleList list;
    
    list.InsertAtEndOfList(1);
    list.InsertAtEndOfList(3);
    list.InsertAtEndOfList(2);
    //TAKING CHOICE FROM USER
     char choice ;

        while (choice != 'e')
        {
            cout << "\n----------------------------------------------------\n";
            cout << "a) For Enter Data End of List\nb) For Searching Element in List" << endl;
            cout << "c) For Delete The Element from Intermediate\nd) For Minimum Element" << endl;
            cout << "f) For Maximum Element\ng) For Enter Data Start Of List\nh) For Delete The Element At End" << endl;
            cout << "i) For Sorting the list\nj) For Delete The element At First\nk) For Reverse The List\nl) For Print The list";
            cout << "\ns) For Clear The Screen\ne) For Exit From Loop" << endl << endl << endl;
            cout << "Enter Your Choice:\t" ;
            cin >> choice;
            cout << endl;
        switch(choice)
        {
            case 'a':
            //CALLING THE FUNCTION WHICH INSERT AT END OF LIST
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
                list.InsertAtEndOfList(data);
            }
                cout << "\nLimt of list Over\nAll The Element are\t";
                list.Print();
                cout << "\nAll the item of list display" << endl << endl;
                system("pause");
                break;

            case 'b':
            //SERACH THE ELEMENT
                int searchValue;
                list.Print();
                cout << "Enter the Element For Search:\t";
                cin >> searchValue;   
                if(list.SearchTheElement(searchValue))
                {
                    cout << "Value Exist:\t" << searchValue << endl;
                }
                else
                {
                    cout << "Value not Exist:\t" << searchValue << endl;
                }
                system("pause");
                break;

            case 'c':
            //DELETE THE DATA
                int value;
                cout << "Enter the Element For delete From:\t";
                list.Print();
                cin >> value; 
                if(list.SearchTheElement(value))
                {
                    list.Deleted(value);
                    cout << endl;
                }
                else
                {
                    cout << value << "\tElement are not exist" << endl;
                }
                system("pause");
                break;

            case 'd':
            //FINF MINIMUM NUMBER
                cout << "Minimum Number is->" << list.MinimumValue() << endl;
                cout << endl;
                system("pause");
                break;


            case 'f':
            //FIND MAXIMUM NUMBER
                cout << "Maximum Number is->" << list.MaximumValue() << endl;;
                cout << endl;
                system("pause");
                break;

            case 'g':
            //INSERT AT START
                int numOne;
                cout << "Select First number:\t";
                cin >> numOne;
                list.InsertAtStart(numOne);
                cout << endl;
                cout << "List are\t";
                list.Print();
                system("pause");
                break;            

            case 'h':
            //DELETE AT LAST
                list.DeleteAtLast();
                cout << endl;
                system("pause");
                break;

            case 'i':
            //SORTING THE LIST
                list.Print();
                cout << "------------------------------------------" << endl;
                list.SortingList();
                system("pause");
                break;  

            case 'j':
            //DELETE ELEMENT AT FIRST
                list.DeleteAtFirst();
                system("pause");
                break;

            case 'k':
                    //FOR REVERSE THE LIST
                    list.Print();
                    cout << "--------------------------------------------" << endl;
                    list.ReverseList();
                    system("pause"); 
                    break;

            case 'l':
                    list.Print();
                    system("pause");
                    break;        

            case 's':
                    //clear the screen
                    system("cls"); 
                    break;

            case 'e':
                    //EXIT FROM LOOP
                cout << "Exit from Loop\nThank You\n";
                break;
                    //DEFAULT CONDITION
            default:
                cout << "Wrong input!!\nPlz Choose Correct Option" << endl;
                system("pause");
                break;    
    }
        }
}