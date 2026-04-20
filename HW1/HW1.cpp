#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

struct Node {
      int data;
      Node* next;
};

Node* add_node(int data) {
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;
    return new_node;
}

Node* insert_node(Node* head, int new_data) {
    Node* new_node = add_node(new_data);

    if (head == nullptr || new_data < head->data) {
        new_node->next = head;
        return new_node;
    }

    Node* cur = head;
    while (cur->next != nullptr && cur->next->data <= new_data) {
        cur = cur->next;
    }

    new_node->next = cur->next;
    cur->next = new_node;
    return head;
}

Node* delete_node(Node* head, int old_data) {
    while (head != nullptr && head->data == old_data) {
        Node* del = head;
        head = head->next;
        delete del;
    }

    Node* cur = head;
    while (cur != nullptr && cur->next != nullptr) {
        if (cur->next->data == old_data) {
            Node* del = cur->next;
            cur->next = cur->next->next;
            delete del;
        } else {
            cur = cur->next;
        }
    }

    return head;
}

void print_list(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

Node *insertIntoSortedList(Node* head_ref, int new_data) {
  return insert_node(head_ref, new_data);
}

Node *DeletFromSortedList(Node* head_ref, int old_data) {
  return delete_node(head_ref, old_data);
}


int main() {
    struct Node* head = NULL;
    string aStr;
    int aInt;
    
    while (aStr != "x" && aStr != "X") {
    
        cout << "Input or Delete? ";
        cin >> aStr;
        
        if (aStr == "i" || aStr == "I") {
            cout << "Input an integer? ";
            cin >> aInt;
            head = insert_node(head, aInt);
            print_list(head);
        }
        else if (aStr == "d" || aStr == "D") {
            cout << "Input an integer? ";
            cin >> aInt;
            head = delete_node(head, aInt);
            print_list(head);
        }
    }

    while (head != nullptr) {
        Node* del = head;
        head = head->next;
        delete del;
    }
}
