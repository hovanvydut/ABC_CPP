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
  Lecturer* lecturer;
  int numberOfStudents;

public:
  SectionClass();
  SectionClass(const string&, Lecturer*);
  SectionClass(SectionClass&);
  ~SectionClass();

  // setter, getter
  string getName();
  void setName(const string&);

  Lecturer* getLecturer();
  void setLecturer(Lecturer*);

  int getNumberOfStudents();

  // additional method
  bool addStudent(Student*);
  // void removeStudent(Student*);
  bool removeStudent(const string&);

  // override methods
  void show();

  Person* operator [] (int);

private:  
  void setNumberOfStudents(const int &);
};

#endif