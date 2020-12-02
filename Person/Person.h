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
  Person(string = "No Name", int = 0, string = "Unknown", bool = true);
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

  virtual void show() const;
  virtual string removeSpaceAndValidateString(string str);

  friend ostream& operator << (ostream& o, const Person& person);
  friend ostream& operator << (ostream& o, const Person* person);
};

#endif