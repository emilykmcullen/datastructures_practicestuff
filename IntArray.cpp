
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

        int Size() const { return m_size; }

};