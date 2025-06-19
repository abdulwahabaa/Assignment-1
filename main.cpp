#include "AOperations.h"
#include <iostream>
#include <limits>

using namespace std;

void displayMenu() {
    cout << "\n=== Array Operations ==="
        << "\n1. Find integer"
        << "\n2. Modify integer"
        << "\n3. Add integer to end"
        << "\n4. Remove integer by index"
        << "\n5. Print array"
        << "\n6. Exit"
        << "\nChoose option (1-6): ";
}

int main() {
    int arr[MAX_SIZE];
    int size = readDataFromFile(arr);

    while (true) {
        displayMenu();
        int choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        try {
            switch (choice) {
            case 1: {                                                                   // Find integer
                int target;
                cout << "Enter number to find: ";
                cin >> target;
                int index = findInteger(arr, size, target);
                if (index != -1) cout << "Found at index: " << index << endl;
                else cout << "Invalid input please add a number!" << endl;              // communicates to user about invalid inputs
                break;
            }
            case 2: {                                                                   // Modify integer
                int index, newValue, oldValue;
                cout << "Enter index and new value: ";
                cin >> index >> newValue;
                modifyInteger(arr, size, index, newValue, oldValue);
                cout << "Modified! Old value: " << oldValue
                    << ", New value: " << arr[index] << endl;
                break;
            }
            case 3: {                                                                   // Add integer to end
                int value;
                cout << "Enter number to add: ";
                cin >> value;
                if (addInteger(arr, size, value)) {
                    cout << "Added successfully! New size: " << size << endl;
                }
                else {
                    cout << "Array is full!" << endl;
                }
                break;
            }
            case 4: {                                                                   // Removes integer by index
                int index;
                cout << "Enter index to remove: ";
                cin >> index;
                if (removeInteger(arr, size, index)) {
                    cout << "Removed successfully! New size: " << size << endl;
                }
                else {
                    cout << "Invalid index!" << endl;
                }
                break;
            }
            case 5:                                                                     // Prints the array
                printArray(arr, size);
                break;
            case 6:                                                                     // Added Exit 
                return 0;
            default:
                cout << "Invalid choice!" << endl;
            }
        }
        catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
}