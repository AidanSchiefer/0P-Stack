/*
 * stack-stage3.h
 *
 * Implements a simple stack class using dynamic arrays.
 * This may be implemented in 3 stages:
 *   Stage 1: non-template stack class storing strings,
 *            unsafe copies/assignments
 *   Stage 2: template stack class, unsafe copies/assignments
 *   Stage 3: template stack class, safe copies/assignments
 *
 * Note: no underflow detection is performed.  Performing pop() or top()
 * on an empty stack results in undefined behavior (possibly crashing your
 * program)!
 *
 * Author: Aidan Schiefer
 */

#ifndef _STACK_H
#define _STACK_H

// To start stage 2, you probably want to copy all of your code from
// stack-stage1.h and stack-stage1.cpp in place of this comment.

/***
 * DO NOT put unscoped 'using namespace std;' in header files!
 * Instead use the std:: prefix where required in class definitions, as
 * demonstrated in the stack starter code for stage1.
 */
template <typename T>
 class stack {
  public:
    T top(); // non-inline, implemented in stack-stage1.cpp

    // inline definitions, doing nothing at the moment
    void push(const T &);
    void pop();
    size_t size();
    bool is_empty();

    stack(){ 
      // Set the total elements to zero
      _elements = 0;
      // Initialize initial dynamic array size to 1
      _data = new T[1];
      // Set the total capacity to the capacity of the current dynamic array (1)
      _capacity = 1;
    }

    ~stack();
    stack(const stack&);
    stack& operator=(const stack&);

  private:
	T* _data;
    int _elements;
    int _capacity;
};

// Destructor
template <typename T> 
stack<T>::~stack(){
    // Delete dynamically allocated memory
    delete[] _data;
}

// Copy constructor
template <typename T>
stack<T>::stack(const stack& other){
    // Copy variables from the other stack object
    _elements = other._elements;
    _capacity = other._capacity;
    _data = new T[_capacity];
    // Iterate through and copy array elements into _data
    for (int i = 0; i < _elements; i++){
        _data[i] = other._data[i];
    }
}

// Assignment operator
template <typename T>
stack<T>& stack<T>::operator=(const stack& other){
    // If current object doesn't equal the other object, do the assignment
    if (this != &other){
        // Deallocate current data
        delete[] _data;

        // Copy variables from the other stack object
        _elements = other._elements;
        _capacity = other._capacity;
        _data = new T[_capacity];
        // Iterate through and copy array elements into _data
        for (int i = 0; i < _elements; i++){
            _data[i] = other._data[i];
        }
    }
    // Otherwise, return this (Happens regardless. Skips to this if copying the same object)
    return *this;
}

template <typename T>
T stack<T>::top() {
    // Return the top element in the stack
    /*
    if (_elements == 0){
        return "";
    }
    else{
        return _data[_elements-1];
    }
    */
    return _data[_elements-1];
}

template <typename T>
void stack<T>::push(const T & newValue){
    // Old push implementation
    // Loop through the array (stack)
    /*
    size_t size = sizeof(_data) / sizeof(_data[0]);
    for (int i = 0; i < size; i++){
    // If the array (stack) gets to the next empty index, add the new value, then return
        if (_data[i].empty()){
             _data[i] = newValue; // Put new value into the array
            _elements += 1; // Increase elements by 1
             return; // Return from the function
            }
                
        }   
        */
    // Dynamic push implementation
    if (_elements == _capacity){
        T* newData = new T[_capacity * 2]; // Create a new array of capacity (2 * current capacity)
        // Copy contents of old array into the new array
        for (int i = 0; i < _capacity; i++){
            newData[i] = _data[i];
        }
        // Deallocate the old array
        delete[] _data;
        // Replace the old array pointer with new array pointer
        _data = newData;
        // Update array capacity variable
        _capacity = _capacity * 2;
    }
    // Put s in the next available location in the array
    _data[_elements] = newValue;
    // Increment current size variable
    _elements += 1;
}

template <typename T>
void stack<T>::pop(){ 
    //Remove the value at the top of the stack, decrease the number of elements by one
    if (_elements > 0){
        _elements--;
        _data[_elements] = T();
    }  
}

template <typename T>
size_t stack<T>::size(){ 
    // Return the recorded size of the stack
    return _elements; 
}

template <typename T>
bool stack<T>::is_empty(){
    // Check if the array is empty, if it is empty, return true, otherwise, return false
    if (_elements == 0){
        return true;
    }
    else{
        return false;
    }
}


#endif
