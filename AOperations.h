#ifndef ARRAY_OPERATIONS_H
#define ARRAY_OPERATIONS_H

const int MAX_SIZE = 100;

                                                                            // Function declarations below
int findInteger(const int arr[], int size, int target);                     //Searches for requested number in array, returns index if number is found
void modifyInteger(int arr[], int size, int index, int newValue,  
    int& oldValue);                                                         //Modifies value and brings back old and new values
bool addInteger(int arr[], int& size, int value);                           //Adds a new value to the array
bool removeInteger(int arr[], int& size, int index);                        //Removes integer at index user requests

                                                                            // Helper functions which allows reading and printing of file into array
int readDataFromFile(int arr[]);
void printArray(const int arr[], int size);                                 //Prints array 

#endif