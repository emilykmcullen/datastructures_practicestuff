#include "Array.h"
#include <iostream>
#include <vector>
using std::cout;
using std::cin;


int main()
{

    try
    {
        Array<int> a{10};
        for (int i = 0; i < a.Size(); i++)
        {
            a[i] = (i + 1)* 10;
        }

        cout << "Array elements: " << a << std::endl;

        Array<int> b = a;

        cout << "Array b: " << b << std::endl;
    }
    catch(const IndexOutOfBoundsException& e)
    {
        cout << "\n ERROR: Invalid array index!\n";
    }

    return 0;
}

