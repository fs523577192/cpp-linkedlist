#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>
#include "./list.hpp"

template<typename T> class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;

    LinkedListNode(T data) : data(data), next(nullptr) {};
    LinkedListNode(T data, LinkedListNode<T> *next) : data(data), next(next) {};

    ~LinkedListNode() {};
};

template<typename T> class LinkedList : public List<T>
{
private:
    LinkedListNode<T> *head;

public:
    LinkedList() : head(nullptr) {};
    ~LinkedList() {};

    unsigned size()
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
    
};

class EmptyListTest {
private:
    List<int> *pList;
public:
    EmptyListTest(List<int>* pEmptyList) : pList(pEmptyList)
    {
        std::cout << "Test group 1: the list is empty" << std::endl;
    };

    int test()
    {
        int result = this->testSize();
        if (result != 0) {
            return result;
        }
        result = this->testGet();
        if (result != 0) {
            return result;
        }
        result = this->testSet();
        if (result != 0) {
            return result;
        }
        return this->testAdd();
    }

    int testSize()
    {
        std::cout << "Test case 1: the size of an empty list is 0" << std::endl;
        if (this->pList->size() != 0) {
            std::cout << "The size of the list is expected to be 0 but is " << this->pList->size() << std::endl;
            return -1;
        }
        return 0;
    }

    int testGet()
    {
        std::cout << "Test case 2: trying to get an item from an empty list" << std::endl;
        bool thrown = false;
        try {
            this->pList->get(0);
            std::cout << "An out_of_range is expected to be thrown" << std::endl;
            return -1;
        } catch (std::out_of_range e) {
            if (e.what() != std::string("Index out of range")) {
                std::cout << "The exception message is expected to be 'Index out of range', but is" << std::endl
                        << e.what() << std::endl;
            }
            thrown = true;
        }
        if (!thrown) {
            std::cout << "An out_of_range is expected to be thrown" << std::endl;
            return -1;
        }

        thrown = false;
        try {
            this->pList->get(1);
            std::cout << "An out_of_range is expected to be thrown" << std::endl;
            return -1;
        } catch (std::out_of_range e) {
            if (e.what() != std::string("Index out of range")) {
                std::cout << "The exception message is expected to be 'Index out of range', but is" << std::endl
                        << e.what() << std::endl;
            }
            thrown = true;
        }
        if (!thrown) {
            std::cout << "An out_of_range is expected to be thrown" << std::endl;
            return -1;
        }
        return 0;
    }

    int testSet()
    {
        std::cout << "Test case 3: trying to set an item in an empty list" << std::endl;
        bool thrown = false;
        try {
            this->pList->set(0, std::rand());
            std::cout << "An out_of_range is expected to be thrown" << std::endl;
            return -1;
        } catch (std::out_of_range e) {
            if (e.what() != std::string("Index out of range")) {
                std::cout << "The exception message is expected to be 'Index out of range', but is" << std::endl
                        << e.what() << std::endl;
            }
            thrown = true;
        }
        if (!thrown) {
            std::cout << "An out_of_range is expected to be thrown" << std::endl;
            return -1;
        }

        thrown = false;
        try {
            this->pList->set(1, std::rand());
            std::cout << "An out_of_range is expected to be thrown" << std::endl;
            return -1;
        } catch (std::out_of_range e) {
            if (e.what() != std::string("Index out of range")) {
                std::cout << "The exception message is expected to be 'Index out of range', but is" << std::endl
                        << e.what() << std::endl;
            }
            thrown = true;
        }
        if (!thrown) {
            std::cout << "An out_of_range is expected to be thrown" << std::endl;
            return -1;
        }
        return 0;
    }

    int testAdd()
    {
        std::cout << "Test case 4: trying to add an item into an empty list" << std::endl;
        bool thrown = false;
        try {
            this->pList->add(1, std::rand());
            std::cout << "An out_of_range is expected to be thrown" << std::endl;
            return -1;
        } catch (std::out_of_range e) {
            if (e.what() != std::string("Index out of range")) {
                std::cout << "The exception message is expected to be 'Index out of range', but is" << std::endl
                        << e.what() << std::endl;
            }
            thrown = true;
        }
        if (!thrown) {
            std::cout << "An out_of_range is expected to be thrown" << std::endl;
            return -1;
        }

        thrown = false;
        try {
            this->pList->add(2, std::rand());
            std::cout << "An out_of_range is expected to be thrown" << std::endl;
            return -1;
        } catch (std::out_of_range e) {
            if (e.what() != std::string("Index out of range")) {
                std::cout << "The exception message is expected to be 'Index out of range', but is" << std::endl
                        << e.what() << std::endl;
            }
            thrown = true;
        }
        if (!thrown) {
            std::cout << "An out_of_range is expected to be thrown" << std::endl;
            return -1;
        }
        return 0;
    }
};

class ListWithOneItemTest {
private:
    List<int> *pList;
    int item;
public:
    ListWithOneItemTest(List<int>* pEmptyList) : pList(pEmptyList)
    {
        this->item = std::rand();
        std::cout << "Insert one item " << this->item << " into the list" << std::endl;
        this->pList->add(0, this->item);
        std::cout << "Test group 2: the list has one item" << std::endl;
    };

    int test()
    {
        int result = this->testSize();
        if (result != 0) {
            return result;
        }

        result = this->testGet();
        if (result != 0) {
            return result;
        }

        result = this->testSet();
        if (result != 0) {
            return result;
        }
        result = this->testSet();
        if (result != 0) {
            return result;
        }

        return this->testAdd();
    }

    int testSize()
    {
        std::cout << "Test case 1: the size of the list is 1" << std::endl;
        if (this->pList->size() != 1) {
            std::cout << "The size of the list is expected to be 1 but is " << this->pList->size() << std::endl;
            return -1;
        }
        return 0;
    }

    int testGet()
    {
        std::cout << "Test case 2: trying to get an item from the list" << std::endl;

        if (this->pList->get(0) != this->item) {
            std::cout << "The item is expected to be " << this->item << " but is " << this->pList->get(0) << std::endl;
            return -1;
        }

        bool thrown = false;
        try {
            this->pList->get(1);
            std::cout << "An out_of_range is expected to be thrown" << std::endl;
            return -1;
        } catch (std::out_of_range e) {
            if (e.what() != std::string("Index out of range")) {
                std::cout << "The exception message is expected to be 'Index out of range', but is" << std::endl
                        << e.what() << std::endl;
            }
            thrown = true;
        }
        if (!thrown) {
            std::cout << "An out_of_range is expected to be thrown" << std::endl;
            return -1;
        }

        thrown = false;
        try {
            this->pList->get(2);
            std::cout << "An out_of_range is expected to be thrown" << std::endl;
            return -1;
        } catch (std::out_of_range e) {
            if (e.what() != std::string("Index out of range")) {
                std::cout << "The exception message is expected to be 'Index out of range', but is" << std::endl
                        << e.what() << std::endl;
            }
            thrown = true;
        }
        if (!thrown) {
            std::cout << "An out_of_range is expected to be thrown" << std::endl;
            return -1;
        }
        return 0;
    }

    int testSet()
    {
        std::cout << "Test case 3: trying to set an item in the list" << std::endl;
        this->item = std::rand();
        this->pList->set(0, this->item);
        int result = this->testGet();
        if (result != 0) {
            return result;
        }

        bool thrown = false;
        try {
            this->pList->set(1, std::rand());
            std::cout << "An out_of_range is expected to be thrown" << std::endl;
            return -1;
        } catch (std::out_of_range e) {
            if (e.what() != std::string("Index out of range")) {
                std::cout << "The exception message is expected to be 'Index out of range', but is" << std::endl
                        << e.what() << std::endl;
            }
            thrown = true;
        }
        if (!thrown) {
            std::cout << "An out_of_range is expected to be thrown" << std::endl;
            return -1;
        }

        thrown = false;
        try {
            this->pList->set(2, std::rand());
            std::cout << "An out_of_range is expected to be thrown" << std::endl;
            return -1;
        } catch (std::out_of_range e) {
            if (e.what() != std::string("Index out of range")) {
                std::cout << "The exception message is expected to be 'Index out of range', but is" << std::endl
                        << e.what() << std::endl;
            }
            thrown = true;
        }
        if (!thrown) {
            std::cout << "An out_of_range is expected to be thrown" << std::endl;
            return -1;
        }
        return 0;
    }

    int testAdd()
    {
        std::cout << "Test case 4: trying to add an item into the list" << std::endl;
        bool thrown = false;
        try {
            this->pList->add(2, std::rand());
            std::cout << "An out_of_range is expected to be thrown" << std::endl;
            return -1;
        } catch (std::out_of_range e) {
            if (e.what() != std::string("Index out of range")) {
                std::cout << "The exception message is expected to be 'Index out of range', but is" << std::endl
                        << e.what() << std::endl;
            }
            thrown = true;
        }
        if (!thrown) {
            std::cout << "An out_of_range is expected to be thrown" << std::endl;
            return -1;
        }
        return 0;
    }
};

class ListWithTwoItemsTest {
private:
    List<int> *pList;
    int item0, item1;
public:
    ListWithTwoItemsTest(List<int>* pListWithOneItem) : pList(pListWithOneItem)
    {
        this->item0 = this->pList->get(0);
        this->item1 = std::rand();

        std::cout << "Insert one item " << this->item1 << " into the list" << std::endl;
        this->pList->add(1, this->item1);
        std::cout << "Test group 3: the list has two items" << std::endl;
    };

    int test()
    {
        int result = this->testSize();
        if (result != 0) {
            return result;
        }

        result = this->testGet();
        if (result != 0) {
            return result;
        }

        result = this->testSet();
        if (result != 0) {
            return result;
        }
        result = this->testSet();
        if (result != 0) {
            return result;
        }

        return this->testAdd();
    }

    int testSize()
    {
        std::cout << "Test case 1: the size of the list is 2" << std::endl;
        if (this->pList->size() != 2) {
            std::cout << "The size of the list is expected to be 2 but is " << this->pList->size() << std::endl;
            return -1;
        }
        return 0;
    }

    int testGet()
    {
        std::cout << "Test case 2: trying to get an item from the list" << std::endl;

        if (this->pList->get(0) != this->item0) {
            std::cout << "The first item is expected to be " << this->item0 << " but is " << this->pList->get(0) << std::endl;
            return -1;
        }
        if (this->pList->get(1) != this->item1) {
            std::cout << "The second item is expected to be " << this->item1 << " but is " << this->pList->get(1) << std::endl;
            return -1;
        }

        bool thrown = false;
        try {
            this->pList->get(2);
            std::cout << "An out_of_range is expected to be thrown" << std::endl;
            return -1;
        } catch (std::out_of_range e) {
            if (e.what() != std::string("Index out of range")) {
                std::cout << "The exception message is expected to be 'Index out of range', but is" << std::endl
                        << e.what() << std::endl;
            }
            thrown = true;
        }
        if (!thrown) {
            std::cout << "An out_of_range is expected to be thrown" << std::endl;
            return -1;
        }

        thrown = false;
        try {
            this->pList->get(3);
            std::cout << "An out_of_range is expected to be thrown" << std::endl;
            return -1;
        } catch (std::out_of_range e) {
            if (e.what() != std::string("Index out of range")) {
                std::cout << "The exception message is expected to be 'Index out of range', but is" << std::endl
                        << e.what() << std::endl;
            }
            thrown = true;
        }
        if (!thrown) {
            std::cout << "An out_of_range is expected to be thrown" << std::endl;
            return -1;
        }
        return 0;
    }

    int testSet()
    {
        std::cout << "Test case 3: trying to set an item in the list" << std::endl;
        this->item0 = std::rand();
        this->item1 = std::rand();
        this->pList->set(0, this->item0);
        this->pList->set(1, this->item1);
        int result = this->testGet();
        if (result != 0) {
            return result;
        }

        bool thrown = false;
        try {
            this->pList->set(2, std::rand());
            std::cout << "An out_of_range is expected to be thrown" << std::endl;
            return -1;
        } catch (std::out_of_range e) {
            if (e.what() != std::string("Index out of range")) {
                std::cout << "The exception message is expected to be 'Index out of range', but is" << std::endl
                        << e.what() << std::endl;
            }
            thrown = true;
        }
        if (!thrown) {
            std::cout << "An out_of_range is expected to be thrown" << std::endl;
            return -1;
        }

        thrown = false;
        try {
            this->pList->set(3, std::rand());
            std::cout << "An out_of_range is expected to be thrown" << std::endl;
            return -1;
        } catch (std::out_of_range e) {
            if (e.what() != std::string("Index out of range")) {
                std::cout << "The exception message is expected to be 'Index out of range', but is" << std::endl
                        << e.what() << std::endl;
            }
            thrown = true;
        }
        if (!thrown) {
            std::cout << "An out_of_range is expected to be thrown" << std::endl;
            return -1;
        }
        return 0;
    }

    int testAdd()
    {
        std::cout << "Test case 4: trying to add an item into the list" << std::endl;
        bool thrown = false;
        try {
            this->pList->add(3, std::rand());
            std::cout << "An out_of_range is expected to be thrown" << std::endl;
            return -1;
        } catch (std::out_of_range e) {
            if (e.what() != std::string("Index out of range")) {
                std::cout << "The exception message is expected to be 'Index out of range', but is" << std::endl
                        << e.what() << std::endl;
            }
            thrown = true;
        }
        if (!thrown) {
            std::cout << "An out_of_range is expected to be thrown" << std::endl;
            return -1;
        }
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    std::srand(std::time(nullptr));

    LinkedList<int> list = LinkedList<int>();
    int result = EmptyListTest(&list).test();
    if (result != 0) {
        return result;
    }
    result = ListWithOneItemTest(&list).test();
    if (result != 0) {
        return result;
    }
    return ListWithTwoItemsTest(&list).test();
}
