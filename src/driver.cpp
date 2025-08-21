#include <iostream>
#include "Stack.h"

int main() {
    Stack<int> s;        // Integer stack
    Stack<double> s2;    // Double stack

    // Push integers 0-9 onto stack
    for (int i = 0; i < 10; i++) s.Push(i);
    // Pop and print integers
    for (int i = 0; i < 10; i++) std::cout << s.Pop() << std::endl;
    if (s.IsStackEmpty()) std::cout << "Stack is empty" << std::endl;

    // Push doubles 0.0, 1.1, ... onto stack
    for (int i = 0; i < 10; i++) s2.Push(i * 1.1);
    // Pop and print doubles
    for (int i = 0; i < 10; i++) std::cout << s2.Pop() << std::endl;
    if (s2.IsStackEmpty()) std::cout << "Stack is empty" << std::endl;

    return 0;
}
