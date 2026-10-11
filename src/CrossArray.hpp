#pragma once

namespace sjtu {
    class CrossArray{
    private:
        int** arrays;  // 2D array of pointers to int arrays
        int* sizes;    // Array to store the size of each array
        int capacity;  // Maximum number of arrays
        int count;     // Current number of arrays

    public:
        explicit CrossArray(int lines);

        CrossArray(const CrossArray & o);

        CrossArray & WhichGreater(CrossArray & o);

        bool IsSame(const CrossArray & o);

        bool InsertArrays(const int * Input, int size);

        void AppendArrays(const int * Input, int Line, int size);

        void DoubleCrossLength();

        const int * AtArray(int i);

        int & At(int i , int j);

        ~CrossArray();
    };
}