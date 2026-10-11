#pragma once

namespace sjtu {
    class CrossArray{
    private:
        int** arrays;  // 2D array of pointers to int arrays
        int* sizes;    // Array to store the size of each array
        int capacity;  // Maximum number of arrays
        int count;     // Current number of arrays

    public:
        explicit CrossArray(int lines) {
            capacity = lines;
            count = 0;
            arrays = new int*[capacity];
            sizes = new int[capacity];
            
            // Initialize all arrays to nullptr and sizes to 0
            for (int i = 0; i < capacity; i++) {
                arrays[i] = nullptr;
                sizes[i] = 0;
            }
        }

        CrossArray(const CrossArray & o) {
            // Copy basic properties
            capacity = o.capacity;
            count = o.count;
            
            // Allocate memory for arrays and sizes
            arrays = new int*[capacity];
            sizes = new int[capacity];
            
            // Deep copy each array
            for (int i = 0; i < count; i++) {
                if (o.arrays[i] != nullptr) {
                    sizes[i] = o.sizes[i];
                    arrays[i] = new int[sizes[i]];
                    for (int j = 0; j < sizes[i]; j++) {
                        arrays[i][j] = o.arrays[i][j];
                    }
                } else {
                    arrays[i] = nullptr;
                    sizes[i] = 0;
                }
            }
            
            // Initialize remaining arrays to nullptr
            for (int i = count; i < capacity; i++) {
                arrays[i] = nullptr;
                sizes[i] = 0;
            }
        }

        CrossArray & WhichGreater(CrossArray & o) {
            int this_total = 0;
            int o_total = 0;
            
            // Calculate total elements in this object
            for (int i = 0; i < count; i++) {
                this_total += sizes[i];
            }
            
            // Calculate total elements in o
            for (int i = 0; i < o.count; i++) {
                o_total += o.sizes[i];
            }
            
            // Return the one with more elements, or this if equal
            if (this_total >= o_total) {
                return *this;
            } else {
                return o;
            }
        }

        bool IsSame(const CrossArray & o) {
            // Check if both objects point to the same memory location
            return this == &o;
        }

        bool InsertArrays(const int * Input, int size) {
            // Check if we have reached capacity
            if (count >= capacity) {
                return false;
            }
            
            // Allocate memory for the new array
            arrays[count] = new int[size];
            sizes[count] = size;
            
            // Copy elements from Input to the new array
            for (int i = 0; i < size; i++) {
                arrays[count][i] = Input[i];
            }
            
            // Increment count
            count++;
            
            return true;
        }

        void AppendArrays(const int * Input, int Line, int size) {
            // Calculate new size
            int new_size = sizes[Line] + size;
            
            // Allocate new array with increased size
            int* new_array = new int[new_size];
            
            // Copy existing elements
            for (int i = 0; i < sizes[Line]; i++) {
                new_array[i] = arrays[Line][i];
            }
            
            // Append new elements
            for (int i = 0; i < size; i++) {
                new_array[sizes[Line] + i] = Input[i];
            }
            
            // Delete old array and update pointer
            delete[] arrays[Line];
            arrays[Line] = new_array;
            
            // Update size
            sizes[Line] = new_size;
        }

        void DoubleCrossLength() {
            // Double the capacity
            int new_capacity = capacity * 2;
            
            // Allocate new arrays for pointers and sizes
            int** new_arrays = new int*[new_capacity];
            int* new_sizes = new int[new_capacity];
            
            // Copy existing data
            for (int i = 0; i < capacity; i++) {
                new_arrays[i] = arrays[i];
                new_sizes[i] = sizes[i];
            }
            
            // Initialize new slots to nullptr
            for (int i = capacity; i < new_capacity; i++) {
                new_arrays[i] = nullptr;
                new_sizes[i] = 0;
            }
            
            // Update members
            delete[] arrays;
            delete[] sizes;
            arrays = new_arrays;
            sizes = new_sizes;
            capacity = new_capacity;
        }

        const int * AtArray(int i) {
            // Return the pointer to the i-th array
            return arrays[i];
        }

        int & At(int i, int j) {
            // Return reference to the j-th element of the i-th array
            return arrays[i][j];
        }

        ~CrossArray() {
            // Delete all allocated arrays
            for (int i = 0; i < count; i++) {
                if (arrays[i] != nullptr) {
                    delete[] arrays[i];
                }
            }
            
            // Delete the arrays and sizes pointers
            delete[] arrays;
            delete[] sizes;
        }
    };
}