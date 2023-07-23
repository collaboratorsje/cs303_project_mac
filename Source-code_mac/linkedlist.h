#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <QCoreApplication>
#include <QDir>
#include <QStandardPaths>

#include "website.h"

using namespace std;

struct Node {
    Website data;
    Node *nextPtr;
};

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
