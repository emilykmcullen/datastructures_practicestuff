#pragma once
#include <ostream>
#include "Array.h"

template <typename T>
class Stack {
friend std::ostream& operator<<(std::ostream& os, const Stack<T>& stack)
{
    if (stack.IsEmpty())
    {
        os << "** Empty Stack ** \n\n";
        return os; 
    }

    os << "Stack: \n"
    for (int i = stack.m_top; i >= 0; i--)
    {
        os << "    " << stack.m_array[i] << "\n";
    }
    os << '\n';
    return os;
}

    private:
        Array<T> m_array; //stack elements are stored in this array
        int m_top; //index of the top element (-1 for empty stack)

    public:
        //Empty stack
        explicit Stack(int maxStackSize) : m_array{maxStackSize}, m_top{-1}
        {

        }

        void Push(const T& element)
        {
            //Push element on top of the stack
            m_top++;
            m_array[m_top] = element;
        }

        T Pop()
        {
            T topElement = m_array[m_top];
            m_top--;
            return topElement;
        }

        const T& Top() const 
        {
            return m_array[m_top];
        }

        int Size() const 
        {
            return (m_top +1);
        }

        bool IsEmpty() const 
        {
            return Size() == 0;
        }

        int MaxSize() const
        {
            return m_array.Size();
        }

        //Works for simple stacks containing ints floats etc
        //For more complex types would need more here
        void Clear()
        {
            m_top = -1;
        }

};