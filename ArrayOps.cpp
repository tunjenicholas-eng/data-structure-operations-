#include <iostream>
using namespace std;

// 1. Traversal
void traverse(int arr[], int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[10] = {10, 20, 30, 40, 50}; 
    int size = 5;
    
    traverse(arr, size);
    
    // 2. Insertion (Insert 25 at index 2)
    int insertIndex = 2, newValue = 25;
    for (int i = size; i > insertIndex; i--) {
        arr[i] = arr[i - 1];
    }
    arr[insertIndex] = newValue;
    size++;
    cout << "After Insertion: "; 
    traverse(arr, size);
    
    // 3. Deletion (Delete element at index 3)
    int deleteIndex = 3;
    for (int i = deleteIndex; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    cout << "After Deletion: "; 
    traverse(arr, size);
    
    // 4. Search (Linear search for 40)
    int target = 40;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            cout << "Element " << target << " found at index " << i << endl;
            break;
        }
    }

    // 5. Update (Change value at index 1 to 99)
    arr[1] = 99;
    cout << "After Update: "; 
    traverse(arr, size);

    return 0;
}