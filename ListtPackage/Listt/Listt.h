#ifndef LISTT_H
#define LISTT_H

template <class E>
class Listt
{
public:
    Listt();
    virtual ~Listt();
    virtual bool add(const E) = 0;
    virtual int getSize() = 0;
    virtual E get(const int &) = 0;
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