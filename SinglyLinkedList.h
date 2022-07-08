#pragma once
#include <iostream>

template <typename T>
class LinkedList 
{
    public:

    struct Node
    {
        //Needs to contain data and pointer to next
        T m_data{};
        Node* m_next{nullptr};

        Node() = default;
        
        //Constructor with data and node to point to
        Node(T data, Node* next)
        {
            m_data = data;
            m_next = next;
        }

        
    };

    Node* m_head{nullptr};
    //int m_nodeCount{0};

    void Add(T data)
    {
        if (m_head)
        {
            Node* currentNode = m_head;
            while (currentNode->m_next)
            {
                currentNode = currentNode->m_next;
            }
            //at last node now
            currentNode->m_next = new Node(data, nullptr);

        }
        else
        {
            m_head = new Node(data, nullptr);
        }
    }

    void Print()
    {
        Node* currentNode = m_head;
        while (currentNode != nullptr)
        {
            std::cout << "Data at node is: " << currentNode->m_data << std::endl;
            currentNode = currentNode->m_next;
            
        }
    }

    template<typename T2>
    T Search(T2 data)
    {
        Node* currentNode = m_head;
        while (currentNode != nullptr)
        {
            if (currentNode->m_data == data)
            {
                return currentNode->m_data;
            }
            currentNode = currentNode->m_next;
        }
        return {};
    }

    bool Remove(T data)
    {
        if(m_head == nullptr)
        {
            return false;
        }
        //when head node contains the data 
        if(m_head->m_data == data)
        { 
            Node* temp = m_head;
            m_head = m_head->m_next;
            delete temp;
            return true;
        }

        Node* currentNode = m_head;
        while (currentNode->m_next)
        {
            if (currentNode->m_next->m_data == data)
            {
                Node* temp = currentNode->m_next;
                currentNode->m_next = temp->m_next;
                delete temp;
                return true;
            }
            currentNode = currentNode->m_next;
        }
        return false;
    }

    void Reverse()
    {
        if (m_head)
        {
            Node* temp = m_head->m_next; 
            m_head->m_next = nullptr;
            Node* temp2 = temp->m_next; 
            temp->m_next = m_head;

            while (temp2)
            {
                Node* temp3 = temp2->m_next;
                temp2->m_next = temp;
                m_head = temp2;
                temp = temp2;
                temp2 = temp3;

            }
        }
    }



    // LinkedList(const LinkedList& list) = delete;

    // LinkedList& operator=(const SinglyLinkedList& list) = delete


    //add
    //remove
    //search


};

