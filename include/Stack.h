#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cstdlib>

// Initial stack array size
const int MaxStackSize = 2;

// Template class for a dynamic stack
template <typename T>
class Stack {
private:
    T *_stackList;   // Dynamic array to store stack elements
    int _stackSize;  // Current allocated size of the stack
    int _top;        // Index of the top element

    // Extend the stack array when full
    void PushExtend(const T& item);

public:
    Stack(void);              // Constructor
    void Push(const T& item); // Push element onto stack
    T Pop(void);              // Pop the top element
    void ClearStack(void);    // Reset stack to empty
    T Top(void) const;        // Get the top element without popping

    bool IsStackEmpty(void) const; // Check if stack is empty
    bool IsStackFull(void) const;  // Check if stack is full
};

// -------- Implementation --------
template <typename T>
Stack<T>::Stack(void) {
    _stackList = new T[MaxStackSize]; // Allocate initial array
    _stackSize = MaxStackSize;
    _top = -1; // Stack is empty initially
}

template <typename T>
void Stack<T>::Push(const T& item) {
    if (IsStackFull()) PushExtend(item); // Extend if full
    else _stackList[++_top] = item;      // Otherwise push normally
}

template <typename T>
void Stack<T>::PushExtend(const T& item) {
    // Allocate new array with double size
    T *newStackList = new T[_stackSize * 2];

    // Copy existing elements
    for (int i = 0; i <= _top; ++i)
        newStackList[i] = _stackList[i];

    delete[] _stackList;  // Free old array
    _stackList = newStackList;
    _stackSize *= 2;      // Update stack size
    _stackList[++_top] = item; // Push new element
}

template <typename T>
T Stack<T>::Pop(void) {
    if (IsStackEmpty()) {
        std::cerr << "Stack underflow error." << std::endl;
        exit(EXIT_FAILURE);
    }
    return _stackList[_top--]; // Return top element and decrement
}

template <typename T>
void Stack<T>::ClearStack(void) { _top = -1; }

template <typename T>
T Stack<T>::Top(void) const {
    if (IsStackEmpty()) {
        std::cerr << "Stack is empty." << std::endl;
        exit(EXIT_FAILURE);
    }
    return _stackList[_top]; // Return top without popping
}

template <typename T>
bool Stack<T>::IsStackEmpty(void) const { return _top == -1; }

template <typename T>
bool Stack<T>::IsStackFull(void) const { return _top == _stackSize - 1; }

#endif
