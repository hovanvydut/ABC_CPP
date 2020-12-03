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
  Student(string, double = 0, SectionClass* = nullptr);
  Student(string, int, string, bool, string, double);
  Student(string, int, string, bool, string, double, SectionClass*);
  ~Student();

  string getStudentId() const;
  void setStudentId(const string &);

  double getGPA() const;
  void setGPA(const double &);

  SectionClass getSectionClass() const;

  // NOTE: add const at the end method

  // override method
  void show() const;
  string getClassName() const;

  // không dùng hàm bạn được (do circular dependency, fix bằng forward declaration) nên dùng lớp bạn 
  friend class SectionClass;

  friend ostream& operator << (ostream& o, const Student& student);
  friend ostream& operator << (ostream& o, const Student* student);

  bool operator == (const Student&) const;
  bool operator > (const Student&) const;
  bool operator >= (const Student&) const;
  bool operator < (const Student&) const;
  bool operator <= (const Student&) const;

private:   
  // quan hệ 1-n với SectionClass
  void setSectionClass(SectionClass*);
};

#endif