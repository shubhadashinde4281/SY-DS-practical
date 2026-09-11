#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class ArrayStack {
private:
    string pages[MAX];
    int top;

public:
    ArrayStack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(string page) {
        if (isFull()) {
            cout << "Stack Overflow!\n";
            return;
        }

        pages[++top] = page;
    }

    string pop() {
        if (isEmpty()) {
            return "Stack Underflow";
        }

        return pages[top--];
    }

    string peek() {
        if (isEmpty()) {
            return "";
        }

        return pages[top];
    }
};

int main() {
    ArrayStack backStack;

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

    if (!currentPage.empty()) {
        currentPage = backStack.peek();
        cout << "Current page: " << currentPage << endl;
    }

    cout << "\nBack button pressed.\n";

    currentPage = backStack.pop();

    if (!currentPage.empty()) {
        cout << "Current page: " << currentPage << endl;
    }

    return 0;
}
