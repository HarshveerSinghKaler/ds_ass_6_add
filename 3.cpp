#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
Node* reverseInGroups(Node* head, int k) {
    if (!head || k <= 1)
        return head;
    Node* curr = head;
    Node* next = NULL;
    Node* prev = NULL;
    int count = 0;
    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        curr->prev = next;

        prev = curr;
        curr = next;
        count++;
    }
    if (next != NULL) {
        head->next = reverseInGroups(next, k);
        if (head->next)
            head->next->prev = head;
    }

    return prev;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next)
            cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}

void push(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head)
        head = newNode;
    else {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

int main() {
    Node* head = NULL;
    for (int i = 1; i <= 6; i++)
        push(head, i);
    cout << "Original list: "<<endl;
    printList(head);
    int k = 2;
    head = reverseInGroups(head, k);
    cout << "Reversed in groups of " << k <<endl;
    printList(head);
    return 0;
}