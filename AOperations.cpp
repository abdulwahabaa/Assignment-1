#include "AOperations.h"
#include <fstream>
#include <stdexcept>

using namespace std;

                                                                                    // 1: Find integer and return index
int findInteger(const int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;                                                               // Returns index if found within input txt
        }
    }
    return -1;                                                                      // Returns -1 if not found within input txt
}

                                                                                    //  2: Modify value at index and return old/new values
void modifyInteger(int arr[], int size, int index, int newValue, int& oldValue) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of bounds!");
    }
    oldValue = arr[index];                                                          // Stores old value
    arr[index] = newValue;                                                          // Set new value
}

                                                                                    // 3: Add integer to end of array
bool addInteger(int arr[], int& size, int value) {
    if (size >= MAX_SIZE) {
        return false;                                                               // Return false if array is full
    }
    arr[size] = value;
    size++;
    return true;
}

                                                                                    // 4: Remove integer at index
bool removeInteger(int arr[], int& size, int index) {
    if (index < 0 || index >= size) {
        return false;                                                               // Return false if index invalid
    }
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];                                                        // Shift elements left
    }
    size--;
    return true;
}

                                                                                    // Helper function to read data
int readDataFromFile(int arr[]) {
    ifstream file("input.txt");
    if (!file) throw runtime_error("Cannot open file!");

    int size = 0;
    while (size < MAX_SIZE && file >> arr[size]) {
        size++;
    }
    return size;
}
                                                                                    // Assigns printArray
void printArray(const int arr[], int size)
{
}
