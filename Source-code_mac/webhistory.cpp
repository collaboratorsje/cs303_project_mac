#include "webhistory.h"
#include "ui_webhistory.h"

webHistory::webHistory(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::webHistory)
{
    ui->setupUi(this);

    myList = LinkedList();
}

webHistory::~webHistory()
{
    delete ui;
}

// Add button
void webHistory::on_pushButton_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, "Enter Text", "Please enter some text:", QLineEdit::Normal, "", &ok);

    if (ok && !text.isEmpty()) {
        std::string url = text.toStdString();

        // Get the current day, month, and year
        std::time_t currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::tm* currentDateTime = std::localtime(&currentTime);
        int day = currentDateTime->tm_mday;
        int month = currentDateTime->tm_mon + 1;
        int year = currentDateTime->tm_year + 1900;
        int seconds = currentDateTime->tm_sec;
        int minutes = currentDateTime->tm_min;


        // Create a new Website object
        Website newWebsite(url, year, month, day, minutes, seconds);

        // Add the Website object to your LinkedList
        myList.addElement(newWebsite);

        // Display the URL in the list widget
        ui->listWidget->addItem(text);
    }
    myList.printList();
}

// Remove button - Clicking remove with item selected
void webHistory::on_pushButton_2_clicked()
{
    // Get the selected item in the QListWidget
    QListWidgetItem* selectedItem = ui->listWidget->currentItem();

    if (selectedItem) {
        // Get the item's text (assuming the item's text is the same as the data in your linked list)
        QString data = selectedItem->text();

        // Remove the selected item from the QListWidget
        ui->listWidget->takeItem(ui->listWidget->row(selectedItem));

        // Optionally, you can also delete the item to free memory
        delete selectedItem;

        // Now remove the corresponding data from the linked list
        myList.removeElementByData(data);

        myList.printList();
    }

}

// Sort (Date)
void webHistory::on_pushButton_4_clicked()
{
    myList.sortList();

    // Clear the QListWidget
    ui->listWidget->clear();

    // Traverse the linked list and add items to the QListWidget in the current order
    Node* current = myList.getHeadPtr();
    while (current) {
        ui->listWidget->addItem(QString::fromStdString(current->data.getName()));
        current = current->nextPtr;
    }

}

// Sort A-Z
void webHistory::on_pushButton_7_clicked()
{
    myList.sortByNameList();

    // Clear the QListWidget
    ui->listWidget->clear();

    // Traverse the linked list and add items to the QListWidget in the current order
    Node* current = myList.getHeadPtr();
    while (current) {
        ui->listWidget->addItem(QString::fromStdString(current->data.getName()));
        current = current->nextPtr;
    }
}

// Export button
void webHistory::on_pushButton_6_clicked()
{
    myList.exportList();
}

// Archive button
void webHistory::on_pushButton_5_clicked()
{
    // Call the archiveList() function to get the archived data in a new LinkedList
    LinkedList* archivedList = myList.archiveList();

    // Clear the listWidget_2 before adding new items
    ui->listWidget_2->clear();

    // Iterate over the archived list and add each item to listWidget_2
    Node* temp = archivedList->getHeadPtr();
    while (temp != nullptr) {
        ui->listWidget_2->addItem(QString::fromStdString(temp->data.getName()));
        temp = temp->nextPtr;
    }

    // Clean up the memory used by the archivedList
    delete archivedList;
}

