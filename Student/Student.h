#ifndef SINHVIEN_H
#define SINHVIEN_H

#include <iostream>
#include "../Person/Person.h"

class Student : public Person
{

private:
  string studentId;
  double GPA;

public:
  Student();
  Student(string, int, string, bool, string, double);
  ~Student();

  string getStudentId();
  void setStudentId(const string &);

  double getGPA();
  void setGPA(const double &);

  void show();
};

#endif