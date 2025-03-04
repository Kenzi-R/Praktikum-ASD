#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class LinkedList {
private:
    Node *head;

public:
    LinkedList() : head(NULL) {}

    void insertFirst(int value) {
        Node* newNode = new Node();  
        newNode->data = value;       
        newNode->next = head;       
        head = newNode;             
    }

    void insertLast(int value) {
        Node* newNode = new Node();  
        newNode->data = value;       
        newNode->next = NULL;        

        if (!head) { 
            head = newNode; 
            return; 
        } 

        Node* temp = head; 
        while (temp->next)  
            temp = temp->next; 

        temp->next = newNode; 
    }

    void insertAt(int value, int pos) {
        if (pos < 1) {
            cout << "Position should be >= 1.\n";
            return;
        }

        if (pos == 1) {
            insertFirst(value);
            return;
        }

        Node* newNode = new Node();  
        newNode->data = value;      

        Node* temp = head; 
        for (int i = 1; i < pos - 1 && temp; i++) 
            temp = temp->next; 

        if (!temp) { 
            cout << "Position out of range.\n";
            delete newNode; 
            return; 
        }

        newNode->next = temp->next; 
        temp->next = newNode; 
    }

    void deleteFirst() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;  
        head = head->next;  
        delete temp;       
    }

    void deleteLast() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        if (!head->next) {
            delete head;    
            head = NULL;    
            return;
        }

        Node* temp = head; 
        while (temp->next->next) 
            temp = temp->next; 

        delete temp->next;  
        temp->next = NULL;  
    }

    void deleteAt(int pos) {
        if (pos < 1) {
            cout << "Position should be >= 1.\n";
            return;
        }

        if (pos == 1) {
            deleteFirst();
            return;
        }

        Node* temp = head; 
        for (int i = 1; i < pos - 1 && temp; i++) 
            temp = temp->next; 

        if (!temp || !temp->next) { 
            cout << "Position out of range.\n";
            return;
        }

        Node* nodeToDelete = temp->next;  
        temp->next = temp->next->next;    
        delete nodeToDelete;             
    }

    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head; 
        while (temp) { 
            cout << temp->data << " -> ";  
            temp = temp->next; 
        }

        cout << "NULL\n";  
    }

    void searchData(int data) {
        Node* temp = head;
        if (!head) { // Cek apakah list kosong
            cout << "List is empty\n";
            return;
        }
        while (temp) {
            if(temp->data == data) {
                cout << data << " is present in the linked list.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "No node in the linked list has the value " << data << ".\n";
    }
};

int main() {
    LinkedList list1;

    list1.insertLast(10);
    list1.insertLast(20);
    list1.insertFirst(5);
    list1.insertAt(15, 3);
    cout << "Linked list after insertions: ";
    list1.display();
    cout<<"Masukkan nilai yang ingin dicari:";
    int data;cin>>data;
    list1.searchData(data);
    return 0;
}