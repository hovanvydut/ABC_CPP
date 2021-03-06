#include "ArrayListt.h"

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
// E nen da nang hoa toan tu ==
int ArrayListt<E>::indexOf(const E elm)
{
    int idx = -1;
    for (int i = 0; i < this->size; i++)
    {
        if (this->get(i) == elm)
        {
            idx = i;
            break;
        }
    }
    return idx;
}

template <class E>
int ArrayListt<E>::lastIndexOf(const E elm)
{
    int idx = -1;
    for (int i = 0; i < this->size; i++)
    {
        if (this->get(i) == elm)
        {
            idx = i;
        }
    }
    return idx;
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
bool ArrayListt<E>::add(const int &idx, const E elm)
{
    // them vao cuoi danh sach
    if (idx == this->size)
    {
        this->add(elm);
        return true;
    }

    if (idx < 0 || idx > (this->size - 1))
    {
        return false;
    }

    E *tmp1 = new E[idx];
    for (int i = 0; i < idx; i++)
    {
        *(tmp1 + i) = *(this->data + i);
    }

    E *tmp2 = new E[this->size - idx];
    for (int i = 0; i < (this->size - idx); i++)
    {
        *(tmp2 + i) = *(this->data + (i + idx));
    }

    delete[] this->data;
    this->size++;

    this->data = new E[this->size];
    for (int i = 0; i < idx; i++)
    {
        *(this->data + i) = *(tmp1 + i);
    }
    *(this->data + idx) = elm;
    for (int i = idx + 1; i < this->size; i++)
    {
        *(this->data + i) = *(tmp2 + i - (idx + 1));
    }

    delete[] tmp1;
    delete[] tmp2;
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

template <class E>
bool ArrayListt<E>::removeAt(const int &idx)
{
    if (this->size <= 0)
    {
        return false;
    }
    if (idx < 0 || idx > this->size - 1)
    {
        return false;
    }

    E *tmp1 = new E[idx];
    E *tmp2 = new E[this->size - idx - 1];
    for (int i = 0; i < idx; i++)
    {
        *(tmp1 + i) = *(this->data + i);
    }
    for (int i = 0; i < this->size - idx - 1; i++)
    {
        *(tmp2 + i) = *(this->data + i + idx + 1);
    }

    delete[] this->data;
    this->size--;

    this->data = new E[this->size];
    for (int i = 0; i < idx; i++)
    {
        *(this->data + i) = *(tmp1 + i);
    }
    for (int i = idx; i < this->size; i++)
    {
        *(this->data + i) = *(tmp2 + i - idx);
    }

    delete[] tmp1;
    delete[] tmp2;

    return true;
}

template <class E>
bool ArrayListt<E>::remove(const E elm)
{
    int idx = this->indexOf(elm);
    if (idx == -1)
    {
        return false;
    }
    return this->removeAt(idx);
}

template <class E>
bool ArrayListt<E>::isEmpty()
{
    return this->size <= 0;
}

template <class E>
void ArrayListt<E>::clear()
{
    delete[] this->data;
    this->size = 0;
}

template <class E>
bool ArrayListt<E>::contains(const E elm)
{
    const int idx = this->indexOf(elm);
    return idx > -1;
}

/* template<class E>
bool ArrayListt<E>::equals(Listt<E>* o) {
  if (this->size != o->size) {
    return false;
  }

  for (int i = 0; i < this->size; i++) {
    if (this->get(i) != o->get(i)) {
      return false;
    }
  }

  return true;
} */

template <class E>
const E ArrayListt<E>::set(const int &idx, const E elm)
{
    if (idx < 0 || idx > this->size - 1)
    {
        throw "idx is invalid";
    }
    const E before = this->get(idx);
    *(this->data + idx) = elm;
    return before;
}

template <class E>
void ArrayListt<E>::sort(bool (*compare)(const E, const E))
{
    for (int i = 0; i < this->size - 1; i++)
    {
        for (int j = i + 1; j < this->size; j++)
        {
            if (compare(this->get(i), this->get(j)))
            {
                E tmp = this->get(i);
                this->set(i, this->get(j));
                this->set(j, tmp);
            }
        }
    }
}

template <class E>
bool ArrayListt<E>::compareASC(const E a, const E b)
{
    if (isPointer<E>::value)
    {
      return *a > *b;
    }
    return a > b;
}

template <class E>
bool ArrayListt<E>::compareDESC(const E a, const E b)
{
    if (isPointer<E>::value)
    {
      return *b > *a;
    }
    return b > a;
}

template <class E>
void ArrayListt<E>::show()
{
    for (int i = 0; i < this->size; i++)
    {
        std::cout << this->get(i) << " ";
    }
    std::cout << std::endl;
}

template <class T>
std::ostream &operator<<(std::ostream &o, ArrayListt<T> &ArrayListt)
{
    for (int i = 0; i < ArrayListt.size; i++)
    {
        o << *(ArrayListt.data + i) << " ";
    }
    o << std::endl;
    return o;
}

template <class T>
std::ostream &operator<<(std::ostream &o, ArrayListt<T> *ArrayListt)
{
    for (int i = 0; i < ArrayListt->size; i++)
    {
        o << *(ArrayListt->data + i) << " ";
    }
    o << std::endl;
    return o;
}
