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

