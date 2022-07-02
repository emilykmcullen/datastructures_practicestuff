#include "IntArray.cpp"
#include <iostream>
#include <vector>
using std::cout;
using std::cin;
#include <ostream>


std::ostream& operator<<(std::ostream& os, const IntArray& a)
{
    os << "[";
    for (int i=0; i < a.Size(); i++)
    {
        if (i != a.Size() - 1)
        {
            os << a[i] << ", ";
        }
        else
        {
            os << a[i];
        }
    } 
    os << "]";
    return os;
}

int main()
{

    try
    {
        IntArray a{10};
        for (int i = 0; i < a.Size(); i++)
        {
            a[i] = (i + 1)* 10;
        }

        cout << "Array elements: " << a << std::endl;

        IntArray b = a;

        cout << "Array b: " << b << std::endl;
    }
    catch(const IndexOutOfBoundsException& e)
    {
        cout << "\n ERROR: Invalid array index!\n";
    }

    return 0;
}

