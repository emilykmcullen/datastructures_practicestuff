
class IndexOutOfBoundsException{};

class IntArray
{
    private:
    int* m_ptr{nullptr};
    int m_size{0};

    bool IsValidIndex(int index) const
    {
        return (index >= 0) && (index < m_size);
    }


    public:
        IntArray() = default;

        explicit IntArray(int size)
        {
            if (size != 0)
            {
                m_ptr = new int[size]{};
                m_size = size;
            }
        }

        ~IntArray()
        {
            delete[] m_ptr;
        }

        //Copy constructor
        IntArray(const IntArray& source)
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

        //Ready only
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