/*
 * stack-stage1.cpp
 *
 * Method definitions for the stack implementation (stage 1).
 *
 * Author: Aidan Schiefer
 */

#include "stack-stage1.h"

using namespace std;

string stack::top() {
    // Return the top element in the stack
    if (_elements == 0){
        return "";
    }
    else{
        return _data[_elements-1];
    }
}

void stack::push(const std::string & newValue){
    // Loop through the array (stack)
    size_t size = sizeof(_data) / sizeof(_data[0]);
    for (int i = 0; i < size; i++){
        // If the array (stack) gets to the next empty index, add the new value, then return
        if (_data[i].empty()){
            _data[i] = newValue; // Put new value into the array
            _elements += 1; // Increase elements by 1
            return; // Return from the function
        }
    }
}

void stack::pop(){ 
    //Remove the value at the top of the stack, decrease the number of elements by one
    if (_elements > 0){
        _elements--;
        _data[_elements] = "";
    }  
}

size_t stack::size(){ 
    // Return the recorded size of the stack
    return _elements; 
}

bool stack::is_empty(){
    // Check if the array is empty, if it is empty, return true, otherwise, return false
    if (_elements == 0){
        return true;
    }
    else{
        return false;
    }
}