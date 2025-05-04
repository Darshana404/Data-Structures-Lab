// Code for Lab11 - Q3
#include <iostream>
using namespace std;

#define size 10

class Node {
public:
    int key;
    Node* next;
    Node(int k) : key(k), next(nullptr) {}
};

class HashTable {
private:
    Node* table[size];

    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTable() {
        for (int i = 0; i < size; i++) {
            table[i] = nullptr;
        }
    }

    void insert(int key) {
        int index = hashFunction(key);
        Node* newNode = new Node(key);
        newNode->next = table[index];
        table[index] = newNode;
    }

    void search(int key) {
        int index = hashFunction(key);
        Node* temp = table[index];
        while (temp != nullptr) {
            if (temp->key == key) {
                return;
            }
            temp = temp->next;
        }
    }

    void remove(int key) {
        int index = hashFunction(key);
        Node* temp = table[index];
        Node* prev = nullptr;
        while (temp != nullptr) {
            if (temp->key == key) {
                if (prev == nullptr) {
                    table[index] = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            Node* temp = table[i];
            cout << "Index " << i << ": ";
            if (temp == nullptr) {
                cout << "EMPTY";
            } else {
                while (temp != nullptr) {
                    cout << temp->key << " -> ";
                    temp = temp->next;
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;
    int choice,num;
    while(1)
    {
        cout<<"1-Insert\n2-Delete\n3-Search\n4-Display\n5-Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter the number to be inserted: ";
                cin>>num;
                ht.insert(num);
                break;
            case 2:
                cout<<"Enter the number to be deleted: ";
                cin>>num;
                ht.remove(num);
                break;
            case 3:
                cout<<"Enter the number to be searched: ";
                cin>>num;
                ht.search(num);
                break;
            case 4:
                ht.display();
                break;
            case 5:
                return(0);
            default:
                cout<<"Enter a valid choice"<<endl;
        }
    }
}
