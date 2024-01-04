#ifndef LIST_H
#define LIST_H

template<typename T> class List {
public:
    virtual unsigned size() noexcept = 0;
    virtual T get(unsigned index) = 0;
    virtual T set(unsigned index, T value) = 0;
    virtual void add(unsigned index, T value) = 0;
    virtual T remove(unsigned index) = 0;
};

#endif // LIST_H