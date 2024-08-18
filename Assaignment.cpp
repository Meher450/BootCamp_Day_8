// insert a new node at the end of a singly linked list
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

void insertAtEnd(Node* &head, int val) {
    Node* newNode = new Node(val);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Node* head = nullptr;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);

    printList(head);

    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////
//Insertion and deletion of Node
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

void insertAtBeginning(Node* &head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node* &head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAfter(Node* prevNode, int val) {
    if (prevNode == nullptr) {
        cout << "Previous node cannot be nullptr." << endl;
        return;
    }
    Node* newNode = new Node(val);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void insertBefore(Node* &head, Node* nextNode, int val) {
    if (head == nullptr || nextNode == nullptr) {
        cout << "Invalid operation." << endl;
        return;
    }
    if (head == nextNode) {
        insertAtBeginning(head, val);
        return;
    }
    Node* temp = head;
    while (temp->next != nextNode) {
        temp = temp->next;
        if (temp == nullptr) {
            cout << "Next node not found in the list." << endl;
            return;
        }
    }
    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtBeginning(Node* &head) {
    if (head == nullptr) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteAtEnd(Node* &head) {
    if (head == nullptr) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

void deleteByValue(Node* &head, int val) {
    if (head == nullptr) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }
    if (head->data == val) {
        deleteAtBeginning(head);
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != val) {
        temp = temp->next;
    }
    if (temp->next == nullptr) {
        cout << "Value " << val << " not found in the list." << endl;
        return;
    }
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

// Print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Node* head = nullptr;

    insertAtBeginning(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    insertAfter(head->next, 25);
    insertBefore(head, head->next->next->next, 15); // Insert before 30

    cout << "List after insertions: ";
    printList(head);

    deleteAtBeginning(head);
    cout << "List after deleting the first node: ";
    printList(head);

    deleteAtEnd(head);
    cout << "List after deleting the last node: ";
    printList(head);

    deleteByValue(head, 25);
    cout << "List after deleting node with value 25: ";
    printList(head);

    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////

//detecting and removing loops
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

bool detectLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true; // Loop detected
        }
    }
    return false; // No loop
}

void removeLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    // Detect loop
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            break; // Loop detected
        }
    }

    // If no loop found
    if (slow != fast) {
        return;
    }

    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    Node* loopStart = slow;
    while (fast->next != loopStart) {
        fast = fast->next;
    }

    fast->next = nullptr;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head->next->next; // Creating a loop

    if (detectLoop(head)) {
        cout << "Loop detected. Removing loop..." << endl;
        removeLoop(head);
    } else {
        cout << "No loop detected." << endl;
    }

    cout << "List after removing loop: ";
    printList(head);

    return 0;
}
