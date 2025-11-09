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
void correctPointer(Node* head) {
    if (!head) return;
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    if (fast==NULL || fast->next==NULL) {
        return;
    }
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    Node* loopStart = slow;
    Node* temp = loopStart;
    while (temp->next != loopStart) {
        temp = temp->next;
    }
    temp->next = NULL;
    loopStart->prev = temp;
}
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = NULL;
    head->prev = NULL;
    correctPointer(head);

    cout << "After correction:" << endl;
    printList(head);

    return 0;
}