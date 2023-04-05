#include <iostream>
using namespace std;

//CLASS START
class SingleList
{
    //PRIVATE PART
private:
    //VARAIBLE POINTER
    int data;
    SingleList * Next;
    SingleList * Head;
    //PUBLIC PART
public:
    //CONDTRUCTOR
    SingleList();
     //PRINT FUNCTION 
    void Print();
    //INSERT temp FUNCTION
    void InsertDataInEndList(int data);
    //DELETE temp FUNCTION
    void DeleteDataFromList(int data);
    //TRANSVERSE OF LIST
    void TransverseOfList();
    //SEARCH THE NUMBER
    bool SearchingNumberInList(int data);
    //SORTING THE LIST
    void SortingTheList();
    //FIND MINIMUM NUMBER
    void MinimumNumberFromList();
    //FIND THE MAXIMUM NUMBER
    void MaximumNumberFromList();
    //SWAPP THE LIST ELEMENT
    void SwaappTheElement(int numOne,int numTwo);
    //ADD ELEMENT AT DESIRED LOCATION
    void AddElementAtDesiredLocation(int data,int position);
    //ADD temp FIRST LOCATION
    void AddDataAtFirstLocation(int data);

};
//DEFINATION OF CONSTRUCTOR
SingleList::SingleList()
{
    Next = NULL;
    Head = NULL;
}
//DEFINATION OF INSERT AT END
void SingleList::InsertDataInEndList(int data)
{
    SingleList * NewDtemp = new SingleList();
    NewDtemp->data = data;
    NewDtemp->Next = NULL;

    SingleList * temp = Head;
    if(temp != NULL)
    {    
        while(temp->Next != NULL)
        {
            temp = temp->Next;
        }
        temp->Next = NewDtemp;
    }
    else
    {
        Head = NewDtemp;
    }
}
//DEFINATION OF PRINT
void SingleList::Print()
{
    SingleList * temp = Head;
    if(temp == NULL)
    {
        cout << "List is empty" << endl;
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
//DEFINATION OF TRANSVERSE OF LIST
void SingleList::TransverseOfList()
{
    SingleList * temp = Head;
    if(temp == NULL)
    {
        cout << "List is empty" << endl;
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
//DEFINATION OF AT FIRST LOCATION
void SingleList::AddDataAtFirstLocation(int data)
{
    SingleList * temp = new SingleList();
    temp->data = data;
    temp->Next = Head;
    Head = temp;
}
//DEFINATION OF DELETE
void SingleList::DeleteDataFromList(int data)
{
    SingleList * storePtr;
    SingleList *delPtr = Head;
    if(delPtr == NULL)
    {
        cout << "List is Empty" << endl;
    }
    else
    {
        while (delPtr !=  NULL)
        {
            if(delPtr->data == data)
            break;
            {
                storePtr = delPtr;
            }
            delPtr = delPtr->Next;
        }
        storePtr->Next = delPtr->Next;
        delete delPtr;
        delPtr = NULL;
        cout << data << " is Deleted" << endl;
    }
    
}
//DEFINATION OF MINIMUM
void SingleList::MinimumNumberFromList()
{
    int min = 0;
    SingleList * temp = Head;
    min = temp->data;
    while (temp != NULL)
    {
        if(temp->data < min)
        {
            min = temp->data;
        }
        temp = temp->Next;
    }
    cout << "Minimum Number is\t" << min << endl;
    
}
//DEFINATION OF MAXIMUM
void SingleList::MaximumNumberFromList()
{
    int max = 0;
    SingleList * temp = Head;
    max = temp->data;
    while (temp != NULL)
    {
        if(temp->data > max)
        {
            max = temp->data;
        }
        temp = temp->Next;
    }
    cout << "Maximum Number is\t" << max << endl;
}
//DEFINATION OF SWAPP
void SingleList::SwaappTheElement(int one,int two)
{
    SingleList * Node = Head;
    while (Node != NULL)
    {
        if(Node->data == one)
        {
            Node->data = two;
        }
        else if(Node->data == two)
        {
             Node->data = one;
        }
        Node = Node->Next;
    }  
}
//DEFINATION OF SEARCHING
bool SingleList::SearchingNumberInList(int data)
{
    SingleList * temp = Head;
    while(temp != NULL)
    {
        if(temp->data == data)
        {
            return true;
        }
        temp = temp->Next;
    }
        return false;
}
//DEFINATION OF SORTING
void SingleList::SortingTheList()
{
    SingleList * temp = Head;
    SingleList * current = NULL;
    int data;

    while (temp != NULL)
    {
        current = temp->Next;
        while (current != NULL)
        {
            if(temp->data > current->data)
            {
                data = temp->data;
                temp->data = current->data;
                current->data = data;
            }
            current = current->Next;
        }
        temp = temp->Next;
    }
    Print();
}
//DEFINATION OF DATA ENTER AT DESIRED LOCATION
void SingleList::AddElementAtDesiredLocation(int data,int position)
{
    int count = 0;
    SingleList * newNode = new SingleList();
    newNode->data = data;
    if(Head == NULL)
    {
        Head = newNode;
    }
    else
    {
        SingleList *temp = Head;
        while(temp != NULL)
        {
            if(count == position - 1)
            {
                newNode->Next = temp->Next;
                temp->Next = newNode;
            }
            temp = temp->Next;
            count++;
        }
    }
}
int main()
{
     //MAKING OBJECT OF LIST
    SingleList list;

    list.InsertDataInEndList(1);
    list.InsertDataInEndList(3);
    list.InsertDataInEndList(2);
    //TAKING CHOICE FROM USER
     char choice ;

        while (choice != 'e')
        {
            cout << "\n----------------------------------------------------\n";
            cout << "a) For Enter Data End of List\nb) For Searching Element in List" << endl;
            cout << "c) For Delete The Element\nd) For Minimum Element" << endl;
            cout << "f) For Maximum Element\ng) Swaap The Element\nh) For Transervse of list" << endl;
            cout << "i) For Sorting the list\nj) For Enter the value at desired location\nk) For Enter data at First Location";
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
                list.InsertDataInEndList(data);
            }
                cout << "\nLimt of list Over\nAll The Element are\t";
                list.Print();
                cout << "\nAll the item of list display" << endl << endl;
                system("pause");
                break;

            case 'b':
            //SERACH THE ELEMENT
                int searchValue;
                cout << "Enter the Element For Search:\t";
                cin >> searchValue;   
                if(list.SearchingNumberInList(searchValue))
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
                if(list.SearchingNumberInList(value))
                {
                    list.DeleteDataFromList(value);
                    cout << "\n Left element are\t";
                    list.Print();
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
                list.MinimumNumberFromList();
                cout << endl;
                system("pause");
                break;


            case 'f':
            //FIND MAXIMUM NUMBER
                list.MaximumNumberFromList();
                cout << endl;
                system("pause");
                break;

            case 'g':
            //SWAPP TWO ELEMENT OF LIST
                int numOne , numTwo;
                cout << "Element Select From List\t";
                list.Print();
                cout << "Select First number:\t";
                cin >> numOne;
                cout << "Select Second number:\t";
                cin >> numTwo;
                list.SwaappTheElement(numOne,numTwo);
                cout << endl;
                list.Print();
                system("pause");
                break;            

            case 'h':
            //TRANSVERSE OF LIST
                cout << "List Elements are ->\t";
                list.TransverseOfList();
                cout << endl;
                system("pause");
                break;

            case 'i':
            //SORTING THE LIST
                cout << "List Element are ->\t";
                list.Print();
                cout << "\nAfter Sorting The Element are ->\t";
                list.SortingTheList();
                system("pause");
                break;  

            case 'j':
            //ADD ELEMENT AT DESIRED LOCATION
                int position;
                int element;
                cout << "Enter the Desired Location:\t";
                cin >> position;         

                cout << "Enter the Value in List:\t";
                cin >> element;

                list.AddElementAtDesiredLocation(element,position);
                list.Print();
                system("pause");
                break;

            case 'k':
                    //ADD ELEMENT AT FIRST LOCATION
                    int val;
                    cout << "Enter data at first location\t";
                    cin >> val;
                    list.AddDataAtFirstLocation(val);
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