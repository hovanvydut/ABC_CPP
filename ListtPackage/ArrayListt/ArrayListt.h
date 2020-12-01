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
    virtual bool add(const E);
    virtual int getSize();
    virtual E get(const int &);
};

template <class E>
ArrayListt<E>::ArrayListt()
{
    this->size = 0;
    this->data = nullptr;
}

template <class E>
ArrayListt<E>::~ArrayListt()
{
    delete[] this->data;
}

template <class E>
bool ArrayListt<E>::add(const E elm)
{
    if (this->size == 0)
    {
        this->data = new E[this->size + 1];
        *(this->data) = elm;
        this->size++;
        return true;
    }
    // E = Room*
    E *tmp = new E[this->size];
    for (int i = 0; i < this->size; i++)
    {
        *(tmp + i) = *(this->data + i);
    }

    delete[] this->data;
    this->data = new E[this->size + 1];
    for (int i = 0; i < this->size; i++)
    {
        *(this->data + i) = *(tmp + i);
    }
    *(this->data + this->size) = elm;
    this->size++;
    return true;
}

template <class E>
int ArrayListt<E>::getSize()
{
  return this->size;
}

template <class E>
E ArrayListt<E>::get(const int &idx)
{
    if (idx < 0 || idx > this->size - 1)
    {
        throw "index is invalid";
    }

    return *(this->data + idx);
}

#endif // ARRAYLISTT_H