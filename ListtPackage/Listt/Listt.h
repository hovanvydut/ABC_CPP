#ifndef LISTT_H
#define LISTT_H

template <class E>
class Listt
{
public:
    Listt();
    virtual ~Listt();
    virtual int indexOf(const E) = 0;
    virtual int lastIndexOf(const E) = 0;
    virtual bool add(const E) = 0;
    virtual bool add(const int &, const E) = 0;
    virtual int getSize() = 0;
    virtual E get(const int &) = 0;
    
    virtual bool remove(const E) = 0;
    virtual bool removeAt(const int &) = 0;
    virtual bool isEmpty() = 0;
    virtual void clear() = 0;
    virtual bool contains(const E) = 0;
    virtual void show() = 0;
    virtual const E set(const int &, const E) = 0;
    virtual void sort(bool (*compare)(const E, const E)) = 0;
};

template <class E>
Listt<E>::Listt()
{

}

template <class E>
Listt<E>::~Listt()
{

}


#endif // LISTT_H