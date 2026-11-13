#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() { head = nullptr; }

    // 1. Insertion (At the end)
    void insertNode(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) temp = temp->next;
            temp->next = newNode;
        }
        cout << value << " inserted into Linked List." << endl;
    }

    // 2. Deletion (By value)
    void deleteNode(int value) {
        if (head == nullptr) return;
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << value << " deleted." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }
        if (temp->next != nullptr) {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
            cout << value << " deleted." << endl;
        } else {
            cout << value << " not found to delete." << endl;
        }
    }

    // 3. Search
    bool search(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) return true;
            temp = temp->next;
        }
        return false;
    }

    // 4. Traversal
    void display() {
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;
    list.insertNode(10); 
    list.insertNode(20); 
    list.insertNode(30);
    list.display();
    cout << "Search for 20: " << (list.search(20) ? "Found" : "Not Found") << endl;
    list.deleteNode(20);
    list.display();
    return 0;
}