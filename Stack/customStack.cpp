#include <iostream>

// We define a maximum size for our array-based stack
#define MAX_SIZE 100 

class Stack {
private:
    int top; // This is the most important variable. It tracks the index of the top element.
    int arr[MAX_SIZE]; // The array that actually holds our data

public:
    // Constructor: When we create a stack, it starts completely empty.
    Stack() {
        top = -1; // -1 means there is nothing in the array yet.
    }

    // PUSH: Add an item to the top
    bool push(int value) {
        // First, check if the stack is full (Stack Overflow)
        if (top >= (MAX_SIZE - 1)) {
            std::cout << "Stack Overflow! Cannot push " << value << "\n";
            return false;
        }
        
        // Move the 'top' pointer up one spot, then insert the value
        top++;
        arr[top] = value;
        
        std::cout << value << " pushed onto the stack.\n";
        return true;
    }

    // POP: Remove and return the top item
    int pop() {
        // First, check if the stack is already empty (Stack Underflow)
        if (top < 0) {
            std::cout << "Stack Underflow! Nothing to pop.\n";
            return 0; 
        }
        
        // Grab the value at the current top
        int poppedValue = arr[top];
        
        // Move the 'top' pointer down one spot. 
        // (Note: we don't actually have to delete the data in the array, 
        // because the next push will just overwrite it).
        top--; 
        
        return poppedValue;
    }

    // PEEK (or TOP): Look at the top item without removing it
    int peek() {
        if (top < 0) {
            std::cout << "Stack is empty.\n";
            return 0;
        }
        return arr[top];
    }

    // Check if the stack is empty
    bool isEmpty() {
        return (top < 0);
    }
};

int main() {
    std::cout << "--- Testing our Custom Stack ---\n";
    
    Stack myStack;

    // Let's push some plates onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    std::cout << "\nLet's peek at the top: " << myStack.peek() << "\n\n";

    // Now let's pop them off. Because it's LIFO, 30 comes off first!
    std::cout << myStack.pop() << " popped from stack.\n";
    std::cout << myStack.pop() << " popped from stack.\n";
    
    std::cout << "\nNew top element is: " << myStack.peek() << "\n";

    return 0;
}