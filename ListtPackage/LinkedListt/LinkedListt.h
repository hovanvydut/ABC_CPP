#ifndef LINKEDLISTT_H
#define LINKEDLISTT_H

#ifndef Listt_h
#define Listt_h
#include "../Listt/Listt.h"
#endif
#include "../NodeLinkedListt/NodeLinkedListt.h"

template <class E>
class LinkedListt : public Listt<E>
{
private:
  NodeLinkedListt<E> *data;
  int size;

public:
  LinkedListt();
  ~LinkedListt();
  virtual int indexOf(const E);
  virtual int lastIndexOf(const E);
  virtual bool add(const E);
  virtual bool add(const int &, const E);
  virtual bool addFirst(const E);
  virtual bool removeAt(const int &);
  virtual bool remove(const E);
  virtual int getSize();
  virtual bool isEmpty();
  virtual void clear();
  virtual bool contains(const E);
  virtual E get(const int &);
  virtual const E set(const int &, const E);
  virtual void show();
  virtual void sort(bool (*compare)(const E, const E));
  static bool compareASC(const E, const E);
  static bool compareDESC(const E, const E);
  NodeLinkedListt<E> *listIterator();

  template <typename T>
  struct isPointer
  {
    static const bool value = false;
  };

  template <typename T>
  struct isPointer<T *>
  {
    static const bool value = true;
  };
};

#endif // LINKEDLISTT_H
