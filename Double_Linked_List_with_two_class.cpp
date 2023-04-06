#include <iostream>

using namespace std;

// NODE CLASS START
class Node
{
    // PRIVATE PART
private:
    // VARAIBLE
    int data;
    // NODE POINTER
    Node *Next;
    Node *Prev;
    // PUBLIC PART
public:
    // CONSTRUCTOR
    Node();
    // GET DATA FROM USER
    int GetData();
    // GET ADDRESS OF NODE
    Node *GetNext();
    // GET PREVIOUS ADDRESS
    Node *GetPrev();
    // SET THE DATA
    void SetData(int data);
    // SET NODE ADDRESS
    void SetNext(Node *Next);
    // SET PREVIOUS ADDRESS
    void SetPrev(Node *Prev);

}; // END CLASS
// DEFINATION OF NODE CONSTRUCTOR
Node::Node()
{
    Next = NULL;
}

// DEFINATION OF GET DATA
int Node::GetData()
{
    return data;
}
// DEFINATION OF NEXT ADDRESS
Node *Node::GetNext()
{
    return Next;
}
// DEFINATION OF PREVIOUS ADDRESS
Node *Node::GetPrev()
{
    return Prev;
}
// DEFINATION OF SET DATA
void Node ::SetData(int data)
{
    this->data = data;
}
// DEFINATION OF SET NODE ADDRESS
void Node::SetNext(Node *Next)
{
    this->Next = Next;
}
// DEFINATION OF SET PREVIOUS ADDRESS
void Node::SetPrev(Node *Prev)
{
    this->Prev = Prev;
}

// NEXT CLASS LIST
class Double_List
{
    // PRIVATE PART
private:
    // NODE POINTER
    Node *First, *Last;

public:
    // CONSTRUCTOR
    Double_List();
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
// DEFINATION OF CONSTRUCTOR
Double_List::Double_List(/* args */)
{
    First = Last = NULL;
}
// DEFINATION OF INSERT AT END OF LIST
void Double_List::InsertAtEndOfList(int data)
{
    // OBJECT MAKING
    Node *newNode = new Node();
    // ASSIGN DATA
    newNode->SetData(data);
    // CHECKING CONDITION FOR NULL
    if (First == NULL)
    {
        First = Last = newNode;
    }
    else
    {   
        //Insert at last 
        newNode->SetPrev(Last);
        Last->SetNext(newNode);
        Last = newNode;
    }
}
// DEFINATION OF INSERT LIST AT START
void Double_List::InsertAtStart(int data)
{
    // OBJECT MAKING
    Node *newNode = new Node();
    // ASSIGN DATA
    newNode->SetData(data);
    // CHECKING CONDITION FOR NULL
    if (First == NULL)
    {
        First = Last = newNode;
    }
    else
    {
        //insert at first
        newNode->SetNext(First);
        First->SetPrev(newNode);
        First = newNode;
    }
}
// DEFINATION OF PRINT FUNCTION
void Double_List::Print()
{
    // NODE = FIRST
    Node *current = First;
    // CHECKING CONDITION FOR NULL
    if (current == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
            cout << "Element of list are\t";
        // INFINITY LOOP TO GET NULL ADDRESS
        while (current->GetNext() != NULL)
        {
            cout << current->GetData() << "\t";
            current = current->GetNext(); //++
        }
        cout << current->GetData();
        cout << endl;
    }
}
//DEFINATION OF SEARCH THE ELEMENT
bool Double_List::SearchTheElement(int data)
{
    Node * temp = First;
    while (temp != NULL)
    {
        if(temp->GetData() == data)
        {
            return true;
        }
        temp = temp->GetNext();
    }
        return false;
    
}

// DEFINATION OF SORTING LIST
void Double_List::SortingList()
{
    Node *current, *index;
    // NODE = FIRST
    current = First;
    // CHECKING CONDITION FOR NULL
    if (current == NULL)
    {
        cout << "List is Empty" << endl;
    }
    else
    {
        while (current != NULL)
        {
            index = current->GetNext();
            while (index != NULL)
            {
                //Bubble sorting
                if (current->GetData() > index->GetData())
                {
                    int num = current->GetData();
                    current->SetData(index->GetData());
                    index->SetData(num);
                }
                index = index->GetNext();
            }
            current = current->GetNext();
        }
        cout << "Sorted List->\t";
        Print();
    }
}
//DEFINATION OF DELETE AT FIRST
void Double_List::DeleteAtFirst()
{
    Node * temp = First;
    First = First->GetNext();
    int data = temp->GetData();
    delete temp;
    First->SetPrev(NULL);

    cout << data << " Deleted" << endl;
    Print();
}

//DEFINATION OF DELETE AT LAST
void Double_List::DeleteAtLast()
{
    Node * temp = First;
    Node * save ;
    int value;
    while (temp->GetNext() != NULL)
    {
        temp = temp->GetNext();
        value = temp->GetData();
    }
    save = temp->GetPrev();
    save->SetNext(NULL);
    delete temp;
    temp = NULL;
    cout << value << " Deleted" << endl;
    Print();
}


//DEFINATION OF DELETE 
void Double_List::Deleted(int data)
{
    Node * temp = First;
    Node * save;

    while(temp->GetNext() != NULL)
    {
        if(temp->GetData() == data)
        break;
        {
            save = temp;
        }
        temp = temp->GetNext();
    }
    save->SetNext(temp->GetNext());
    temp->GetNext()->SetPrev(save);
    delete temp;
    temp = NULL;
    cout << data << " Deleted" << endl;
    Print();
}

//DEFINATION OF MINIMUM FUNCTION
int Double_List::MinimumValue()
{
    int min = 0;
    Node *temp = First;
    min = temp->GetData();
    while(temp->GetNext() != NULL)
    {
        if(temp->GetData() < min)
        {
            min = temp->GetData();
        }
        temp = temp->GetNext();
    }
    return min;
}

//DEFINATION OF MAXIMUM NUMBER
int Double_List::MaximumValue()
{
    int max = 0;
    Node *temp = First;
    max = temp->GetData();
    while(temp->GetNext() != NULL)
    {
        if(temp->GetData() > max)
        {
            max = temp->GetData();
        }
        temp = temp->GetNext();
    }
    return max;
}
//DEFINATION OF REVERSE LIST
void Double_List::ReverseList()
{
    Node *ptrOne = First;
    Node *ptrTwo = ptrOne->GetNext();
    ptrOne->SetNext(NULL);
    ptrOne->SetPrev(ptrTwo);

    while(ptrTwo != NULL)
    {
        ptrTwo->SetPrev(ptrTwo->GetNext());
        ptrTwo->SetNext(ptrOne);
        ptrOne = ptrTwo;
        ptrTwo = ptrTwo->GetPrev();
    }
    First = ptrOne;
    cout << "Reverse list-->\t";
    Print();
}

int main()
{
     //MAKING OBJECT OF LIST
    Double_List list;

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