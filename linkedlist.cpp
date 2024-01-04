#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "./list.hpp"

template<typename T> class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;

    LinkedListNode(T data) : data(data), next(nullptr) {};
    LinkedListNode(T data, LinkedListNode<T> *next) : data(data), next(next) {};

    ~LinkedListNode() noexcept {};
};

template<typename T> class LinkedList : public List<T>
{
private:
    LinkedListNode<T> *head;

public:
    LinkedList() : head(nullptr) {};
    ~LinkedList() noexcept {
        while (this->head != nullptr) {
            LinkedListNode<T> *current = head;
            head = head->next;
            delete current;
        }
    };

    unsigned size() noexcept
    {
        unsigned int count = 0;
        LinkedListNode<T> *current = head;
        while (current!= nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    T get(unsigned index) 
    {
        LinkedListNode<T> *current = head;
        for (unsigned i = 0; i < index && current!= nullptr; i++) {
            current = current->next;
        }
        if (current == nullptr) {
            throw std::out_of_range("Index out of range");
        }
        return current->data;
    }

    T set(unsigned index, T value) 
    {
        LinkedListNode<T> *current = head;
        for (unsigned i = 0; i < index && current!= nullptr; i++) {
            current = current->next;
        }
        if (current == nullptr) {
            throw std::out_of_range("Index out of range");
        }
        T previousVal = current->data;
        current->data = value;
        return previousVal;
    }

    void add(unsigned index, T value) 
    {
        LinkedListNode<T> **pCurrent = &(this->head);
        for (unsigned i = 0; i < index; i++) {
            if ((*pCurrent) == nullptr) {
                throw std::out_of_range("Index out of range");
            }
            pCurrent = &(
                (*pCurrent)->next
            );
        }
        *pCurrent = new LinkedListNode<T>(value, *pCurrent);
    }
    
    T remove(unsigned index) 
    {
        LinkedListNode<T> **pCurrent = &(this->head);
        for (unsigned i = 0; i < index; i++) {
            if ((*pCurrent) == nullptr) {
                throw std::out_of_range("Index out of range");
            }
            pCurrent = &(
                (*pCurrent)->next
            );
        }

        LinkedListNode<T> *current = *pCurrent;
        if (current == nullptr) {
            throw std::out_of_range("Index out of range");
        }

        T value = current->data;
        *pCurrent = current->next;
        delete current;
        return value;
    }
};

#endif // LINKED_LIST_H
