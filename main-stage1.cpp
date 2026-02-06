/*
 * main-stage1.cpp
 *
 * Includes the main() function for the stack project (stage 1).
 *
 * This code is included in the build target "run-stage1-main", and
 * in the convenience target "stage1".
 */

#include <iostream>

#include "stack-stage1.h"

using namespace std;

class Stack{
    public:

        Stack(){
            // Set the total elements to zero
            _elements = 0;
            // Initialize initial dynamic array size to 1
            _data = new std::string[1];
            // Set the total capacity to the capacity of the current dynamic array (1)
            _capacity = 1;
        }

        string top() {
        // Return the top element in the stack
            if (_elements == 0){
                return "";
            }
            else{
                return _data[_elements-1];
            }
        }

        void push(const std::string & newValue){
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

        void pop(){ 
            //Remove the value at the top of the stack, decrease the number of elements by one
            if (_elements > 0){
                _elements--;
                _data[_elements] = "";
            }  
        }

        size_t size(){ 
            // Return the recorded size of the stack
            return _elements; 
        }

        bool is_empty(){
            // Check if the array is empty, if it is empty, return true, otherwise, return false
            if (_elements == 0){
                return true;
            }
            else{
                return false;
            }
        }
    private:
        std::string* _data;
        int _elements;
        int _capacity;
};

int main() {
    // You can use this main() to run your own analysis or initial testing code.
    cout << "If you are seeing this, you have successfully run main!" << endl;
    Stack stk;
    stk.push("a");
    cout << "The first element in the stack is: " << stk.top() << endl;
    stk.pop();
    bool isEmpty = stk.is_empty();
    cout << "Is the stack empty? " << isEmpty << endl;
    cout << "What is the new top of the stack? " << stk.top() << endl;
    return 0;
}
