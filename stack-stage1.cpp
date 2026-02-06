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
         std::string* newData = new std::string[_capacity * 2]; // Create a new array of capacity (2 * current capacity)
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