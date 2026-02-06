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
            _elements = 0;
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
    std::string _data[4];
    int _elements;
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
