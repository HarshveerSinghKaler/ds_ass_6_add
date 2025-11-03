#include <iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node(int val) {
            this -> val = val;
            this-> next = NULL;
        }
};

int getlength(Node* head) {
    int length = 0;
    Node* temp = head;
    do {
        length++;
        temp = temp -> next;
    } while (temp!=head);

    return length;
} 

Node* split(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;
    
    while (fast-> next != head && fast -> next -> next != head) {
        slow = slow -> next;
        fast = fast -> next -> next;
    
    }
    
    if (fast-> next -> next == head) {
        fast = fast -> next;
    }
    
    Node* head1 = head;
    Node* head2 = slow -> next;
    
    fast -> next = head2;
    slow -> next = head1;

    return head1;
}