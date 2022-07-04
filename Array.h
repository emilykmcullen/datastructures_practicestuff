#pragma once
#include <utility>
#include <ostream>

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
            if (size != 0)
            {
                m_ptr = new T[size]{};
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