#include "Array.h"
#include <vector>
#include <cassert>
#include "Stack.h"
using std::cout;
using std::cin;
#include "SinglyLinkedList.h"


int main()
{
    // Stack<int> stack{10};
    // assert(stack.IsEmpty());
    // assert(stack.MaxSize() == 10);

    // cout << " Stack created: \n";
    // cout << stack;
    // cout << "Pushing some elements: \n";
    // cout << "Pushing 10, 20 and 64 \n";
    // stack.Push(10);
    // stack.Push(20);
    // stack.Push(64);
    // assert(stack.Size() == 3);
    // cout << stack;
    // cout << "Popping element \n";
    // stack.Pop();
    // cout << stack;


    // try
    // {
    //     Array<int> a{10};
    //     for (int i = 0; i < a.Size(); i++)
    //     {
    //         a[i] = (i + 1)* 10;
    //     }

    //     cout << "Array elements: " << a << std::endl;

    //     Array<int> b = a;

    //     cout << "Array b: " << b << std::endl;

    //     int index = a.Search(100);
    //     int index2 = a.BinarySearch(100);
    //     cout << "Element found at index " << index << std::endl;
    //     cout << "Element found at index " << index2 << std::endl;
    // }
    // catch(const IndexOutOfBoundsException& e)
    // {
    //     cout << "\n ERROR: Invalid array index!\n";
    // }

    LinkedList<int> ll{};

    ll.Add(1);
    ll.Add(8);
    ll.Add(16);
    ll.Add(3);
    ll.Print();
    // cout << ll.Search(3);
    // cout << ll.Search(17) << std::endl;
    ll.Reverse();
    std::cout << ll.m_head->m_data << std::endl;
    ll.Print();



    return 0;
}

