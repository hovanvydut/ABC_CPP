#ifndef NORMALSTUDENT_H
#define NORMALSTUDENT_H

#include <string>
#include "../Student/Student.h"

class NormalStudent : public Student
{

private:
  string parkingCode;

public: 
  NormalStudent();
  NormalStudent(string, int, string, bool, string, double, string);
  NormalStudent(string, int, string, bool, string, double, SectionClass*, string);
  ~NormalStudent();

  // getter, setter
  string getParkingCode() const;
  void setParkingCode(string&);

  // override method
  void show() const;
  string getClassName() const;

  friend ostream& operator << (ostream& o, const NormalStudent& student);
  friend ostream& operator << (ostream& o, const NormalStudent* student);
};

#endif