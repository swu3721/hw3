#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};

//Implementing the functions
template <typename T>
Stack<T>::Stack()
{
//Do i need smth here
}

template <typename T>
Stack<T>::~Stack()
{

}

template <typename T>
bool Stack<T>::empty() const {
    return std::vector<T>::empty();
}

template <typename T>
size_t Stack<T>::size() const{
    return std::vector<T>::size();
}

//Treat the back of the vector as the top
template <typename T>
void Stack<T>::push(const T& item) {
    this->push_back(item);
}

//Treat the back of the vector as the top
template <typename T>
void Stack<T>::pop() {
    if (empty()) {
        throw std::underflow_error("Empty Stack");
    } else {
        this->pop_back();
    }
}

//Treat the back of the vector as the top
template <typename T>
const T& Stack<T>::top() const {
    if (empty()) {
        throw std::underflow_error("Empty Stack");
    } else {
        return this->back();
    }

}

#endif