#pragma once
#include <utility>
#include <ostream>
#include <iostream>

class IndexOutOfBoundsException{};

template <typename T>
class Array
{
     /** A friend function is a function that isn't a member of a class but 
     * has access to the class's private and protected members. 
     * Friend functions aren't considered class members;*/
    friend void swap(Array& a, Array& b) noexcept
    {
        std::swap(a.m_ptr, b.m_ptr);
        std::swap(a.m_size, b.m_size);
    }

    private:
    T* m_ptr{nullptr};
    int m_size{0};

    bool IsValidIndex(int index) const
    {
        return (index >= 0) && (index < m_size);
    }


    public:
        Array() = default;

        explicit Array(int size)
        {
             std::cout << "DEFAULT CONSTRUCTOR CALLED" << std::endl;
            if (size != 0)
            {
                m_ptr = new T[size]{}; //All values will be init to 0 instead of garbage values using the brace initialization
                m_size = size;
            }
        }

        ~Array()
        {
            delete[] m_ptr;
        }

        
        /**
         * COPY CONSTRUCTOR - we can now do a DEEP COPY
         * We want to make our own copy constructor because otherwise the default compiler-generated copy constructor
         * will do a member-wise copy and the m_ptr of the new IntArray will point to the same place in memory as the old
         * IntArray. (SHALLOW COPY)
        */
        Array(const Array& source)
        {
             std::cout << "COPY CONSTRUCTOR CALLED" << std::endl;
            if (!source.IsEmpty())
            {
                m_ptr = new int[source.Size()]{};
                m_size = source.Size();

                for (int i = 0; i < source.Size(); i++)
                {
                    m_ptr[i] = source.m_ptr[i];
                }
            }
        }

        //COPY ASSIGNMENT OPERATOR
        /**
         * We pass the 'source' IntArray by value so that we invoke the copy-constructor and
         * make a copy of that array to use
         */
        Array& operator=(Array source)
        {
            //Prevent self-assignment
            if (&source != this)
            {
                //Don't forget to release the previous array block!!
                //Implement proper deep-copy from source to this
                swap(source, *this);
            }
            return *this;
        }

        /** 
         * MOVE CONSTRUCTOR
         * 
        */
       //
        Array(Array&& source)
        {

            std::cout << "MOVE CONSTRUCTOR CALLED" << std::endl;
            //Transfer ownership (steal data from source)
            m_ptr = source.m_ptr;
            m_size = source.m_size;

            //Clear source
            source.m_ptr = nullptr;
            m_size = 0;

        }

        bool IsEmpty() const
        {
            return (m_size == 0);
        }

        int& operator[](int index)
        {
            if (!IsValidIndex(index))
            {
                throw IndexOutOfBoundsException{};
            }
            return m_ptr[index];
        }

        //Read only
        int& operator[](int index) const
        {
            if (!IsValidIndex(index))
            {
                throw IndexOutOfBoundsException{};
            }
            return m_ptr[index];
        }

        int Size() const { return m_size; }

        /** LINEAR SEARCH */
        int Search(const T& element)
        {
            int count = 1;
            for (int i = 0; i < m_size; i++)
            {
                
                if (m_ptr[i] == element)
                {
                    std::cout << "Linear search took " << count << " steps" << std::endl;

                    return i;
                }
                count++;
                
            }
            return -1;
        }

        /** BINARY SEARCH - ARRAY MUST BE SORTED FIRST, TODO: implement sort*/
        int BinarySearch(const T& element)
        {
            int left = 0;
            int right = m_size - 1;

            int count = 1;

            while (left <= right)
            {
                int middle = (left + right) /2;

                if (m_ptr[middle] == element)
                {
                    std::cout << "Binary search took " << count << " steps" << std::endl;
                    return middle;
                }
                else if (m_ptr[middle] < element)
                {
                    //Search in the right half
                    left = middle + 1;
                }
                else if (m_ptr[middle] > element)
                {
                    //Search in the left half
                    right = middle - 1;
                }
                count++;
            }

            //If left becomes more than right, element not found
            return -1;
        }

};

template<typename T>
inline std::ostream& operator<<(std::ostream& os, const Array<T>& a)
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