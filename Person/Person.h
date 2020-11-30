#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

class Person
{

protected:
  string ten;
  int tuoi;
  string dia_chi;
  bool gioi_tinh; // true: name, false: nu

public:
  Person();
  Person(string, int, string, bool);
  Person(const Person &);
  virtual ~Person();

  // getter, setter
  virtual string getTen() const;
  virtual void setTen(const string &);

  virtual int getTuoi() const;
  virtual void setTuoi(const int &);

  virtual string getDiaChi() const;
  virtual void setDiaChi(const string &);

  virtual bool getGioiTinh() const;
  virtual void setGioiTinh(const bool &);

  virtual void show();
  virtual string removeSpaceAndValidateString(string str);
};

#endif