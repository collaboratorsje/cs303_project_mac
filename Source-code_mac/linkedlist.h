#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <QCoreApplication>
#include <QDir>
#include <QStandardPaths>

#include "website.h"

using namespace std;
// creates the node made from a website object and a pointer to the next node
struct Node {
    Website data;
    Node *nextPtr;
};
// defines the linkedlist with private data member the headptr and some merge sort helper functions and merge sort functions
class LinkedList {
private:
    Node *headPtr;

    // Merge Sort Helper Function by date
    Node* mergeSortedLists(Node* left, Node* right);
    // Merge Sort Helper Function by name
    Node* mergeSortedListsByName(Node* left, Node* right);

    // Merge Sort Function by date
    Node* mergeSort(Node* head);
    // Merge Sort Function by name
    Node* mergeSortByName(Node* head);

public:
    // declares the linked list class functions
    LinkedList();
    LinkedList(Node *headPtr);
    void addElement(Website);
    Website peek();
    void delElement();
    void printList();
    bool listIsEmpty();
    void clearList();
    int listCount = 0;
    void sortList();
    void sortByNameList();
    LinkedList* archiveList();
    void exportList();

    // Declare the function to remove an element with specific data from the linked list
    void removeElementByData(const QString& data);

    // Function to get the headPtr
    Node* getHeadPtr() const { return headPtr; }
};
