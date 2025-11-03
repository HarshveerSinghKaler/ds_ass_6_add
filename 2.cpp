#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node(int val) {
        this -> val = val;
        this -> next = NULL;
    } 
};

int getparity(int n) {
    int count = 0;
    while (n) {
        if (n & 1) {
            count++;
        }
        n = n >> 1;
    }

    return count;
}

void removeEvenParity(Node* &head) {
    if (head == NULL) {
        return;
    }

    Node* curr = head;
    Node* prev = NULL;
    
    do {
        int parity = getparity(curr -> val);
        
        if (parity % 2 == 0) {
            if (curr == head) {
                Node* temp = head;
                
                while (temp-> next != head) {
                    temp = temp -> next;
                }
                
                if (head -> next == head) {
                    delete head;
                    head = NULL;
                    return;
                }
                
                temp -> next = head -> next;
                
                Node* toDelete = head;
                
                head = head -> next;
                curr = head;
                delete toDelete;
                prev = temp;
            } else {
                prev -> next = curr -> next;
                Node* toDelete = curr;
                curr = curr -> next;
                delete toDelete;
            }
        } else {
            prev = curr;
            curr = curr -> next;
        }
    } while (curr!=head);
}