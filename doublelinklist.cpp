#include <iostream>
#include <string>
using namespace std;

class Node
{
public :
    int noMhs;
    Node *next;
    Node *prev;
};

class DoubleLinkedList
{
private:
    Node *START;
public:
    DoubleLinkedList()
    {
        START = NULL;
    }
    void addNode()
    {
        int nim;
        cout << "Enter the roll number of the student: ";
        cin >> nim;

        Node *newnode = new Node;
        newnode->noMhs = nim;

        if (START == NULL || nim <= START->noMhs)
    {
            if (START != NULL && nim == START->noMhs)
        {
            cout << "Duplicat numbers not allowed" << endl;
            return;
        }

        newnode->next = START;

        if (START != NULL)
            START->prev = newnode;

        newnode->prev = NULL;
        START = newnode;
        return;
    }

    Node *current = START;

    while (current->next != NULL && current->next->noMhs < nim)
    {
        current = current->next;
    }
    if (current->next != NULL && nim == current->next->noMhs)
    {
        cout << "Duplicate roll numbers not allowed" << endl;
        return;
    }

    newnode->next = current->next;
    newnode->prev = current;

    if (current->next != NULL)
        current->next->prev = newnode;

    current->next = newnode;
    }

    void hapus()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl; 
            return;
        }

    cout << "\nEnter the roll number of the student whose record is to be deleted: ";
    int rollNo;
    cin >> rollNo;

    Node *current = START;

        while (current != NULL && current->noMhs != rollNo)
            current = current->next;
    
        if (current == NULL)
        {
        cout << "Record not found" << endl;
        return;
        }   

        if (current == START)
        {
        START = current->next;
        if (START != NULL)
            START->prev = NULL;
        }
        else
        {
        current->prev->next = current->next;

        if(current->next != NULL)
            current->next->prev = current->prev;
        }

     delete current;
    cout << "Record with roll number " << rollNo << " deleted" << endl;
    }

    void traverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

    Node *currentNode = START;

    cout << "\nRecords in ascesnding order of roll number are:\n";
    int i = 0;
    while (currentNode != NULL)
        {
            cout << i + 1 << ". " << currentNode->noMhs << " " << endl;
            currentNode = currentNode->next;
            i++;
        }
    }

    void retraverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        Node *currentNode = START;
        int i = 0;
        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
            i++;
        }

        cout << "\nRecords in descending order of roll number are:\n";
        while (currentNode != NULL)
        {
            cout << i + 1 << " . " << currentNode->noMhs << " " << endl;

            currentNode = currentNode ->prev;
            i--;
        }
    }

    

   