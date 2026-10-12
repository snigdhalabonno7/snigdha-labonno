#ifndef MY_LinkedListQueue
#define MY_LinkedListQueue

#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T val)
    {
        data = val;
        next = NULL;
    }
};

template <typename T>
class List
{
    Node<T> *m_head;
    Node<T> *m_tail;

public:
    List()
    {
        m_head = NULL;
        m_tail = NULL;
    }

    void push_front(T val)
    {
        Node<T> *node = new Node<T>(val);
        if (m_head == NULL)
        {
            m_head = node;
            m_tail = node;
            return;
        }
        else
        {
            node->next = m_head;
            m_head = node;
        }
    }

    T front()
    {
        if (m_head == NULL)
        {
            cout << "Empty Queue!" << endl;
        }
        else
        {
            return m_head->data;
        }
    }

    int size()
    {
        Node<T> *current = m_head;
        int count = 0;
        while (current != NULL)
        {
            count++;
            current = current->next;
        }
        return count;
    }

    void pop_front()
    {
        if (m_head == NULL)
        {
            cout << "Link list is empty!" << endl;
            return;
        }

        Node<T> *current = m_head;
        m_head = current->next;
        current->next = NULL;
        delete current;
        if (m_head == NULL)
            m_tail = NULL;
    }

    void push_back(T val)
    {
        Node<T> *node = new Node<T>(val);
        if (m_head == NULL)
        {
            m_head = m_tail = node;
        }
        else
        {
            m_tail->next = node;
            m_tail = node;
        }
    }

    void pop_back()
    {
        if (m_head == NULL)
        {
            cout << "Link list is empty!" << endl;
            return;
        }
        if (m_head == m_tail)
        {
            delete m_head;
            m_head = m_tail = NULL;
            return;
        }
        Node<T> *current = m_head;
        while (current->next != m_tail)
        {
            current = current->next;
        }
        current->next = NULL;
        delete m_tail;
        m_tail = current;
    }

    void insertInto(T val, int pos)
    {
        if (pos < 0)
        {
            cout << "Invalid Position!" << endl;
        }
        else if (pos == 0)
        {
            push_front(val);
        }
        else
        {
            Node<T> *node = new Node<T>(val);
            Node<T> *current = m_head;
            for (int i = 0; i < pos - 1; i++)
            {
                if (current == NULL)
                {
                    cout << "Invalid Postion!" << endl;
                    return;
                }
                current = current->next;
            }
            node->next = current->next;
            current->next = node;
        }
    }

    int search(T val)
    {
        Node<T> *current = m_head;
        int index = -1;
        while (current != NULL)
        {
            index++;
            if (current->data == val)
            {
                return index;
            }
            current = current->next;
        }
        return -1;
    }

    void printLL()
    {
        if (m_head == NULL)
        {
            cout << "Link list is empty" << endl;
            return;
        }
        else
        {
            Node<T> *current = m_head;
            while (current != NULL)
            {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

#endif
