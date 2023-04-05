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
    Node *NextAddress;
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
    void SetNext(Node* NextAddress);

};//END CLASS
//DEFINATION OF NODE CONSTRUCTOR
Node::Node()
{
    NextAddress = NULL;
}

//DEFINATION OF GET DATA
int Node::GetData()
{
    return data;
}
//DEFINATION OF NODE ADDRESS
Node* Node::GetNext()
{
    return NextAddress;
}
//DEFINATION OF SET DATA
void Node ::SetData(int data)
{
    this->data = data;
}
//DEFINATION OF SET NODE ADDRESS
void Node::SetNext(Node * NextAddress)
{
    this->NextAddress = NextAddress;
}


//NEXT CLASS LIST START
class  List
{
    //PRIVATE PART
private:
    // CURRENT LOCATION NODE
    Node *Head;
    //FIRST LOCATION NODE
    Node *first;
public:
    //CONSTRUCTOR
     List();
    //PRINT FUNCTION 
    void Print();
    //INSERT DATA FUNCTION
    void InsertDataInEndList(int data);
    //DELETE DATA FUNCTION
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
    //ADD ELEMENT IN BEFORE
    void AddElementInAfter(int index,int data);
    //ADD ELEMENT AT DESIRED LOCATION
    void AddElementAtDesiredLocation(int data,int position);
    //ADD DATA FIRST LOCATION
    void AddDataAtFirstLocation(int data);


};//END CLASS

//DEFINATION OF CONSTRUCTOR
 List:: List()
{
    Head = NULL;
}

//DEFINATION OF ADD DATA AT FIRST LOCATION
void List::AddDataAtFirstLocation(int data)
{
    //Making new object
    Node * Data = new Node();
    //ASSIGN VALUE OR ADDRESS
    Data->SetData(data);
    Data->SetNext(Head);
    Head = Data;
}

//DEFINATION OF ADD ELEMENT AT DESIRD LOCATION
void List::AddElementAtDesiredLocation(int data,int position)
{
    //NEW OBJECT
    Node *temp = new Node();
    //ASSIGN VALUE
    temp->SetData(data);    
    //CHECKING CONDITION FOR NULL
    if(Head == NULL)
    {
        Head = temp;
        return;
    }

    //MAKING NODE AND ASSIGN DEFAULT LOCATION
    Node *Visit = Head;
    int count = 0;
    //INFINITY LOOP TO NULL THE ADDRESS OF NODE
    while(Visit != NULL)
    {
        //TEST THE CONDITION
        if(count == position -1)
        {
            //SET ADDRESS TO TEMP(NEW) FROM VISIT(DEFAULT)->NEXT ADDRESS
            temp->SetNext( Visit->GetNext());
            Visit->SetNext(temp);
        }
        //++ ADDRESS
        Visit = Visit->GetNext();
        count++;
    }
    
}

//DEFINATION OF ADD AFTER ELEMENT
void List::AddElementInAfter(int index,int data)
{
    //TEMP NODE
    Node *temp = Head;
    //NEW INSTANCE CREATE
    Node *NewData = new Node();
    //SET DATA
    NewData ->SetData(data);

    //INFINITY LOOP TO GET INDEX
    while (temp->GetData() != index)
    {
        //++
        temp = temp ->GetNext();
    }
    //NEW DATA SET ADDRESS WHICH GET BY TEMP
    NewData->SetNext(temp->GetNext());
    //SET NEXT ADDRESS TO NEW DATA 
    temp->SetNext(NewData);
}


//DEFINATION OF SWAPP FUNCTION
void List::SwaappTheElement(int numOne,int numTwo)
{
    //NODE = DEFAULT 
    Node *temp = Head;
    //INFINITY LOOP TO GET NULL ADDRESS
    while (temp != NULL)
    {
        //GET VALUE
        if(temp->GetData() == numOne)
        {
            //ASSIGN VALUE
            temp->SetData(numTwo);
        }
        //GET ANOTHER VALUE
        else if(temp->GetData() == numTwo)
        {
            //ASSIGN THE VALUE
            temp->SetData(numOne);
        }
        //++
        temp = temp ->GetNext();
    }
}

//DEFINATION OF MAXIMUM NUMBER
void List::MaximumNumberFromList()
{
    //VARAIBLE
    int max = 0;
    //NODE = DEFAULT
    Node *temp = Head;
    //GET DATA
    max = temp->GetData();
    //INFINITY LOOP TO GET NULL ADDRESS
    while(temp != NULL)
    {
        //CHECK CONDITI FOR MAXIMUM
        if(temp->GetData() > max)
        {
            //STORE VALUE TO MAX VARAIBLE
            max = temp ->GetData();
        }
        //++;
        temp = temp->GetNext();
    }
    cout << "Maximum Number is:\t" << max << endl;

}
//DEFINATION OF MINIMUM NUMBER
void List::MinimumNumberFromList()
{
    

    //NODE = DEFAULT
    Node *temp = Head;
    //GET DATA
    //VARAIBLE
    int min = temp->GetData();
    //INFINITY LOOP TO GET NULL ADDRESS
    while(temp != NULL)
    {
        //CHECK CONDITION FOR MINIMUM
        if(temp->GetData() < min)
        {
            //STORE VALUE TO MIN VARAIBLE
            min = temp ->GetData();
        }
        //++;
        temp = temp->GetNext();
    }
    cout << "Minimum Number is :\t" << min << endl ;
}

//DEFINATION OF SORTING LIST
void List::SortingTheList()
{
    //NODE = DEFAULT
    Node *temp = Head;
    //NODE = NULL
    Node *current = NULL;
    int number;
    //CHECKING CONDITON FOR NULL
    if(temp == NULL)
    {
    }
    else
    {
        //INFINITY LOOP FOR GET NULL ADDRESS
        while (temp != NULL )
        {
            //GET VALUE
            current = temp->GetNext();
            //INFINITY LOOP FOR GET NULL ADDRESS
            while(current != NULL)
            {
                //COMPARE BOTH VALUE
                if(temp->GetData() > current->GetData())
                {
                    //SWAPPS THE VALUE
                    number = temp->GetData();
                    temp->SetData(current->GetData()); 
                    current->SetData(number) ;
                }//++
                 current = current->GetNext();
            }//++
            temp = temp->GetNext();
        }
    }
    Print();
}

//DEFINATION OF SEARCH FUNCTION
bool List::SearchingNumberInList(int data)
{
    //NODE = DEFAULT
    Node *temp = Head;
    //INFINITY LOOP TO GET NULL ADDRESS
    while (temp != NULL)
    {
        //CHECKING THE DATA 
        if(temp->GetData() == data)
        {
            //TRUE CONDITION
            return true;
        }//++
        temp = temp ->GetNext();
    }
    //FALSE CONDITION
    return false;
}

//DEFINATION OF INSERT DATA IN END OF LIST
void List::InsertDataInEndList(int data)
{
    //CREATE A NEW NODE OBJECT
    Node *node = new Node();
    //ASSIGN DATA 
    node ->SetData(data);
    //CREATE A TEMP NODE
    Node *temp = Head;

    // CHECKING THE CONDITION OF NODE NULL OR NOT
    if(temp != NULL)
    {
        //WHILE INFINITY LOOP UNTIL NOOD IS NULL
        while (temp->GetNext() != NULL)
        {
            temp = temp ->GetNext();
            
        }

        //GIVE THE NEW NODE TO LAST
        temp->SetNext(node);
    }
    else
    {
        // NODE TO DEFAULT LOCATION
        Head = node;
    }
}

//DEFINATION OF TRANVERSE FUNCTION
void List::TransverseOfList()
{
    Node *temp = Head;
    while(temp != NULL)
    {
        cout << temp->GetData() << "\t";
        temp = temp ->GetNext();
    }
}

//DEFINATION OF PRINT FUNCTION
void List::Print()
{
    //TEMP NODE POINTER
    Node *temp = Head;

    //CASE 1:EMPTY LIST
    if(temp == NULL)
    {
        cout << "\nLIST IS EMPTY" << endl << endl;
    }
    //CASE 2:MORE THAN ONE NODE
    else
    {
        //INFINITY LOOP UNTIL THE ADDRESS OF NODE NULL
        while (temp != NULL)
        {
            cout << temp->GetData() << "\t";
           temp = temp->GetNext(); 
        }
            cout << endl;
    }
}

//DEFINATION OF DELETE 
void List :: DeleteDataFromList(int data)
{
    // TEMP POINTER
    Node *temp = Head;

    //CASE 1:NO NODE
    if(temp == NULL)
    {

    }
    //CASE 2 MORE THAN ONE NODE
    else
    {
        Node * Pervious;
        //INFITY LOOP
        while(temp != NULL)
        {
            if(temp ->GetData() == data)
            break;
            {
                Pervious = temp;
                temp = temp ->GetNext();
            }
        }

        Pervious->SetNext(temp->GetNext());
        delete temp;
        //temp = NULL;
        cout << "\nElement is Deleted" << endl;
    }
}


int main()
{
    //MAKING OBJECT OF LIST
    List list;

    list.InsertDataInEndList(1);
    list.InsertDataInEndList(3);
    list.InsertDataInEndList(2);
    //TAKING CHOICE FROM USER
     char choice ;

        while (choice != 'e')
        {
            cout << "\n----------------------------------------------------\n";
            cout << "a) For Enter Data End of List\nc) For Enter data Before Some Index" << endl;
            cout << "d) For Searching Element in List\nf) For Delete The Element\ng) For Minimum Element" << endl;
            cout << "h) For Maximum Element\ni) Swaap The Element\nj) For Transervse of list" << endl;
            cout << "k) For Sorting the list\nl) For Enter the value at desired location\nm) For Enter data at First Location";
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


            case 'c':
            //ENTER ELEMENT ON DIFFERENT INDEX
                int vale , index;
                cout << "Enter the Element After Of Index:\t";
                cin >> vale;
                cout << "Select Index -->\t";
                list.Print();
                cin >> index;
                if(list.SearchingNumberInList(index))
                {
                list.AddElementInAfter(index,vale);
                list.Print();
                cout << endl;
                }
                else
                {
                    cout << "Not Index Match!!" << endl;
                }
                system("pause");
                break;

            case 'd':
            //SERACH THE ELEMENT
                int searchValue;
                cout << "Enter the Element For Search:\t";
                cin >> searchValue;   
                if(list.SearchingNumberInList(searchValue))
                {
                    cout << "Value Exist:\t" << searchValue;
                }
                else
                {
                    cout << "Value not Exist:\t" << searchValue;
                }
                system("pause");
                break;

            case 'f':
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

            case 'g':
            //FINF MINIMUM NUMBER
                list.MinimumNumberFromList();
                cout << endl;
                system("pause");
                break;


            case 'h':
            //FIND MAXIMUM NUMBER
                list.MaximumNumberFromList();
                cout << endl;
                system("pause");
                break;

            case 'i':
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

            case 'j':
            //TRANSVERSE OF LIST
                cout << "List Elements are ->\t";
                list.TransverseOfList();
                cout << endl;
                system("pause");
                break; 
            case 'k':
            //SORTING THE LIST
                cout << "List Element are ->\t";
                list.Print();
                cout << "\nAfter Sorting The Element are ->\t";
                list.SortingTheList();
                system("pause");
                break;  

            case 'l':
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

            case 'm':
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


    // // Making Object
    // Node n1,n2,n3,n4,n5;
    // // SET DATA TO EVERY NODE
    // n1.SetData(10);
    // n2.SetData(20);
    // n3.SetData(30);
    // n4.SetData(40);
    // n5.SetData(50);

    // //SET ADDRESS TO EVERY NODE
    // n1.SetNext(&n2);
    // n2.SetNext(&n3);
    // n3.SetNext(&n4);
    // n4.SetNext(&n5);
    // n5.SetNext(NULL);

    // //DISPLAY THE NODE DATA 
    // cout << "NODE VALUES ARE:\t\t" << n1.GetData() << "\t\t" << n2.GetData() << "\t\t" << n3.GetData() << "\t\t" << n4.GetData() << "\t\t"<< n5.GetData() << endl << endl;

    // //DISPLAY THE NODE ADDRESS
    // cout << "NODE ADDRESS ARE:\t\t"  << n1.GetNext() << "\t" << n2.GetNext() << "\t" << n3.GetNext() << "\t" << n4.GetNext() << "\t" << n5.GetNext() << endl << endl;

}