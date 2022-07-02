#include "IntArray.cpp"
#include <iostream>
#include <vector>
using std::cout;
using std::cin;

int main()
{

    try
    {
        IntArray a{10};
        for (int i = 0; i < a.Size(); i++)
        {
            a[i] = (i + 1)* 10;
        }

        cout << "Array elements: ";
        for (int i = 0; i < a.Size(); i++)
        {
            cout << a[i] << ' ';
        }
        cout << '\n';

        cout << "Array size is: " << a.Size() << "\n";
        cout << "Please enter an array index: ";
        int index{};
        cin >> index;
        cout << "The element at index " << index << " is " << a[index] << '\n';
    }
    catch(const IndexOutOfBoundsException& e)
    {
        cout << "\n ERROR: Invalid array index!\n";
    }

    return 0;
}
