#include "linkedlist.h"

LinkedList::LinkedList() { headPtr = nullptr; }

LinkedList::LinkedList(Node *headPtr) { this->headPtr = headPtr; }

void LinkedList::addElement(Website websiteInfo) {
    // Create the new node and set its data
    Node *newNode = new Node;
    newNode->data = websiteInfo;
    newNode->nextPtr = nullptr;

    if (headPtr == nullptr) { // If the list is empty
        headPtr = newNode;      // Set the new node as the head
    } else {
        Node *tempPtr = headPtr;
        while (tempPtr->nextPtr != nullptr) {
            tempPtr = tempPtr->nextPtr; // Traverse to the last node
        }
        tempPtr->nextPtr = newNode; // Add the new node to the end
    }

    listCount++;
}

Website LinkedList::peek() { // return the contents of the front of the list
    // (but do not remove)
    Node *tmp = headPtr;
    return tmp->data;
}

void LinkedList::delElement() {
    if (headPtr == nullptr) { // Checks if a headPtr exists
        cout << "The list is EMPTY!\n";
        return;
    } else { // Deletes headPtr and assigns headPtr's nextPtr to new headPtr
        Node *delNode = headPtr;
        headPtr = headPtr->nextPtr;
        delete delNode;
        delNode = nullptr;
        listCount--;
        return;
    }
}

void LinkedList::printList() {
    Node *tempPtr = headPtr;
    if (tempPtr == nullptr) {
        cout << "\nThe list is empty." << endl;
    }
    while (tempPtr != nullptr) {
        tempPtr->data.print();
        tempPtr = tempPtr->nextPtr;
    }
}

bool LinkedList::listIsEmpty() {
    if (headPtr == nullptr) {
        return true;
    } else {
        return false;
    }
}

void LinkedList::clearList() {
    Node *delNode = headPtr;
    Node *next;
    while (delNode != nullptr) {
        next = delNode->nextPtr;
        free(delNode);
        delNode = next;
    }
    listCount = 0;
    headPtr = nullptr;
}

// Merge Sort Helper Function
Node *LinkedList::mergeSortedLists(Node *left, Node *right) {
    if (!left)
        return right;
    if (!right)
        return left;

    Node *result = nullptr;
    if (Website::sortByDate(left->data, right->data)) {
        result = left;
        result->nextPtr = mergeSortedLists(left->nextPtr, right);
    } else {
        result = right;
        result->nextPtr = mergeSortedLists(left, right->nextPtr);
    }
    return result;
}

// Merge Sort Function
Node *LinkedList::mergeSort(Node *head) {
    if (!head || !head->nextPtr)
        return head;

    // Find the middle of the list
    Node *slow = head;
    Node *fast = head->nextPtr;
    while (fast && fast->nextPtr) {
        slow = slow->nextPtr;
        fast = fast->nextPtr->nextPtr;
    }

    Node *secondHalf = slow->nextPtr;
    slow->nextPtr = nullptr; // Split the list into two halves

    // Recursively sort both halves
    Node *left = mergeSort(head);
    Node *right = mergeSort(secondHalf);

    // Merge the two sorted halves
    return mergeSortedLists(left, right);
}

void LinkedList::sortList() { headPtr = mergeSort(headPtr); }

void LinkedList::sortByNameList() {
    headPtr = mergeSortByName(headPtr);
}

Node* LinkedList::mergeSortByName(Node* head) {
    if (!head || !head->nextPtr)
        return head;

    Node* slow = head;
    Node* fast = head->nextPtr;
    while (fast && fast->nextPtr) {
        slow = slow->nextPtr;
        fast = fast->nextPtr->nextPtr;
    }

    Node* secondHalf = slow->nextPtr;
    slow->nextPtr = nullptr;

    Node* left = mergeSortByName(head);
    Node* right = mergeSortByName(secondHalf);

    return mergeSortedListsByName(left, right);
}

Node* LinkedList::mergeSortedListsByName(Node* left, Node* right) {
    if (!left)
        return right;
    if (!right)
        return left;

    Node* result = nullptr;
    if (Website::sortByName(left->data, right->data)) {
        result = left;
        result->nextPtr = mergeSortedListsByName(left->nextPtr, right);
    } else {
        result = right;
        result->nextPtr = mergeSortedListsByName(left, right->nextPtr);
    }
    return result;
}

LinkedList *LinkedList::archiveList() {
    Node *temp = headPtr; // initializes temp pointer
    Node *newNode = nullptr;
    unordered_map<Node *, Node *> hashMap; // create map to store data
    while (temp != nullptr) {
        newNode = new Node;
        newNode->data = temp->data; // add temp data to newNode
        newNode->nextPtr = temp->nextPtr;
        hashMap[temp] = newNode; // store data in map
        temp = newNode->nextPtr;
    }
    temp = headPtr;
    while (temp != NULL) { // adjust pointers
        newNode = hashMap[temp];
        newNode->nextPtr = hashMap[temp->nextPtr];
        temp = temp->nextPtr;
    }

    return new LinkedList(hashMap[headPtr]); // returned coppied list
}

void LinkedList::exportList() {

    // Get the documents directory path
    QString documentsPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);

    // Append the file name to the directory path
    QString filePath = documentsPath + QDir::separator() + "ExportList.txt";

    // Convert the file path to a standard string
    std::string filePathStr = filePath.toStdString();

    // Open the file for writing
    std::ofstream outFile(filePathStr);

    // Check if the file was opened successfully
    if (!outFile.is_open()) {
        std::cout << "Error: Unable to open the file for writing." << std::endl;
        return;
    }

    // Write data to the file
    Node *temp = headPtr;
    while (temp != nullptr) {
        outFile << temp->data.getName() << std::endl;
        temp = temp->nextPtr;
    }

    // Close the file
    outFile.close();

    std::cout << "\nWebsite History has been successfully exported.\n";
}

void LinkedList::removeElementByData(const QString& data) {
    Node* current = headPtr;
    Node* prev = nullptr;

    // Traverse the list to find the element with matching data
    while (current) {
        // Call the compareData function to check if the data matches
        if (current->data.compareData(data)) {
            // Element found, remove it from the list
            if (prev) {
                prev->nextPtr = current->nextPtr;
                delete current;
            } else {
                // If the element is the first in the list (head)
                headPtr = current->nextPtr;
                delete current;
            }
            return; // Element removed, exit the function
        }

        prev = current;
        current = current->nextPtr;
    }
}
