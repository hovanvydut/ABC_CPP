#ifndef ARRAYLISTT_H
#define ARRAYLISTT_H


#include <iostream>
#ifndef Listt_h
#define Listt_h
#include "../Listt/Listt.h"
#endif

template <class E>
class ArrayListt : public Listt<E>
{
private:
    E *data;
    int size;

public:
    ArrayListt();
    ~ArrayListt();
    int indexOf(const E);
    int lastIndexOf(const E);
    virtual bool add(const E);
    bool add(const int &, const E);
    virtual int getSize();
    virtual E get(const int &);
    
    virtual bool removeAt(const int &);
    virtual bool remove(const E);
    virtual bool isEmpty();
    virtual void clear();
    virtual bool contains(const E);
    // bool equals(Listt<E>* o);
    virtual const E set(const int &, const E);
    virtual void sort(bool (*compare)(const E, const E));
    static bool compareASC(const E, const E);
    static bool compareDESC(const E, const E);
    void show();
    template <class T> friend std::ostream &operator<<(std::ostream &, ArrayListt<T> &);
    template <class T> friend std::ostream &operator<<(std::ostream &, ArrayListt<T> *);
};

#endif // ARRAYLISTT_H