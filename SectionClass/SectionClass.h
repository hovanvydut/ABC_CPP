#ifndef SECTIONCLASS_H
#define SECTIONCLASS_H

#include <string>
#include "../Lecturer/Lecturer.h"
// #include "../Student/Student.h"

class Student;
class SectionClass {

private:
  string name;
  Student** listStudents;
  Lecturer lecturer;
  int numberOfStudents;

public:
  SectionClass();
  SectionClass(const string&, const Lecturer&);
  SectionClass(SectionClass&);
  ~SectionClass();

  // setter, getter
  string getName();
  void setName(const string&);
  Lecturer getLecturer();
  void setLecturer(const Lecturer&);
  int getNumberOfStudents();

  // additional method
  void addStudent(Student*);
  void show();
private:  
  void setNumberOfStudents(const int &);
};

#endif