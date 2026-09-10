#include <iostream>
#include <string>
using namespace std;

struct Node {
    string page;
    Node* next;

    Node(string p) {
        page = p;
        next = NULL;
    }
};

class LinkedStack {
private:
    Node* top;

public:
    LinkedStack() {
        top = NULL;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void push(string page) {
        Node* newNode = new Node(page);

        newNode->next = top;
        top = newNode;
    }

    string pop() {
        if (isEmpty()) {
            return "";
        }

        Node* temp = top;
        string page = top->page;

        top = top->next;
        delete temp;

        return page;
    }

    string peek() {
        if (isEmpty()) {
            return "";
        }

        return top->page;
    }

    ~LinkedStack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    LinkedStack backStack;

    string currentPage = "Home";

    // Visit pages
    cout << "Visiting: " << currentPage << endl;

    backStack.push(currentPage);
    currentPage = "Google";
    cout << "Visiting: " << currentPage << endl;

    backStack.push(currentPage);
    currentPage = "YouTube";
    cout << "Visiting: " << currentPage << endl;

    backStack.push(currentPage);
    currentPage = "Wikipedia";
    cout << "Visiting: " << currentPage << endl;

    // Back button
    cout << "\nBack button pressed.\n";

    currentPage = backStack.pop();
    cout << "Going back to: " << currentPage << endl;

    cout << "\nBack button pressed.\n";

    currentPage = backStack.pop();
    cout << "Going back to: " << currentPage << endl;

    return 0;
} 