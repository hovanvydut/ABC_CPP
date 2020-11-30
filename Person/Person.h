#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

class Person
{

protected:
  string name;
  int age;
  string address;
  bool gender; // true: name, false: nu

public:
  Person();
  Person(string, int, string, bool);
  Person(const Person &);
  virtual ~Person();

  // getter, setter
  virtual string getName() const;
  virtual void setName(const string &);

  virtual int getAge() const;
  virtual void setAge(const int &);

  virtual string getAddress() const;
  virtual void setAddress(const string &);

  virtual bool getGender() const;
  virtual void setGender(const bool &);

  virtual void show();
  virtual string removeSpaceAndValidateString(string str);
};

#endif