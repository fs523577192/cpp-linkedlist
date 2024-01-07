#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include "./linkedlist.cpp"

int randomInt()
{
    return (std::rand() << 15) | std::rand();
}

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
        result = this->testRemove();
        if (result != 0) {
            return result;
        }
        return this->testAdd();
    }

    int testSize()
    {
        std::cout << "Test case 1: the size of an empty list is 0" << std::endl;
        if (this->pList->size() != 0) {
            std::cerr << "The size of the list is expected to be 0 but is " << this->pList->size() << std::endl;
            return -1;
        }
        return 0;
    }

    int testGet()
    {
        std::cout << "Test case 2: trying to get an item from an empty list" << std::endl;
        for (unsigned i = 0; i <= 1; i += 1) {
            bool thrown = false;
            try {
                this->pList->get(i);
                std::cerr << "An out_of_range is expected to be thrown" << std::endl;
                return -1;
            } catch (std::out_of_range e) {
                if (e.what() != std::string("Index out of range")) {
                    std::cerr << "The exception message is expected to be 'Index out of range', but is" << std::endl
                            << e.what() << std::endl;
                }
                thrown = true;
            }
            if (!thrown) {
                std::cerr << "An out_of_range is expected to be thrown" << std::endl;
                return -1;
            }
        }
        return 0;
    }

    int testSet()
    {
        std::cout << "Test case 3: trying to set an item in an empty list" << std::endl;
        for (unsigned i = 0; i <= 1; i += 1) {
            bool thrown = false;
            try {
                this->pList->set(i, randomInt());
                std::cerr << "An out_of_range is expected to be thrown" << std::endl;
                return -1;
            } catch (std::out_of_range e) {
                if (e.what() != std::string("Index out of range")) {
                    std::cerr << "The exception message is expected to be 'Index out of range', but is" << std::endl
                            << e.what() << std::endl;
                }
                thrown = true;
            }
            if (!thrown) {
                std::cerr << "An out_of_range is expected to be thrown" << std::endl;
                return -1;
            }
        }
        return 0;
    }

    int testRemove()
    {
        std::cout << "Test case 4: trying to remove an item from an empty list" << std::endl;
        for (unsigned i = 0; i <= 1; i += 1) {
            bool thrown = false;
            try {
                this->pList->set(i, randomInt());
                std::cerr << "An out_of_range is expected to be thrown" << std::endl;
                return -1;
            } catch (std::out_of_range e) {
                if (e.what() != std::string("Index out of range")) {
                    std::cerr << "The exception message is expected to be 'Index out of range', but is" << std::endl
                            << e.what() << std::endl;
                }
                thrown = true;
            }
            if (!thrown) {
                std::cerr << "An out_of_range is expected to be thrown" << std::endl;
                return -1;
            }
        }
        return 0;
    }

    int testAdd()
    {
        std::cout << "Test case 5: trying to add an item into an empty list" << std::endl;
        for (unsigned i = 1; i <= 2; i += 1) {
            bool thrown = false;
            try {
                this->pList->add(i, randomInt());
                std::cerr << "An out_of_range is expected to be thrown" << std::endl;
                return -1;
            } catch (std::out_of_range e) {
                if (e.what() != std::string("Index out of range")) {
                    std::cerr << "The exception message is expected to be 'Index out of range', but is" << std::endl
                            << e.what() << std::endl;
                }
                thrown = true;
            }
            if (!thrown) {
                std::cerr << "An out_of_range is expected to be thrown" << std::endl;
                return -1;
            }
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
        this->item = randomInt();
        std::cout << "Insert the first item " << this->item << " into the list" << std::endl;
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

        result = this->testRemove();
        if (result != 0) {
            return result;
        }

        return this->testAdd();
    }

    int testSize()
    {
        std::cout << "Test case 1: the size of the list is 1" << std::endl;
        if (this->pList->size() != 1) {
            std::cerr << "The size of the list is expected to be 1 but is " << this->pList->size() << std::endl;
            return -1;
        }
        return 0;
    }

    int testGet()
    {
        std::cout << "Test case 2: trying to get an item from the list" << std::endl;

        if (this->pList->get(0) != this->item) {
            std::cerr << "The item is expected to be " << this->item << " but is " << this->pList->get(0) << std::endl;
            return -1;
        }

        for (unsigned i = 1; i <= 2; i += 1) {
            bool thrown = false;
            try {
                this->pList->get(i);
                std::cerr << "An out_of_range is expected to be thrown" << std::endl;
                return -1;
            } catch (std::out_of_range e) {
                if (e.what() != std::string("Index out of range")) {
                    std::cerr << "The exception message is expected to be 'Index out of range', but is" << std::endl
                            << e.what() << std::endl;
                }
                thrown = true;
            }
            if (!thrown) {
                std::cerr << "An out_of_range is expected to be thrown" << std::endl;
                return -1;
            }
        }
        return 0;
    }

    int testSet()
    {
        std::cout << "Test case 3: trying to set an item in the list" << std::endl;
        this->item = randomInt();
        std::cout << "Set the first item to " << this->item << std::endl;
        this->pList->set(0, this->item);
        int result = this->testGet();
        if (result != 0) {
            return result;
        }

        for (unsigned i = 1; i <= 2; i += 1) {
            bool thrown = false;
            try {
                this->pList->set(i, randomInt());
                std::cerr << "An out_of_range is expected to be thrown" << std::endl;
                return -1;
            } catch (std::out_of_range e) {
                if (e.what() != std::string("Index out of range")) {
                    std::cerr << "The exception message is expected to be 'Index out of range', but is" << std::endl
                            << e.what() << std::endl;
                }
                thrown = true;
            }
            if (!thrown) {
                std::cerr << "An out_of_range is expected to be thrown" << std::endl;
                return -1;
            }
        }
        return 0;
    }

    int testRemove()
    {
        std::cout << "Test case 4: trying to remove an item from the list" << std::endl;
        for (unsigned i = 1; i <= 2; i += 1) {
            bool thrown = false;
            try {
                this->pList->set(i, randomInt());
                std::cerr << "An out_of_range is expected to be thrown" << std::endl;
                return -1;
            } catch (std::out_of_range e) {
                if (e.what() != std::string("Index out of range")) {
                    std::cerr << "The exception message is expected to be 'Index out of range', but is" << std::endl
                            << e.what() << std::endl;
                }
                thrown = true;
            }
            if (!thrown) {
                std::cerr << "An out_of_range is expected to be thrown" << std::endl;
                return -1;
            }
        }
        
        int temp = this->pList->remove(0); // remove the only item
        if (temp != this->item) {
            std::cerr << "remove(0) is expected to be " << this->item << ", but is actually "
                    << temp << std::endl;
            return -1;
        }
        if (this->pList->size() != 0) {
            std::cerr << "The size of the list is expected to be 0, but is actually "
                    << this->pList->size() << std::endl;
            return -1;
        }

        this->pList->add(0, this->item);
        if (this->pList->size() != 1) {
            std::cerr << "The size of the list is expected to be 1, but is actually "
                    << this->pList->size() << std::endl;
            return -1;
        }
        
        return 0;
    }

    int testAdd()
    {
        std::cout << "Test case 5: trying to add an item into the list" << std::endl;
        for (unsigned i = 2; i <= 3; i += 1) {
            bool thrown = false;
            try {
                this->pList->add(i, randomInt());
                std::cerr << "An out_of_range is expected to be thrown" << std::endl;
                return -1;
            } catch (std::out_of_range e) {
                if (e.what() != std::string("Index out of range")) {
                    std::cerr << "The exception message is expected to be 'Index out of range', but is" << std::endl
                            << e.what() << std::endl;
                }
                thrown = true;
            }
            if (!thrown) {
                std::cerr << "An out_of_range is expected to be thrown" << std::endl;
                return -1;
            }
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
        this->item1 = randomInt();

        std::cout << "Insert the second item " << this->item1 << " into the list" << std::endl;
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

        result = this->testRemove();
        if (result != 0) {
            return result;
        }

        return this->testAdd();
    }

    int testSize()
    {
        std::cout << "Test case 1: the size of the list is 2" << std::endl;
        if (this->pList->size() != 2) {
            std::cerr << "The size of the list is expected to be 2 but is " << this->pList->size() << std::endl;
            return -1;
        }
        return 0;
    }

    int testGet()
    {
        std::cout << "Test case 2: trying to get an item from the list" << std::endl;

        if (this->pList->get(0) != this->item0) {
            std::cerr << "The first item is expected to be " << this->item0 << " but is " << this->pList->get(0) << std::endl;
            return -1;
        }
        if (this->pList->get(1) != this->item1) {
            std::cerr << "The second item is expected to be " << this->item1 << " but is " << this->pList->get(1) << std::endl;
            return -1;
        }

        for (unsigned i = 2; i <= 3; i += 1) {
            bool thrown = false;
            try {
                this->pList->get(i);
                std::cerr << "An out_of_range is expected to be thrown" << std::endl;
                return -1;
            } catch (std::out_of_range e) {
                if (e.what() != std::string("Index out of range")) {
                    std::cerr << "The exception message is expected to be 'Index out of range', but is" << std::endl
                            << e.what() << std::endl;
                }
                thrown = true;
            }
            if (!thrown) {
                std::cerr << "An out_of_range is expected to be thrown" << std::endl;
                return -1;
            }
        }
        return 0;
    }

    int testSet()
    {
        std::cout << "Test case 3: trying to set an item in the list" << std::endl;
        this->item0 = randomInt();
        this->item1 = randomInt();
        std::cout << "Set the first item to " << this->item0 << std::endl;
        std::cout << "Set the second item to " << this->item1 << std::endl;
        this->pList->set(0, this->item0);
        this->pList->set(1, this->item1);
        int result = this->testGet();
        if (result != 0) {
            return result;
        }

        for (unsigned i = 2; i <= 3; i += 1) {
            bool thrown = false;
            try {
                this->pList->set(i, randomInt());
                std::cerr << "An out_of_range is expected to be thrown" << std::endl;
                return -1;
            } catch (std::out_of_range e) {
                if (e.what() != std::string("Index out of range")) {
                    std::cerr << "The exception message is expected to be 'Index out of range', but is" << std::endl
                            << e.what() << std::endl;
                }
                thrown = true;
            }
            if (!thrown) {
                std::cerr << "An out_of_range is expected to be thrown" << std::endl;
                return -1;
            }
        }
        return 0;
    }

    int testRemove()
    {
        std::cout << "Test case 4: trying to remove an item from the list" << std::endl;
        for (unsigned i = 2; i <= 3; i += 1) {
            bool thrown = false;
            try {
                this->pList->set(i, randomInt());
                std::cerr << "An out_of_range is expected to be thrown" << std::endl;
                return -1;
            } catch (std::out_of_range e) {
                if (e.what() != std::string("Index out of range")) {
                    std::cerr << "The exception message is expected to be 'Index out of range', but is" << std::endl
                            << e.what() << std::endl;
                }
                thrown = true;
            }
            if (!thrown) {
                std::cerr << "An out_of_range is expected to be thrown" << std::endl;
                return -1;
            }
        }
        
        int temp = this->pList->remove(0); // remove the first item
        if (temp != this->item0) {
            std::cerr << "remove(0) is expected to be " << this->item0 << ", but is actually "
                    << temp << std::endl;
            return -1;
        }
        if (this->pList->size() != 1) {
            std::cerr << "The size of the list is expected to be 1, but is actually "
                    << this->pList->size() << std::endl;
            return -1;
        }

        this->pList->add(0, this->item0);
        if (this->pList->size() != 2) {
            std::cerr << "The size of the list is expected to be 2, but is actually "
                    << this->pList->size() << std::endl;
            return -1;
        }
        
        return 0;
    }

    int testAdd()
    {
        std::cout << "Test case 5: trying to add an item into the list" << std::endl;
        for (unsigned i = 3; i <= 4; i += 1) {
            bool thrown = false;
            try {
                this->pList->add(3, randomInt());
                std::cerr << "An out_of_range is expected to be thrown" << std::endl;
                return -1;
            } catch (std::out_of_range e) {
                if (e.what() != std::string("Index out of range")) {
                    std::cerr << "The exception message is expected to be 'Index out of range', but is" << std::endl
                            << e.what() << std::endl;
                }
                thrown = true;
            }
            if (!thrown) {
                std::cerr << "An out_of_range is expected to be thrown" << std::endl;
                return -1;
            }
        }
        return 0;
    }
};

class ListWithThreeItemsTest {
private:
    List<int> *pList;
    int item0, item1, item2;
public:
    ListWithThreeItemsTest(List<int>* pListWithTwoItem) : pList(pListWithTwoItem)
    {
        this->item0 = this->pList->get(0);
        this->item2 = this->pList->get(1);
        this->item1 = randomInt();

        std::cout << "Insert one item " << this->item1 << " into the list" << std::endl;
        this->pList->add(1, this->item1);
        std::cout << "Test group 4: the list has three items" << std::endl;
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

        // will remove all 3 items
        return this->testRemove();
    }

    int testSize()
    {
        std::cout << "Test case 1: the size of the list is 3" << std::endl;
        if (this->pList->size() != 3) {
            std::cerr << "The size of the list is expected to be 3 but is " << this->pList->size() << std::endl;
            return -1;
        }
        return 0;
    }

    int testGet()
    {
        std::cout << "Test case 2: trying to get an item from the list" << std::endl;

        if (this->pList->get(0) != this->item0) {
            std::cerr << "The first item is expected to be " << this->item0 << " but is " << this->pList->get(0) << std::endl;
            return -1;
        }
        if (this->pList->get(1) != this->item1) {
            std::cerr << "The second item is expected to be " << this->item1 << " but is " << this->pList->get(1) << std::endl;
            return -1;
        }
        if (this->pList->get(2) != this->item2) {
            std::cerr << "The second item is expected to be " << this->item1 << " but is " << this->pList->get(1) << std::endl;
            return -1;
        }

        for (unsigned i = 3; i <= 4; i += 1) {
            bool thrown = false;
            try {
                this->pList->get(i);
                std::cerr << "An out_of_range is expected to be thrown" << std::endl;
                return -1;
            } catch (std::out_of_range e) {
                if (e.what() != std::string("Index out of range")) {
                    std::cerr << "The exception message is expected to be 'Index out of range', but is" << std::endl
                            << e.what() << std::endl;
                }
                thrown = true;
            }
            if (!thrown) {
                std::cerr << "An out_of_range is expected to be thrown" << std::endl;
                return -1;
            }
        }
        return 0;
    }

    int testSet()
    {
        std::cout << "Test case 3: trying to set an item in the list" << std::endl;
        this->item0 = randomInt();
        this->item1 = randomInt();
        this->item2 = randomInt();
        std::cout << "Set the first item to " << this->item0 << std::endl;
        std::cout << "Set the second item to " << this->item1 << std::endl;
        std::cout << "Set the third item to " << this->item2 << std::endl;
        this->pList->set(0, this->item0);
        this->pList->set(1, this->item1);
        this->pList->set(2, this->item2);
        int result = this->testGet();
        if (result != 0) {
            return result;
        }

        for (unsigned i = 3; i <= 4; i += 1) {
            bool thrown = false;
            try {
                this->pList->set(i, randomInt());
                std::cerr << "An out_of_range is expected to be thrown" << std::endl;
                return -1;
            } catch (std::out_of_range e) {
                if (e.what() != std::string("Index out of range")) {
                    std::cerr << "The exception message is expected to be 'Index out of range', but is" << std::endl
                            << e.what() << std::endl;
                }
                thrown = true;
            }
            if (!thrown) {
                std::cerr << "An out_of_range is expected to be thrown" << std::endl;
                return -1;
            }
        }
        return 0;
    }

    int testRemove()
    {
        std::cout << "Test case 4: trying to remove items from the list" << std::endl;
        for (unsigned i = 3; i <= 4; i += 1) {
            bool thrown = false;
            try {
                this->pList->set(i, randomInt());
                std::cerr << "An out_of_range is expected to be thrown" << std::endl;
                return -1;
            } catch (std::out_of_range e) {
                if (e.what() != std::string("Index out of range")) {
                    std::cerr << "The exception message is expected to be 'Index out of range', but is" << std::endl
                            << e.what() << std::endl;
                }
                thrown = true;
            }
            if (!thrown) {
                std::cerr << "An out_of_range is expected to be thrown" << std::endl;
                return -1;
            }
        }

        int temp = this->pList->remove(1); // remove an item in the middle
        if (temp != this->item1) {
            std::cerr << "remove(1) is expected to be " << this->item1 << ", but is actually "
                    << temp << std::endl;
            return -1;
        }
        if (this->pList->size() != 2) {
            std::cerr << "The size of the list is expected to be 2, but is actually "
                    << this->pList->size() << std::endl;
            return -1;
        }

        this->pList->add(1, this->item1);
        if (this->pList->size() != 3) {
            std::cerr << "The size of the list is expected to be 3, but is actually "
                    << this->pList->size() << std::endl;
            return -1;
        }
        
        temp = this->pList->remove(2); // remove the last item
        if (temp != this->item2) {
            std::cerr << "remove(2) is expected to be " << this->item2 << ", but is actually "
                    << temp << std::endl;
            return -1;
        }
        if (this->pList->size() != 2) {
            std::cerr << "The size of the list is expected to be 2, but is actually "
                    << this->pList->size() << std::endl;
            return -1;
        }

        this->pList->add(2, this->item2);
        if (this->pList->size() != 3) {
            std::cerr << "The size of the list is expected to be 3, but is actually "
                    << this->pList->size() << std::endl;
            return -1;
        }
        return 0;
    }
};

int testRandomAdd(List<int> *pEmptyList) {
    const int size = std::rand();
    std::cout << "Test a LinkedList with size " << size << std::endl;

    std::ofstream outfile;
    outfile.open("test.log", std::ios::out | std::ios::app );

    List<int> *pList = pEmptyList;
    try {
        for (unsigned i = 1; i <= size; i++) {
            unsigned index = std::rand() % i;
            int value = randomInt();
            outfile << i << ": add(" << index << ", " << value << ")" << std::endl;

            pList->add(index, value);
            if (pList->size() != i) {
                std::cerr << "The size of the list is expected to be " << i << " but is "
                        << pList->size() << std::endl;
                outfile.close();
                return -1;
            }
            int temp = pList->remove(index);
            if (temp != value) {
                std::cerr << "The removed item is expected to be " << value << " but is "
                        << temp << std::endl;
                outfile.close();
                return -1;
            }

            pList->add(index, value);
            if (pList->get(index) != value) {
                std::cerr << "The item at index " << i << " is expected to be " << value << " but is "
                        << pList->get(index) << std::endl;
                outfile.close();
                return -1;
            }
        }
    } catch (std::out_of_range e) {
        std::cerr << e.what() << std::endl;
        outfile.close();
        return -1;
    }
    outfile.close();
    return 0;
}

int main(int argc, char const *argv[])
{
    std::srand(std::time(nullptr));

    LinkedList<int> list1 = LinkedList<int>();
    int result = EmptyListTest(&list1).test();
    if (result != 0) {
        return result;
    }
    std::cout << std::endl;
    result = ListWithOneItemTest(&list1).test();
    if (result != 0) {
        return result;
    }
    std::cout << std::endl;
    result = ListWithTwoItemsTest(&list1).test();
    if (result != 0) {
        return result;
    }
    std::cout << std::endl;
    result = ListWithThreeItemsTest(&list1).test();
    if (result != 0) {
        return result;
    }
    std::cout << std::endl;

    LinkedList<int> list2 = LinkedList<int>();
    return testRandomAdd(&list2);
}
