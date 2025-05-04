// Code for Lab8 - Q2
//Program to implement tree data structure
#include<iostream>
using namespace std;

class tree {
    struct node {
        char data;
        struct node* left;
        struct node* right;
    };

public:
    struct node* head;
    
    tree() {
        head = NULL;
    }

    void insert(char let);
    void preorder(struct node* head);
    void postorder(struct node* head);
    void inorder(struct node* head);
};

int main() {
    tree l1;
    int choice;
    char let;
    
    do {
        cout << "Enter the choice:\n1.Insert\n2.Inorder traversal\n3.Preorder traversal\n4.Postorder traversal\n5.Exit\nchoice: ";
        cin >> choice;
        cout << endl;
        
        switch (choice) {
            case 1:
                cout << "Enter the character to be inserted: ";
                cin >> let;
                l1.insert(let);
                break;

            case 2:
                l1.inorder(l1.head);
                cout << endl;
                break;

            case 3:
                l1.preorder(l1.head);
                cout << endl;
                break;

            case 4:
                l1.postorder(l1.head);
                cout << endl;
                break;

            case 5:
                cout << "Exiting.....\n";
                break;
        }
    } while (choice != 5);

    return 0;
}

// Level-order insertion
void tree::insert(char let) {
    node* newnode = new node();
    struct node* temp = head;
    newnode->data = let;
    newnode->left = NULL;
    newnode->right = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    while (temp) {
        if (temp->left == NULL) {
            temp->left = newnode;
            return;
        }
        if (temp->right == NULL) {
            temp->right = newnode;
            return;
        }
        temp = temp->left;
    }
}

// Left-root-right traversal
void tree::inorder(struct node* head) {
    if (head == NULL) {
        return;
    }
    inorder(head->left);
    cout << head->data;
    inorder(head->right);
}

// Root-left-right traversal
void tree::preorder(struct node* head) {
    if (head == NULL) {
        return;
    }
    cout << head->data;
    preorder(head->left);
    preorder(head->right);
}

// Left-right-root traversal
void tree::postorder(struct node* head) {
    if (head == NULL) {
        return;
    }
    postorder(head->left);
    postorder(head->right);
    cout << head->data;
}
