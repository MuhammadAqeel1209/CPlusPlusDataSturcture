#include <iostream>
using namespace std;
class Node
{
    //PRIVATE PART
private:
    //VARAIBLES
    int data;      // data part
    //POINTER
    Node *next; // next of next node
    Node *head;    // head location of link list
    //PUBLIC PART
public:
    Node()
    { // default constructor
        head = NULL;
    }
    void InsertAtBegin(int data)
    {
        Node *headNode = new Node();
        headNode->data = data;
        headNode->next = NULL;
        Node *visitNode = head;
        while (visitNode->next != head)
        {
            visitNode = visitNode->next;
        }
        visitNode->next = headNode; // NEW NODE IS HEAD NOW
        headNode->next = head;
        head = headNode;
    }
    void InsertdataAtEnd(int data)
    {
        Node *NewNode = new Node();
        NewNode->data = data;
        NewNode->next = NULL;
        if (head == NULL)
        {
            head = NewNode; // newNode is boss/head now
            head->next = head;
            return;
        }
        Node *visitNode = head;
        while (visitNode->next != head) // circular list--->every last node is  connected to first node
        {
            visitNode = visitNode->next;
        }
        visitNode->next = NewNode;
        NewNode->next = head;
    }
    void Display()
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }
        Node *printNode = head; // visit all the list to print data
        do
        {
            cout << "-->" << printNode->data;
            printNode = printNode->next;
        } while (printNode != head);
        cout << "-->Head\n";
    }
};

int main()
{
    Node node;
    node.InsertdataAtEnd(20);
    node.InsertdataAtEnd(30);
    node.InsertdataAtEnd(40);
    node.InsertdataAtEnd(40);
    node.InsertdataAtEnd(40);
    node.InsertdataAtEnd(40);
    node.InsertdataAtEnd(40);
    node.InsertdataAtEnd(40);
    node.InsertdataAtEnd(40);
    node.InsertdataAtEnd(40);
    node.InsertdataAtEnd(40);
    node.InsertdataAtEnd(40);
    node.InsertdataAtEnd(40);
    node.InsertdataAtEnd(40);
    node.InsertdataAtEnd(40);
    node.InsertAtBegin(10);
    node.InsertAtBegin(9);
    node.InsertAtBegin(8);
    node.InsertAtBegin(7);
    node.Display();
}