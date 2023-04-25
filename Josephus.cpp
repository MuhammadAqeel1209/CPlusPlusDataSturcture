#include <iostream>
using namespace std;
//CLASS START
class CircularList
{
    //PRIVATE PART
private:
    //VARAIBLES
    int data;
    //POINTERS
    CircularList *next;
    CircularList *head;
    CircularList *currentLoc;
//PUBLIC PART
public:
    //CONSTRUCTOR
    CircularList();
    //INSERT NODE
    void InsertNode(int data);
    //JOSPHEUS METHOD
    int JospheousPro();
    //PRINT NODE
    void printdata();
};
//CALLING CONSTRUCTOR
CircularList::CircularList()
{
    head = NULL;
    currentLoc = NULL;
}
//DEFINATION OF INSERT NODE
void CircularList::InsertNode(int data)
{
    CircularList *newNode = new CircularList();
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        newNode->next = newNode;
        currentLoc = head;
        return;
    }
    currentLoc->next = newNode;
    currentLoc = currentLoc->next;
    currentLoc->next = head;
}
//DEFINATION OF JOSPHEOUS
int CircularList::JospheousPro()
{
    int delValue;
    currentLoc = head;
    CircularList *delPtr = head->next;
    while (head->next != head)
    {
        for (int i = 1; i < 2; i++)
        {
            currentLoc = currentLoc->next;
            delPtr = delPtr->next;
        }
        currentLoc->next = delPtr->next;
        if (delPtr == head) // if delptr == head mov head to next node
            head = head->next;
        delValue = delPtr->data; // store deleted value in delvalue
        delete delPtr;
        currentLoc = currentLoc->next;
        delPtr = currentLoc->next;
        cout << delValue << "\t << Deleted \n";
    } 
    cout << "Leaders is:\t";
    return head->data;
}
//DEFINATION OF PRINT DATA
void CircularList::printdata()
{
    currentLoc = head;
    do
    {
        cout << "-->" << currentLoc->data;
        currentLoc = currentLoc->next;
    } while (currentLoc != head);
    cout << "-->head\n";
}

int main()
{
    CircularList list;
    list.InsertNode(1);
    list.InsertNode(2);
    list.InsertNode(3);
    list.InsertNode(4);
    list.InsertNode(5);
    list.InsertNode(6);
    list.InsertNode(7);
    list.InsertNode(8);
    list.InsertNode(9);
    list.InsertNode(10);
    list.printdata();
    cout << list.JospheousPro();
}