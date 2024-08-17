#include <bits/stdc++.h>
using namespace std;

// A linked list node
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize a new node with data
    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

// Function to sort a linked list of 0s, 1s and 2s
void sortList(Node* head) {
      
    // Initialize count of '0', '1' and '2' as 0
    int cnt[3] = { 0, 0, 0 };
    Node* ptr = head;

    // Traverse and count total number of '0', '1' and '2'
    // cnt[0] will store total number of '0's
    // cnt[1] will store total number of '1's
    // cnt[2] will store total number of '2's
    while (ptr != NULL) {
        cnt[ptr->data] += 1;
        ptr = ptr->next;
    }

    int idx = 0;
    ptr = head;
    
      // Fill first cnt[0] nodes with value 0
      // Fill next cnt[1] nodes with value 1
       // Fill remaining cnt[2] nodes with value 2
    while (ptr != nullptr) {
          
        if (cnt[idx] == 0)
            idx += 1;
        else {
            ptr->data = idx;
            cnt[idx] -= 1;
            ptr = ptr->next;
        }
    }
}

// This function prints the contents 
// of the linked list starting from the head
void printList(Node* node) {
    while (node != nullptr) {
        cout << " " << node->data;
        node = node->next;
    }
      cout << "\n";
}