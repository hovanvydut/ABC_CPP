#ifndef SECTIONCLASS_H
#define SECTIONCLASS_H

#include <string>
#include "../Lecturer/Lecturer.h"
#include "../ListtPackage/ArrayListt/ArrayListt.cpp"
#include "../ListtPackage/LinkedListt/LinkedListt.h"
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
  SectionClass(const string = "No Name", Lecturer*  = nullptr);

public:
  // Singleton Pattern
  static SectionClass* getInstance();
  ~SectionClass();
  // SectionClass(SectionClass&);

  // setter, getter
  string getName() const;
  void setName(const string);
  Lecturer* getLecturer() const;
  void setLecturer(Lecturer*);
  int getNumberOfStudents() const;

  // management method
  bool addStudent(Student*);
  bool removeStudent(const string);
  Student* findStudentById(const string);
  void sortGPAStudentDESC();
  void sortGPAStudentASC();
  Student* operator [] (int);
  friend ostream& operator << (ostream&, const SectionClass&);
  friend ostream& operator << (ostream&, const SectionClass*);
  // void removeStudent(Student*);

  // override method
  void show() const;
};

#endif