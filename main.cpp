#include "src/CrossArray.hpp"
#include <iostream>

int main() {
    // Example usage of CrossArray class
    sjtu::CrossArray arr(5);
    
    // Test InsertArrays
    int data1[] = {1, 2, 3};
    arr.InsertArrays(data1, 3);
    
    int data2[] = {4, 5};
    arr.InsertArrays(data2, 2);
    
    // Test At
    std::cout << "arr.At(0, 0): " << arr.At(0, 0) << std::endl; // Should print 1
    std::cout << "arr.At(1, 1): " << arr.At(1, 1) << std::endl; // Should print 5
    
    // Test AppendArrays
    int data3[] = {6, 7};
    arr.AppendArrays(data3, 0, 2);
    
    std::cout << "After append, arr.At(0, 4): " << arr.At(0, 4) << std::endl; // Should print 7
    
    // Test DoubleCrossLength
    arr.DoubleCrossLength();
    
    // Test WhichGreater
    sjtu::CrossArray arr2(3);
    int data4[] = {8, 9, 10, 11};
    arr2.InsertArrays(data4, 4);
    
    sjtu::CrossArray& greater = arr.WhichGreater(arr2);
    std::cout << "Greater array has first element: " << greater.At(0, 0) << std::endl;
    
    // Test IsSame
    std::cout << "arr and arr2 are same: " << arr.IsSame(arr2) << std::endl;
    
    // Test AtArray
    const int* array0 = arr.AtArray(0);
    if (array0 != nullptr) {
        std::cout << "AtArray(0)[0]: " << array0[0] << std::endl;
    }
    
    return 0;
}