#ifndef SECTIONCLASS_H
#define SECTIONCLASS_H

#include <string>
#include "../Lecturer/Lecturer.h"
#include "../ListtPackage/ArrayListt/ArrayListt.h"
// #include "../Student/Student.h"

class Student;

class SectionClass {

private:
  string name;
  Listt<Student*> *listStudents;
  Lecturer* lecturer;
  // Vì có thuộc tính size của Listt rồi nên không cần thuộc tính numberOfStudents
  // int numberOfStudents;

  static SectionClass* _instance;
  SectionClass();
  SectionClass(const string&, Lecturer*);

public:
  // Singleton Pattern
  static SectionClass* getInstance();

  // SectionClass(SectionClass&);
  ~SectionClass();

  // setter, getter
  string getName() const;
  void setName(const string&);

  Lecturer* getLecturer() const;
  void setLecturer(Lecturer*);

  int getNumberOfStudents() const;

  // additional method
  bool addStudent(Student*);
  // void removeStudent(Student*);
  bool removeStudent(const string&);

  // override methods
  void show() const;

  Student* operator [] (int);
  friend ostream& operator << (ostream&, const SectionClass&);
  friend ostream& operator << (ostream&, const SectionClass*);
};

#endif