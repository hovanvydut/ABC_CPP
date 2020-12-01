#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "../Person/Person.h"
// #include "../SectionClass/SectionClass.h"

class SectionClass;
class Student : public Person
{

protected:
  string studentId;
  double GPA;
  SectionClass* sectionClass;

public:
  Student();
  Student(string, int, string, bool, string, double);
  Student(string, int, string, bool, string, double, SectionClass*);
  ~Student();

  string getStudentId() const;
  void setStudentId(const string &);

  double getGPA() const;
  void setGPA(const double &);

  SectionClass getSectionClass() const;
  void setSectionClass(SectionClass*);

  // NOTE: add const at the end method

  // override method
  void show();
};

#endif